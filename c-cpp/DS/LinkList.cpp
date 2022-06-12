#include <stdio.h>
#include <malloc.h>

typedef struct LNode {
    int data;
    struct LNode *next;
} lnode, *linklist;

/*Initialize Link List 初始化链表*/
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

/*Search Element by Position 按位查找*/
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

/*Insert node 插入节点*/
void InsertElem(linklist &L, int i, int e) {
    lnode *p = GetElem(L, i - 1);
    if (!p) {
        printf("Invalid Position!\n");
        return;
    }
    lnode *s = (lnode *)malloc(sizeof(lnode)); //开辟新的结点
    s->data = e;
    s->next = p->next;
    p->next = s;
}

/*Delete node 删除节点*/
void DeleteElem(linklist &L, int i, int &e) {
    lnode *p = GetElem(L, i - 1);
    if (!p) {
        printf("Invalid Position!\n");
        return;
    }
    lnode *q = p->next; //q 指向要删除的结点
    e = q->data;
    p->next = q->next;
    free(q); //释放该结点内存
}

/*Search Element by Value 按值查找*/
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

/*Print Link List 打印链表*/
void PrintList(linklist L) {
    if (Empty(L)) {
        printf("Empty List!\n");
        return;
    }
    lnode *p = L->next;
    while (p) {
        printf("%d\n", p->data);
        p = p->next;
    }
}

/*Destroy Link List 销毁链表 */
void DestroyList(linklist &L) {
    lnode *p;
    while (L) {
        p = L;
        L = L->next;
        free(p); //释放该结点内存 
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
    printf("Delete element is %d\n", e);
    DestroyList(list);
    return 0;
}
