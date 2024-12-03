/*************************************************************************
	> File Name: 956.c
	> Author: 
	> Mail: 
	> Created Time: Wed 05 Jul 2023 05:07:40 PM CST
 ************************************************************************/

#include<stdio.h>

#define MAX_N 25

int arr[MAX_N] = {0};

void fib(int n) {
    if (n == 1 || n == 2) return ;
    fib(n - 1);
    arr[n] = arr[n - 1] + arr[n - 2];
    return ;
}

int main() {
    arr[1] = arr[2] = 1;
    int n;
    scanf("%d", &n);
    fib(n);
    printf("%d\n", arr[n]);
    return 0;
}
