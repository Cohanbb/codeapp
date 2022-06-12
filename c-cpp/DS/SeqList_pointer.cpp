/*使用动态数组实现的顺序表*/
#include <stdio.h>
#include <malloc.h>

#define Initsize 20 //Initial maxsize

typedef struct Seqlist_pointer {
    int *data;
    int length, maxsize;
} sqlist;

/*Initialize Sequential List 初始化顺序表*/
void InitList(sqlist &L) {
    L.maxsize = Initsize;
    L.data = (int *)malloc(sizeof(int) * L.maxsize);
    L.length = 0;
    for (int i = 0; i < L.maxsize; i++)
        *(L.data + i) = 0;
}

bool Empty(sqlist L) {
    return L.length == 0;
}

/*Extend Size of List 扩充顺序表容量*/
void ExtendList(sqlist &L, int n) {
    int *p = L.data; //p 指向原地址
    L.maxsize += n; //扩容
    L.data = (int *)malloc(sizeof(int) * L.maxsize); //开辟新地址
    for (int i = 0; i < L.length; i++)
        *(L.data + i) = *(p + i);
    free(p); //释放 p 指向的内存
    p = NULL; //p 置空
}

/*Insert Element 插入元素*/
void InsertElem(sqlist &L, int i, int e) {
    if (i <= 0 || i > L.length + 1) {
        printf("Invalid Position!\n");
        return;
    }
    if (L.length == L.maxsize)
        ExtendList(L, 1);
    for (int j = L.length; j >= i; j--)
        *(L.data + j) = *(L.data + j - 1);
    *(L.data + i - 1) = e;
    L.length++;
}

/*Delete Element 删除元素*/
void DeleteElem(sqlist &L, int i, int &e) {
    if (i <= 0 || i > L.length) {
        printf("Invalid Position!\n");
        return;
    }
    e = *(L.data + i - 1);
    for (int j = i; j < L.length; j++)
        *(L.data + j - 1) = *(L.data + j);
    *(L.data + L.length - 1) = 0;
    L.length--;
}

/*Search Element By Value 按值查找*/
void LocateElem(sqlist L, int &i, int e) {
    for (int j = 0; j < L.length; j++) {
        if (*(L.data + j) == e) {
            i = j + 1;
            return;
        }
    }
    printf("Not Found!\n");
}

/*Print Sequential List 打印顺序表*/
void PrintList(sqlist L) {
    if (Empty(L)) {
        printf("Empty List!\n");
        return;
    }
    for (int i = 0; i < L.length; i++)
        printf("%d\n", *(L.data + i));
}

/*Destroy Sequential List 销毁顺序表*/
void DestroyList(sqlist *L) {
    if (!L)
        return;
    free(L->data); //释放数组内存
    L->data = NULL; //指针置空
    L->length = 0;
    L->maxsize = 0;
}

int main() {
    sqlist list;
    int i, e;
    InitList(list);
    InsertElem(list, 1, 2);
    InsertElem(list, 2, 3);
    InsertElem(list, 3, 4);
    DeleteElem(list, 2, e);
    PrintList(list);
    DestroyList(&list);
    return 0;
}
