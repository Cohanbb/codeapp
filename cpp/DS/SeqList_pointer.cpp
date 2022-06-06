#include <stdio.h>
#include <malloc.h>
#define Initsize 20;

typedef struct Seqlist_pointer {
    int *data;
    int length, maxsize;
} sqlist;

