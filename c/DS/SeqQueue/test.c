#include "SeqQueue.h"

int main() {
    sqqueue queue;
    int e;
    InitQueue(&queue);
    EnterQueue(&queue, 1);
    ExitQueue(&queue, &e);
    EnterQueue(&queue, 2);
    PrintQueue(queue);
    DestroyQueue(&queue);
    return 0;
}