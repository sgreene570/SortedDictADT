// File: SortedDictADT.c
// Sorted dictionary implementation with generics in C
// @author: Stephen Greene (sgreene570)


#include <stdlib.h>
#include "SortedDictADT.h"


SortedDictADT *createDict(int (*cmp)(const void *a, const void *b)){
    SortedDictADT *dict = calloc(1, sizeof(SortedDictADT));
    dict->cmp = cmp;
    return dict;
}


SortedDictEntry *createEntry(void *key, void *value){
    return NULL;
}


void addEntry(SortedDictADT dict, SortedDictEntry entry){
    return;
}
