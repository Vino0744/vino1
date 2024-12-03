/*************************************************************************
	> File Name: 2.判断奇偶.c
	> Author: 
	> Mail: 
	> Created Time: Sun 02 Jul 2023 07:00:16 PM CST
 ************************************************************************/

#include<stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
    srand(time(0));
    int val = rand() & 1;
    printf("val = %d\n", val);
    if (val) {
        printf("奇数\n");
    } else {
        printf("偶数\n");
    }
    return 0;
}
