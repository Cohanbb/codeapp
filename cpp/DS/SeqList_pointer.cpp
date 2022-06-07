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
        *(L.data + i) = 0;
}

bool Empty(sqlist L) {
    if (L.length == 0)
        return true;
    return false; 
}

void ExtendList(sqlist &L, int n) {
    int *p = L.data;
    L.maxsize += n;
    L.data = (int *)malloc(sizeof(int) * L.maxsize);
    for (int i = 0; i < L.length; i++)
        *(L.data + i) = *(p + i);
}

void InsertElem(sqlist &L, int i, int e) {
    if (i <= 0 || i > L.length + 1) {
        printf("Invalid Position!");
        return;
    }
    if (L.length == L.maxsize)
        ExtendList(L, 1);
    for (int j = L.length; j >= i; j--)
        *(L.data + j) = *(L.data + j - 1);
    *(L.data + i - 1) = e;
    L.length++;
}

void DeleteElem(sqlist &L, int i, int &e) {
    if (i <= 0 || i > L.length) {
        printf("Invalid Position!");
        return;
    }
    e = *(L.data + i - 1);
    for (int j = i; j < L.length; j++)
        *(L.data + j - 1) = *(L.data + j);
    *(L.data + L.length - 1) = 0;
    L.length--;
}

void LocateElem(sqlist L, int &i, int e) {
    for (int j = 0; j < L.length; j++) {
        if (*(L.data + j) == e) {
            i = j + 1;
            return;
        }
    }
    printf("Not Found!\n");
}

void PrintList(sqlist L) {
    for (int i = 0; i < L.length; i++)
        printf("%d\n", *(L.data + i));
}

void DestroyList(sqlist *L) {
    if (L == NULL)
        return;
    free(L->data);
    L->data = NULL;
    free(L);
    L = NULL;
}

int main() {
    int i, e;
    sqlist list;
    InitList(list);
    InsertElem(list, 1, 2);
    InsertElem(list, 2, 3);
    InsertElem(list, 3, 4);
    DeleteElem(list, 2, e);
    PrintList(list);
    DestroyList(&list);
    return 0;
}
