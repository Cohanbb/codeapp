#include <stdio.h>
#include <malloc.h>

int main() {
    int a = 1;
    int *p = (int *)malloc(sizeof(int));
    *p = 1;
    free(p);
    *p = 3;
    printf("%d\n", *p);
    int b = 2;
    int *q = &b;
    free(q);
    *q = 3;
    printf("%d\n", *q);
    return 0;
}

