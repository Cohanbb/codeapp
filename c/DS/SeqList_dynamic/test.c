#include "SeqList_dynamic.h"

int main() {
    sqlistd list;
    int i, e;
    InitList(&list);
    InsertElem(&list, 1, 2);
    InsertElem(&list, 2, 3);
    InsertElem(&list, 3, 4);
    DeleteElem(&list, 2, &e);
    PrintList(list);
    DestroyList(&list);
    return 0;
}