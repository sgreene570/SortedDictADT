// File: SortedDictADT.c
// Sorted dictionary implementation with generics in C
// @author: Stephen Greene (sgreene570)


#include <stdlib.h>
#include <stdio.h>
#include "SortedDictADT.h"


SortedDictADT *createDict(int (*cmp)(const void *a, const void *b)){
    SortedDictADT *dict = calloc(1, sizeof(SortedDictADT));
    dict->cmp = cmp;
    return dict;
}


SortedDictEntry *createEntry(void *key, void *value){
    SortedDictEntry *entry = calloc(1, sizeof(SortedDictEntry));
    entry->key = key;
    entry->value = value;
    return entry;
}


void addEntry(SortedDictADT *dict, SortedDictEntry *head, SortedDictEntry *entry){
    if(!dict->head){
        dict->head = entry;
    }else{
        int cmp = dict->cmp(entry->key, head->key);
        if(cmp < 0){
            // Copy the contents of the head pointer
            SortedDictEntry *copy = createEntry(head->key, head->value);
            copy->next = head->next;
            // Overide the values of the current head pointer
            // This is to avoid changing the address of the current head
            // so anything pointing to head will not break.
            head->key = entry->key;
            head->value = entry->value;
            head->next = copy;
            // Free entry since its contents have been copied elsewhere
            // Note: deleting entry contents would break the head pointer
            // since key/value were not deep copied.
            free(entry);
        }else if(cmp > 0){
            if(!(head->next)){
                head->next = entry;
            }else{
                addEntry(dict, head->next, entry);
            }
        }
    }
}


void *getValue(SortedDictADT *dict, void *key){
    SortedDictEntry *entry = dict->head;
    // Iterate through entire linked list.
    // TODO: Implement binary searching?
    while(entry){
        if(dict->cmp(key, entry->key) == 0){
            return entry->value;
        }else{
            entry = entry->next;
        }
    }
    return NULL;
}


void *getKey(SortedDictADT *dict, void *value){
    SortedDictEntry *entry = dict->head;
    // Iterate through the linked list to find the key.
    while(entry){
        if(dict->cmp(value, entry->value) == 0){
            return entry->key;
        }else{
            entry = entry->next;
        }
    }
    return NULL;
}


// Frees all dynamic memory used by the dict.
// Assumes that SortedDictEntrys in the dict also use dynamic memory for key/value
void destroyDict(SortedDictADT *dict){
    SortedDictEntry *curr = dict->head;
    while(curr){
        // uncomment these free calls when using generics (currently testing with strings)
        //free(curr->key);
        //free(curr->value);
        SortedDictEntry *temp = curr->next;
        free(curr);
        curr = temp;
    }
    free(dict);
}
