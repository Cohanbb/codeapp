/*链式结构的队列*/
#include <stdio.h>
#include <malloc.h>

typedef struct LNode {
    int data;
    struct LNode *next; 
} lnode;

typedef struct LinkQueue {
    lnode *front;
    lnode *rear;
} linkqueue;

void InitQueue(linkqueue &Q) {
    Q.front = Q.rear = (lnode *)malloc(sizeof(lnode));
    Q.front->next = NULL;
}

bool Empty(linkqueue Q) {
    return Q.front == Q.rear;
}

void EnterQueue(linkqueue &Q, int e) {
    lnode *s = (lnode *)malloc(sizeof(lnode));
    s->data = e;
    s->next = NULL;
    Q.rear->next = s;
    Q.rear = s;
}

void ExitQueue(linkqueue &Q, int &e) {
    if (Empty(Q)) {
        printf("Empty Queue!\n");
        return;
    }
    lnode *p = Q.front->next;
    e = Q.front->data;
    Q.front->next = p->next;
    if (Q.rear == p)
        Q.rear = Q.front;
    free(p);
    p = NULL;
}

void PrintQueue(linkqueue Q) {

}

void DestroyQueue(linkqueue &Q) {

}

int main() {
    
}