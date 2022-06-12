/*链式结构的栈*/
#include <stdio.h>
#include <malloc.h>

typedef struct LNode {
    int data;
    struct LNode *next; 
} LNode, *linkstack;

void InitStack(linkstack &S) {

}

bool Empty(linkstack S) {
    return S.top == -1;
}

void Push(linkstack &S, int e) {

}

void Pop(linkstack &S, int &e) {

}

void PrintStack(linkstack S) {

}

void DestroyStack(linkstack &S) {

}

int main() {
    
}