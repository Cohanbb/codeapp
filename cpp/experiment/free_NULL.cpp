#include <stdio.h>
#include <malloc.h>

int main() {
    int *p = (int *)malloc(sizeof(int) * 2);
    p[0] = 1;
    p[1] = 2;
    printf("%d\n", *p);
    printf("%d\n", p[1]);
    free(p);
    //p = NULL;
    printf("%d\n", *p);
    printf("%d\n", p[1]);
    return 0;
}

