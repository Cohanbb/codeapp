#include <stdio.h>
#include <malloc.h>

typedef struct LNode {
    int data;
    struct LNode *next;
} lnode, *linklist;

void InitList(linklist &L) {
    L = (lnode *)malloc(sizeof(lnode));
    if (L == NULL) {
        printf("Fail To Init!\n");
	return;
    }
    L->next = NULL;
}

bool Empty(linklist L) {
    return L->next == NULL;
}

lnode *GetElem(linklist L, int i) {
    if (i < 0) {
        printf("Invalid Position!\n");
	return NULL;
    } 
    if (i == 0)
	    return L;
    lnode *p = L;
    while (p && i > 0) {
        p =  p->next;
        i--;
    }
    return p;
}

void InsertElem(linklist &L, int i, int e) {
    lnode *p = GetElem(L, i - 1);
    if (!p) {
        printf("Invalid Position!\n");
        return;
    }
    lnode *s = (lnode *)malloc(sizeof(lnode));
    s->data = e;
    s->next = p->next;
    p->next = s;
}

void DeleteElem(linklist &L, int i, int &e) {
    lnode *p = GetElem(L, i - 1);
    if (!p) {
        printf("Invalid Position!");
        return;
    }
    e = p->next->data;
    p->next = p->next->next;
}

lnode *LocateElem(linklist L, int e) {
    lnode *p = L->next;
    while (p) {
        if (p->data == e)
            return p;
        p = p->next;
    }
    printf("Not Found!\n");
    return NULL;
}

void PrintList(linklist L) {
    lnode *p = L->next;
    while (p) {
        printf("%d\n", p->data);
        p = p->next;
    }
}

int main() {
    linklist list;
    int e;
    InitList(list);
    InsertElem(list, 1, 1);
    InsertElem(list, 2, 2);
    InsertElem(list, 3, 3);
    DeleteElem(list, 2, e);
    PrintList(list);
    printf("delete element is %d\n", e);
    return 0;
}
