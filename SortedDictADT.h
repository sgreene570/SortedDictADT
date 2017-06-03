// File: SortedDictADT.h
// Sorted dictionary adt header file
// @author: Stephen Greene (sgreene570)


#ifndef SORTEDDICTADT_H
#define SORTEDDICTADT_H


// Struct SortedDictEntry
// void *key : Key entry for dictionary entry
// void *value : Value associated with given key
// struct SortedDictEntry_s *next : Linked list behavior to point to next entry
typedef struct SortedDictEntry_s{
    void *key;
    void *value;
    struct SortedDictEntry_s *next;
}SortedDictEntry;


// Struct SortedDictADT
// int (*cmp)(const void *a, const void *b) : comparator function pointer
//  The comparator should be used for comparing keys
// SortedDictEntry *head : Head node of the dictionary
typedef struct SortedDictADT_s{
    int (*cmp)(const void *a, const void *b);
    SortedDictEntry *head;
}SortedDictADT;


// createDict()
// Creates and returns a SortedDictADT
// @param int (*cmp)(const void *a, const void *b) : comparator function
// @return SortedDictADT* : Blank SortedDictADT instance
SortedDictADT *createDict(int (*cmp)(const void *a, const void *b));


// createEntry()
// Creates a dictionary entry struct and returns a struct pointer
// @param void *key : Key for dict entry
// @param void *value : Value for associated key
// @return SortedDictEntry* : Pointer to dict entry
SortedDictEntry *createEntry(void *key, void *value);


// addEntry()
// Add a SortedDictEntry to the passed SortedDictADT
// Will not add entry if ley already exists (as defined by the comparator function)
// @param SortedDictADT *dict: The dict to add the entry to
// @param SortedDictEntry *head : The current working head of the dict (For recursion)
// @param SortedDictEntry *entry : The entry to add
void addEntry(SortedDictADT *dict, SortedDictEntry *head, SortedDictEntry *entry);


// getValue()
// Get a value associated with a key
// Remember, dict cannot have duplicate keys as defined by the dict's comparison function.
// @param SortedDictADT *dict : The dict to get a value from
// @param void *key : The key to look for
// @return void *value : void pointer to the value
// Returns null if key is not found in the dict.
void *getValue(SortedDictADT *dict, void *key);


// destoryDict()
// Free all dynamic memory created for SortedDictADT
// @param SortedDictADT *dict : Dict to destroy
void destroyDict(SortedDictADT *dict);


#endif
