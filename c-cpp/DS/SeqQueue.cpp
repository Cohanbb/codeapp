/*使用动态数组实现循环队列*/
#include <stdio.h>
#include <malloc.h>

#define Initsize 20 //Initial Size 初始容量

typedef struct Queue {
    int *data;
    int front, rear, maxsize;
} sqqueue;

void InitQueue(sqqueue &Q) {
    Q.maxsize = Initsize;
    Q.data = (int *)malloc(sizeof(int) * Q.maxsize);
    Q.rear = Q.front = 0;
    for (int i = 0; i < Q.maxsize; i++)
        Q.data[i] = 0;
}

bool Empty(sqqueue Q) {
    if (Q.rear == Q.front) 
        return true;
    return false;
}

void ExtendQueue(sqqueue &Q, int n) {
    int *p = Q.data;
    int i, j;
    j = Q.maxsize;
    Q.maxsize += n;
    Q.data = (int *)malloc(sizeof(int) * Q.maxsize);
    for (i = 0; i < (Q.rear + j - Q.front) % j; i++)
        Q.data[i] = p[(Q.front + i) % j];
}

void EnQueue(sqqueue &Q, int e) {
    if ((Q.rear + 1) % Q.maxsize == Q.front)
        ExtendQueue(Q, 1);
    Q.data[Q.rear] = e;
    Q.rear = (Q.rear + 1) % Q.maxsize;
}

void DeQueue(sqqueue &Q, int &e) {
    if (Empty(Q)) {
        printf("Empty Queue!\n");
        return;
    }
    e = Q.data[Q.front];
    Q.front = (Q.front + 1) % Q.maxsize;
}

void PrintQueue(sqqueue Q) {
    if (Empty(Q)) {
        printf("Empty Queue!\n");
        return;
    }
    for (int i = 0; i < (Q.rear + Q.maxsize - Q.front) % Q.maxsize; i++)
        printf("%d\n", Q.data[(Q.front + i) % Q.maxsize]);
}

void DestroyQueue(sqqueue *Q) {
    free(Q->data);
    Q->data = NULL;
    free(Q);
    Q = NULL;
}

int main() {
    sqqueue queue;
    int e;
    InitQueue(queue);
    EnQueue(queue, 1);
    DeQueue(queue, e);
    EnQueue(queue, 2);
    PrintQueue(queue);
    DestroyQueue(&queue);
    return 0;
}