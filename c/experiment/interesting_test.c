#include <stdio.h>

int main() {
    int a[5] = {1, 2, 3, 4, 5};
    printf("%d\n", a[3]);
    printf("%d\n", 3[a]);
    return 0; 
}

// a[3] -> *(a + 3)
// 3[a] -> *(3 + a)