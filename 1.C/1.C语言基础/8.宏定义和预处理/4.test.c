/*************************************************************************
	> File Name: 3.test.c
	> Author: 
	> Mail: 
	> Created Time: Fri 07 Jul 2023 10:01:58 PM CST
 ************************************************************************/

#include<stdio.h>

#define MAX(a, b) ({ \
    __typeof(a) __a = a; \
    __typeof(b) __b = b; \
    (__a) > (__b) ? __a : __b; \
})

int main() {
    printf("MAX(2, 3) = %d\n", MAX(2, 3));//3
    printf("5 + MAX(2, 3) = %d\n", 5 + MAX(2, 3));//8
    printf("MAX(2, MAX(3, 4)) = %d\n", MAX(2, MAX(3, 4)));//4
    printf("MAX(2, 3 > 4 ? 3 : 4) = %d\n", MAX(2, 3 > 4 ? 3 : 4));//4
    int a = 7;
    printf("MAX(a++, 6) = %d\n", MAX(a++, 6));//7
    printf("a = %d\n", a);//8
    return 0;
}
