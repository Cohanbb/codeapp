#ifndef __LINKQUEUE_H__
#define __LINKQUEUE_H__
#include <stdio.h>
#include <stdlib.h>

typedef struct LNode lnode;

typedef struct LinkQueue linkqueue;

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
