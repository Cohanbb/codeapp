#include "SeqList_static.h"

int main() {
    sqlists list;
    int i, e;
    InitList(&list);
    InsertElem(&list, 1, 1); // insert 1 at the first position
    InsertElem(&list, 2, 3); // insert 3 at the second position
    DeleteElem(&list, 1, &e); // delete content at the first position
    printf("%d\n", e);
    PrintList(list);
    LocateElem(list, &i, 1);
    return 0;
}