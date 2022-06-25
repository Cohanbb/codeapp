/*
 * We all know when a variable directly be used as a parameter of function, the function can not change the variable's value, because the variable just plays as a formal parameter of the function. 
 * Actually the function just uses the copies of the variables as parameters. If we manage to make the function change the variables's values, we should use pointer or reference of the variables as parameters.
 * Now the situation changes, a pointer(or reference) be a parameter of function, and we manage to make the function change the pointer's value, in another words, we hope the function can change the pointer pointing.
 * How to do that? 
 * The code below includes two functions test1 and test2, test1 uses pointer as a parameter and test2 uses pointer of pointer as a parameter.
 * 我们都知道，当一个变量直接用作函数的参数时，函数不能改变变量的值，因为变量只是作为函数的形式参数发挥作用。
 * 实际上，该函数只使用变量的副本作为参数。如果我们设法让函数更改变量的值，我们应该使用变量的指针或引用作为参数。
 * 现在情况发生了变化，指针（或引用）是函数的参数，我们设法使函数更改指针的值，换句话说，我们希望函数可以更改指针的指向。
 * 如何做到这一点？
 * 下面的代码包括两个函数 test1 和 test2，test1 使用指针作为参数，test2 使用指针的指针作为参数。
 */

#include <stdio.h>

void test1(char *q) {
    q = q + 1;
}

void test2(char **r) {
    *r = *r + 1;
}

int main() {
    char a[] = {'a', 'b'};
    char *p = a; 
    test1(p);
    printf ("%c\n", *p);
    test2(&p);
    printf("%c\n", *p);
    return 0;
}


/*
 * As a result, function test1 print 'a' and function test2 print 'b', so function test2 changes the value of the pointer.
 * 结果，函数 test1 打印 “a”，函数 test2 打印“b”，因此函数 test2 更改了指针的指向。
 */
 
