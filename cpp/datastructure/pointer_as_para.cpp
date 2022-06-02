/*
 We all know when a variable directly be used as a parameter of function, the function can not change the variable's value, because the variable just plays as a formal parameter of the function. 
 Actually the function just uses the copies of the variables as parameters. If we manage to make the function change the variables's values, we should use pointer or reference of the variables as parameters.
 Now the situation changes, a pointer(or reference) be a parameter of function, and we manage to make the function change the pointer's value, in another words, we hope the function can change the pointer pointing.
 How to do that? 
 The code below includes two functions test1 and test2, test1 uses pointer as a parameter and test2 uses pointer of pointer as a parameter.
*/


#include <stdio.h>

void test1(char *q) {
    q = q + 1;
}

void test2(char **r) {
    *r = *r + 1;
}

int main () {
    char a[] = {'a', 'b'};
    char *p = a; 
    test1(p);
    printf ("%c\n", *p);
    test2(&p);
    printf("%c\n", *p);
    return 0;
}


/*
 As a result, function test1 print 'a' and function test2 print 'b', so function test2 changes the value of the pointer.
*/
