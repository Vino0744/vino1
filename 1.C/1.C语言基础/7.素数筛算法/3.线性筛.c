/*************************************************************************
	> File Name: 3.线性筛.c
	> Author: 
	> Mail: 
	> Created Time: Wed 12 Jul 2023 01:53:12 PM CST
 ************************************************************************/

#include<stdio.h>
#define MAX_N 10000

int prime[MAX_N + 5];

void init() {
    //N = M * P
    //i ---> M
    //prime[j] ---> P``
    for (int i = 2; i <= MAX_N; i++) {
        if (!prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0]; j++) {
            if (prime[j] * i > MAX_N) break;
            prime[prime[j] * i] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    return ;
}

int main() {
    init();
    printf("%d\n", prime[0]);
    return 0;
}
