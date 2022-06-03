#include <stdio.h>

typedef struct LNode {
    int data;
    struct LNode *next;
} lnode, *linklist;

void Init(linklist &L) {
    L = (lnode *) malloc (sizeof(lnode));
    if (L == NULL) {
        printf("Memory isn't Adequate, Fail to Init\n");
	return;
    }
    L -> next = NULL;
}

bool Empty(linklist L) {
    return L -> next == NULL;
}

lnode *Getwelem(linklist L, int i) {
    if (i == 0)
	return L;
    if (i < 0)
	return NULL;
    lnode *p = L -> next;
    while (p && i > 0) {
       p =  p -> next;
       i--;
    }
    return p;
}


void Insert(linklist &L, int i, int e) {
    lnode *p = Getelem(L, )
}
