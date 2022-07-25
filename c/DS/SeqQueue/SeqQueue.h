#ifndef __SEQQUEUE_H__
#define __SEQQUEUE_H__
#include <stdio.h>
#include <stdlib.h>

typedef struct SeqQueue sqqueue;

/* Initialize Sequential Queue 初始化顺序结构循环队列 */
void InitQueue(sqqueue *Q);

int Empty(sqqueue Q);

/* Extend Size of Queue 扩充循环队列的容量 */
void ExtendQueue(sqqueue *Q, int n);

/* Element Enter Queue 元素进入队列 */
void EnterQueue(sqqueue *Q, int e);

/* Element Exit Queue 元素退出队列 */
void ExitQueue(sqqueue *Q, int *e);

/* Print Sequential Queue 打印顺序结构循环队列 */
void PrintQueue(sqqueue Q);

/* Destroy Sequential Queue 销毁顺序结构循环队列 */
void DestroyQueue(sqqueue *Q);

#endif