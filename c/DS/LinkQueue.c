/* 链式结构的队列 */
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

/* Initialize Link Queue 初始化链式结构队列 */
void InitQueue(linkqueue *Q) {
    Q->front = Q->rear = (lnode *)malloc(sizeof(lnode));
    Q->front->next = NULL;
}

int Empty(linkqueue Q) {
    return Q.front == Q.rear;
}

/* Elements Enter Queue 元素入队 */
void EnterQueue(linkqueue *Q, int e) {
    lnode *s = (lnode *)malloc(sizeof(lnode));
    s->data = e;
    s->next = NULL;
    Q->rear->next = s;
    Q->rear = s;
}

/* Element Exit Queue 元素出队 */
void ExitQueue(linkqueue *Q, int *e) {
    if (Empty(*Q)) {
        printf("Empty Queue!\n");
        return;
    }
    lnode *p = Q->front->next; // p 指向要删除的结点
    e = Q->front->data;
    Q->front->next = p->next;
    if (p ==  Q->rear) // 若 p 等于尾结点，则队列置空
        Q->rear = Q->front;
    free(p); // 释放该结点内存
}

/* Print Link Queue 打印链式结构队列 */
void PrintQueue(linkqueue Q) {

}

/* Destroy Link Queue 销毁链式结构队列 */
void DestroyQueue(linkqueue *Q) {

}

int main() {
    
}