/* 使用动态数组实现的顺序结构栈 */
#include <stdio.h>
#include <malloc.h>

#define Initsize 20 // Initial Size 初始容量

typedef struct SeqStack {
    int *data;
    int top, maxsize;
} sqstack;

/* Initialize Sequential Stack 初始化顺序结构栈 */
void InitStack(sqstack *S) {
    S->maxsize = Initsize;
    S->data = (int *)malloc(sizeof(int) * S->maxsize);
    S->top = -1;
}

int Empty(sqstack S) {
    return S.top == -1;
}

/* Extend Size of Stack 扩充栈容量 */
void ExtendStack(sqstack *S, int n) {
    int *p = S->data; // p 指向原地址
    S->maxsize += n; // 扩容
    S->data = (int *)malloc(sizeof(int) * S->maxsize); // 开辟新地址
    for (int i = 0; i <= S->top; i++)
        S->data[i] = p[i];
    free(p); // 释放原地址
    p = NULL; // p 置空
}

/* Push Element 元素入栈 */
void Push(sqstack *S, int e) {
    if (S->top + 1 == S->maxsize)
        ExtendStack(S, 1);
    S->data[++S->top] = e;
}

/* Pop Element 元素出栈 */
void Pop(sqstack *S, int *e) {
    if (Empty(*S)) {
        printf("Empty Stack!\n");
        return;
    }
    *e = S->data[S->top--];
}

/* Print Sequential Stack 打印顺序结构栈 */
void PrintStack(sqstack S) {
    if (Empty(S)) {
        printf("Empty Stack!\n");
        return;
    }
    for (int i = 0; i <= S.top; i++)
        printf("%d\n", S.data[i]);
}

/* Destroy Sequential Stack 销毁顺序结构栈 */
void DestroyStack(sqstack *S) {
    if (!S)
        return;
    free(S->data); // 释放数组内存
    S->data = NULL; // 指针置空
    S->top = -1;
    S->maxsize = 0;
}

int main() {
    sqstack stack;
    int e;
    InitStack(&stack);
    Push(&stack, 1);
    Push(&stack, 2);
    Pop(&stack, &e);
    Push(&stack, 3);
    PrintStack(stack);
    DestroyStack(&stack);
    return 0;
}