#include <stdio.h>
#include <malloc.h>

#define Initsize 20 //Initial maxsize

typedef struct Seqlist_pointer {
    int *data;
    int length, maxsize;
} sqlist;

void InitList(sqlist &L) {
    L.maxsize = Initsize;
    L.data = (int *)malloc(sizeof(int) * L.maxsize);
    L.length = 0;
    for (int i = 0; i < L.maxsize; i++)
        L.data[i] = 0;
}

bool Empty(sqlist L) {
    if (L.length == 0)
        return true;
    return false; 
}

void InsertElem(sqlist &L, int i, int e) {
    if (i <= 0 || i > L.length + 1)
        return;
    int *last = L.data;
    L.data = (int *)malloc(sizeof(int) * (L.maxsize + 1));
}

void DeleteElem(sqlist &L, int i, int &e) {

}

void LocateElem(sqlist L, int e) {

}

void PrintList(sqlist L) {

}

void DestroyList(sqlist &L) {

}
