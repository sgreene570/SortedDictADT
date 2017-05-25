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
// SortedDictEntry head : Head node of the dictionary
typedef struct SortedDictADT_s{
    int (*cmp)(const void *a, const void *b);
    SortedDictEntry *head;
}SortedDictADT;


// createDict()
// Creates and returns a SortedDictADT
// @param int (*cmp)(const void *a, const void *b) : comparator function
// @return SortedDictADT : Blank SortedDictADT instance
SortedDictADT *createDict(int (*cmp)(const void *a, const void *b));


// createEntry()
// Creates a dictionary entry struct and returns a struct pointer
// @param void *key : Key for dict entry
// @param void *value : Value for associated key
// @return SortedDictEntry : Pointer to dict entry
SortedDictEntry *createEntry(void *key, void *value);


// addEntry()
// Add a SortedDictEntry to the passed SortedDictADT
// @param SortedDictADT dict: The dict to add the entry to
// @param SortedDictEntry entry : The entry to add
void addEntry(SortedDictADT dict, SortedDictEntry entry);


#endif
