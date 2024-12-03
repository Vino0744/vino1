/*************************************************************************
	> File Name: test.c
	> Author: 
	> Mail: 
	> Created Time: Sun 02 Jul 2023 05:31:55 PM CST
 ************************************************************************/

#include<stdio.h>

int main() {
    int a = 0, b = 0;
    if ((a++) && (b++)) {
        printf("true\n");
    } else {
        printf("false\n");
    }
    printf("a = %d, b = %d\n", a, b);
    return 0;
}
