#include "SeqStack.h"

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