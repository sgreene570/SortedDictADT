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
    printf("%s\n", (char *)getValue(dict, "testing"));
    return 0;
}
