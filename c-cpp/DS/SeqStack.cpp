/*使用数组实现的顺序栈*/
#include <stdio.h>
#include <malloc.h>

#define Initsize 20;

typedef struct SeqStack {
    int *data;
    int top, maxsize;
} sqstack;

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

void ExtendStack(sqstack &S, int n) {
    int *p = S.data;
    S.maxsize += n;
    S.data = (int *)malloc(sizeof(int) * S.maxsize);
    for (int i = 0; i <= S.top; i++)
        S.data[i] = p[i];
}

void Push(sqstack &S, int e) {
    if (S.top + 1 == S.maxsize)
        ExtendStack(S, 1);
    S.data[++S.top] = e;
}

void Pop(sqstack &S, int &e) {
    if (Empty(S)) {
        printf("Empty Stack!");
        return;
    }
    e = S.data[S.top--];
}

void PrintStack(sqstack S) {
    if (Empty(S)) {
        printf("Empty Stack!");
        return;
    }
    for (int i = 0; i <= S.top; i++)
        printf("%d\n", S.data[i]);
}

void Destroy(sqstack *S) {
    free(S->data);
    S->data = NULL;
    free(S);
    S = NULL;
}

int main() {
    
}