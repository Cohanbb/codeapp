#ifndef __LINKQUEUE_H__
#define __LINKQUEUE_H__
#include <stdio.h>
#include <stdlib.h>

/* Definition of Link Queue Node 定义链式队列结点 */
typedef struct LNode {
    int data;
    struct LNode *next; 
} lnode;

/* Definition of Link Queue 定义链式队列 */
typedef struct LinkQueue {
    lnode *front;
    lnode *rear;
} linkqueue;

/* Initialize Link Queue 初始化链式结构队列 */
void InitQueue(linkqueue *Q);

int Empty(linkqueue Q);

/* Elements Enter Queue 元素入队 */
void EnterQueue(linkqueue *Q, int e);

/* Element Exit Queue 元素出队 */
void ExitQueue(linkqueue *Q, int *e);

/* Print Link Queue 打印链式结构队列 */
void PrintQueue(linkqueue Q);

/* Destroy Link Queue 销毁链式结构队列 */
void DestroyQueue(linkqueue *Q);

#endif
