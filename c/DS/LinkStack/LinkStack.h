#ifndef __LINKSTACK_H__
#define __LINKSTACK_H__
#include <stdio.h>
#include <stdlib.h>

typedef struct LNode lnode, *linkstack;

/* Initialize Link Stack 初始化链式结构栈 */
void InitStack(linkstack *S);

int Empty(linkstack S);

/* Push Element元素入栈 */
void Push(linkstack *S, int e);

/* Pop Element 元素出栈 */
void Pop(linkstack *S, int *e);

/* Print Link Stack 打印链式结构栈 */
void PrintStack(linkstack S);

/* Destroy Link Stack 销毁链式结构栈 */
void DestroyStack(linkstack *S);

#endif