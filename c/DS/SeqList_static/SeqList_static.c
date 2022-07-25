/* 使用静态数组实现的顺序表 */
#include "SeqList_static.h"

/* Initialize Sequential List 初始化顺序表 */
void InitList(sqlists *L) {
    for (int i = 0; i < Maxsize; ++i)
        L->data[i] = 0;
    L->length = 0;
}

int Empty(sqlists L) {
    return L.length == 0;
}

/* Insert element 插入元素 */
void InsertElem(sqlists *L, int i, int e) {
    if (i <= 0 || i > L->length + 1) {
        printf("Invalid Position!\n");
        return;
    }
    if (L->length == Maxsize) {
        printf("Oversize!\n");
        return;
    }
    for (int j = L->length; j >= i; --j)
        L->data[j] = L->data[j - 1];
    L->data[i - 1] = e;
    ++L->length;
}

/* Delete element 删除元素 */
void DeleteElem(sqlists *L, int i, int *e) {
    if (i <= 0 || i > L->length) {
        printf("Invalid Position!\n");
        return;
    }
    *e = L->data[i - 1];
    for (int j = i; j < L->length; ++j)
        L->data[j - 1] = L->data[j];
    L->data[L->length - 1] = 0;
    --L->length;
}

/* Search Element by Value 按值查找 */
void LocateElem(sqlists L, int *i, int e) {
    for (int j = 0; j < L.length; ++j) {
        if (L.data[j] == e) {
            *i = j + 1;
            return;
        }
    }
    printf("Not Found!\n");
}

/* Print Sequential List 打印顺序表 */
void PrintList(sqlists L) {
    if (Empty(L)) {
        printf("Empty List!\n");
        return;
    }
    for (int i = 0; i < L.length; ++i)
        printf("%d\n", L.data[i]);
}

