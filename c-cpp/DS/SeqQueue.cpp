/*使用动态数组实现的循环队列*/
#include <stdio.h>
#include <malloc.h>

#define Initsize 20 //Initial Size 初始容量

typedef struct SeqQueue {
    int *data;
    int front, rear, maxsize;
} sqqueue;

/*Initialize Sequential Queue 初始化顺序结构循环队列*/
void InitQueue(sqqueue &Q) {
    Q.maxsize = Initsize;
    Q.data = (int *)malloc(sizeof(int) * Q.maxsize);
    Q.rear = Q.front = 0;
    for (int i = 0; i < Q.maxsize; i++)
        Q.data[i] = 0;
}

bool Empty(sqqueue Q) {
    return Q.rear == Q.front;
}

/*Extend Size of Sequential Queue 扩充顺序结构队列的容量*/
void ExtendQueue(sqqueue &Q, int n) {
    int *p = Q.data; //p 指向原地址
    int i, j;
    j = Q.maxsize;
    Q.maxsize += n; //扩容
    Q.data = (int *)malloc(sizeof(int) * Q.maxsize); //开辟新地址
    for (i = 0; i < (Q.rear + j - Q.front) % j; i++)
        Q.data[i] = p[(Q.front + i) % j];
    free(p); //释放原地址
    p = NULL; //p 置空
}

/*Element Enter Queue 元素进入队列*/
void EnterQueue(sqqueue &Q, int e) {
    if ((Q.rear + 1) % Q.maxsize == Q.front)
        ExtendQueue(Q, 1);
    Q.data[Q.rear] = e;
    Q.rear = (Q.rear + 1) % Q.maxsize;
}

/*Element Exit Queue 元素退出队列*/
void ExitQueue(sqqueue &Q, int &e) {
    if (Empty(Q)) {
        printf("Empty Queue!\n");
        return;
    }
    e = Q.data[Q.front];
    Q.front = (Q.front + 1) % Q.maxsize;
}

/*Print Sequential Queue 打印顺序结构循环队列*/
void PrintQueue(sqqueue Q) {
    if (Empty(Q)) {
        printf("Empty Queue!\n");
        return;
    }
    for (int i = 0; i < (Q.rear + Q.maxsize - Q.front) % Q.maxsize; i++)
        printf("%d\n", Q.data[(Q.front + i) % Q.maxsize]);
}

/*Destroy Sequential Queue 销毁顺序结构循环队列*/
void DestroyQueue(sqqueue *Q) {
    if (!Q)
        return;
    free(Q->data); //释放数组的内存
    Q->data = NULL; //指针置空
    Q->rear = Q->front = 0;
    Q->maxsize = 0;
}

int main() {
    sqqueue queue;
    int e;
    InitQueue(queue);
    EnterQueue(queue, 1);
    ExitQueue(queue, e);
    EnterQueue(queue, 2);
    PrintQueue(queue);
    DestroyQueue(&queue);
    return 0;
}