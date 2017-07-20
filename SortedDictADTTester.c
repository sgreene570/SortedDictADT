// File: SortedDictADTTester.c
// Sorted dictionary tester program
// @auther: Stephen Greene (sgreene570)


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SortedDictADT.h"


int comparator(const void *a, const void *b){
    return strcmp((char *)a, (char *)b);
}


int main(int argc, char *argv[]){
    int (*cmp)(const void *a, const void *b) = &comparator;
    SortedDictADT *dict = createDict(cmp);
    addEntry(dict, dict->head, createEntry("testing", "123"));
    addEntry(dict, dict->head, createEntry("123", "TESTING"));
    addEntry(dict, dict->head, createEntry("loop", "adoop"));
    // Test dictionary retrieval
    printf("%s\n", (char *)getValue(dict, "loop"));
    printf("%s\n", (char *)getValue(dict, "testing"));
    printf("%s\n", (char *)getValue(dict, "123"));

    // Test cleanup function
    destroyDict(dict);
    return 0;
}
