#include <stdio.h>
#include <malloc.h>

typedef struct A {
    int a, b;
} A;

int main() {
    A *p = (A *)malloc(sizeof(A)); 
    p->a = 1;
    p->b = 2;
    printf("%p\n", p);
    free(p);
    printf("%p\n", p);
    printf("%d\n", p->a);
    printf("%d\n", p->b);
    p->a = 3;
    p->b = 4;
    return 0;
}

