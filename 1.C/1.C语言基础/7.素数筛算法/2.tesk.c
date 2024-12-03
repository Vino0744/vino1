/*************************************************************************
	> File Name: 2.tesk.c
	> Author: 
	> Mail: 
	> Created Time: Tue 11 Jul 2023 07:43:24 PM CST

problem1 :
求出范围n内所有数字的最小素因子

problem2 :
求出范围n内所有数字的最大素因子

本体设n取10000
 ************************************************************************/
#include <stdio.h>
#define N 100

void init(int *arr, int n) {
    for (int i = 2; i < n; i++) {
        if (arr[i]) continue;
        for (int j = 2; j <= n / i; j++) arr[i * j] = 1;
        arr[++arr[0]] = i;
    }
    return ;
}

void init1(int *arr, int n) {
    for (int i = 2; i <= n; i++) {
        if (arr[i]) continue;
        arr[i] = i;
        for (int j = i; j < n / i; j++) {
            if (arr[i * j] == 0) arr[i * j] = i;
        }
    }
    return ;
}

void init2(int *arr, int n) {
    for (int i = 2; i <= n; i++) {
        if (arr[i]) continue;
        arr[i] = i;
        for (int j = 2, J = n / i; j <= J; j++) arr[i * j] = i;
    }
    return ;
}

void output(int *arr) {
    for (int i = 2; i <= N; i++) printf("prime[%d] = %d\n", i, arr[i]);
    return ;
}

int main() {
    int prime[N + 5] = {0};
    //init(prime, N);
    //init1(prime, N);
    init2(prime, N);
    output(prime);
    return 0;
}
