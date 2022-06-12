/*使用动态数组实现的顺序结构栈*/
#include <stdio.h>
#include <malloc.h>

#define Initsize 20 //Initial Size 初始容量

typedef struct SeqStack {
    int *data;
    int top, maxsize;
} sqstack;

/*Initialize Sequential Stack 初始化顺序结构栈*/
void InitStack(sqstack &S) {
    S.maxsize = Initsize;
    S.data = (int *)malloc(sizeof(int) * S.maxsize);
    S.top = -1;
}

bool Empty(sqstack S) {
    if (S.top == -1)
        return true;
    return false;
}

/*Extend Size of Stack 扩充栈容量*/
void ExtendStack(sqstack &S, int n) {
    int *p = S.data;
    S.maxsize += n;
    S.data = (int *)malloc(sizeof(int) * S.maxsize);
    for (int i = 0; i <= S.top; i++)
        S.data[i] = p[i];
}

/*Push Element 元素入栈*/
void Push(sqstack &S, int e) {
    if (S.top + 1 == S.maxsize)
        ExtendStack(S, 1);
    S.data[++S.top] = e;
}

/*Pop Element 元素出栈*/
void Pop(sqstack &S, int &e) {
    if (Empty(S)) {
        printf("Empty Stack!\n");
        return;
    }
    e = S.data[S.top--];
}

/*Print Sequential Stack 打印顺序结构栈*/
void PrintStack(sqstack S) {
    if (Empty(S)) {
        printf("Empty Stack!\n");
        return;
    }
    for (int i = 0; i <= S.top; i++)
        printf("%d\n", S.data[i]);
}

/*Destroy Sequential Stack 销毁顺序结构栈*/
void DestroyStack(sqstack *S) {
    free(S->data);
    S->data = NULL;
    free(S);
    S = NULL;
}

int main() {
    sqstack stack;
    int e;
    InitStack(stack);
    Push(stack, 1);
    Pop(stack, e);
    Push(stack, 2);
    PrintStack(stack);
    DestroyStack(&stack);
    return 0;
}