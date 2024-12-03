/*************************************************************************
	> File Name: 4.函数指针.c
	> Author: 
	> Mail: 
	> Created Time: Sun 09 Jul 2023 03:29:22 PM CST
 ************************************************************************/

#include<stdio.h>

int add(int a, int b) {
    return a + b;
}

int main() {
    typedef int (*add_func)(int, int);
    add_func f1 = add;
    printf("%d\n", f1(1, 2));
    return 0;
}
