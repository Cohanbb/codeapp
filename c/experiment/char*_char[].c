#include <stdio.h>

int main() {
    char *p = "hello world!";
    char q[] = "HELLO WORLD!";
    *p = "123"; // Error
    *q = "123";
    return 0;
}