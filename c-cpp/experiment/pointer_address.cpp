#include <stdio.h>
#include <malloc.h>

int main() {
    int a = 1;
    int *p = &a;
    int *q = p;
    int *o = (int *)0x11388;
    int *r = (int *)malloc(sizeof(int));
    *r = a;
    free(p);
    *p = 2;
    printf("%p %d\n", &a, a);
    printf("%p %d\n", p, *p);
    printf("%p %d\n", q, *q);
    printf("%p %d\n", o, *o);
    printf("%p %d\n", r, *r);
    return 0;
}