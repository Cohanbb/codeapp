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
    if (Q.rear = Q.front) 
        return true;
    return false;
}

void ExtendQueue(sqqueue &Q, int n) {
    
}

void EnQueue(sqqueue &Q, int e) {
    if ((Q.rear + 1) % Q.maxsize == Q.front)
        ExtendQueue(Q, 1);
    Q.data[Q.rear] = e;
    Q.rear = (Q.rear + 1) % Q.maxsize;
}

void DeQueue(sqqueue &Q, int &e) {
    if (Q.rear == Q.front) {
        printf("Empty Queue!");
        return;
    }
    e = Q.data[Q.front];
    Q.front = (Q.front + 1) % Q.maxsize;
}

void PrintQueue(sqqueue Q) {
    
}

void DestroyQueue(sqqueue *Q) {
    free(Q->data);
    Q->data = NULL;
    free(Q);
    Q = NULL;
}

int main() {

}