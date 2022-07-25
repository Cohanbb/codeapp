#include "LinkList.h"

int main() {
    linklist list;
    int e;
    InitList(&list);
    InsertElem(&list, 1, 1);
    InsertElem(&list, 2, 2);
    InsertElem(&list, 3, 3);
    DeleteElem(&list, 2, &e);
    PrintList(list);
    printf("Delete element is %d\n", e);
    DestroyList(&list);
    return 0;
}