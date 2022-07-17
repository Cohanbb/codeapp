/* 链式结构的栈（带头结点） */
#include <cstdio>
#include <cstdlib>

typedef struct LNode {
    int data;
    struct LNode *next; 
} lnode, *linkstack;

/* Initialize Link Stack 初始化链式结构栈 */
void InitStack(linkstack &S) {
    S = (lnode *)malloc(sizeof(lnode));
    if (S == NULL) {
        printf("Fail To Init!\n");
        return;
    }
    S->next = NULL;
}

bool Empty(linkstack S) {
    return S->next == NULL;
}

void Push(linkstack &S, int e) {
    lnode *p = (lnode *)malloc(sizeof(lnode)); // 开辟新结点作为栈顶
    p->data = e;
    p->next = S->next;
    S->next = p->next;
}

void Pop(linkstack &S, int &e) {
    if (Empty(S)) {
        printf("Empty Stack!\n");
        return;
    }
    lnode *p = S->next; // p 指向栈顶
    e = p->data;
    S->next = p->next;
    free(p); // 释放该结点内存
}

/* Print Link Stack 打印链式结构栈 */
void PrintStack(linkstack S) {
    if (Empty(S)) {
        printf("Empty List!\n");
        return;
    }
    lnode *p = S->next;
    while (p) {
        printf("%d\n", p->data);
        p = p->next;
    }
}

/* Destroy Link Stack 销毁链式结构栈 */
void DestroyStack(linkstack &S) {
    lnode *p;
    while (S) {
        p = S;
        S = S->next;
        free(p); // 释放该结点内存 
    }
}

int main() {
    
}