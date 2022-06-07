#include <stdio.h>
#include <malloc.h>

#define Initsize 20

typedef struct Queue {
    int *data;
    int top, bottom, maxsize;
} sqqueue;

