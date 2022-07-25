#ifndef __SEQSTACK_H__
#define __SEQSTACK_H__
#include <stdio.h>
#include <stdlib.h>

typedef struct SeqStack sqstack;

/* Initialize Sequential Stack 初始化顺序结构栈 */
void InitStack(sqstack *S);

int Empty(sqstack S);

/* Extend Size of Stack 扩充栈容量 */
void ExtendStack(sqstack *S, int n);

/* Push Element 元素入栈 */
void Push(sqstack *S, int e);

/* Pop Element 元素出栈 */
void Pop(sqstack *S, int *e);

/* Print Sequential Stack 打印顺序结构栈 */
void PrintStack(sqstack S);

/* Destroy Sequential Stack 销毁顺序结构栈 */
void DestroyStack(sqstack *S);

#endif