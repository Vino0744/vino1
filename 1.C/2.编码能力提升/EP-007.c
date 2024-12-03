/*************************************************************************
	> File Name: EP-007.c
	> Author: 
	> Mail: 
	> Created Time: Tue 11 Jul 2023 04:15:54 PM CST

Problem 7: $10001$st prime

By listing the first six prime numbers: $2$, $3$, $5$, $7$, $11$, and $13$, we can see that the $6$th prime is $13$.

What is the $10001$st prime number?

 ************************************************************************/

#include<stdio.h>
#include <math.h>
#include <stdlib.h>
#define N 10001 * 20

void init(int *num) {
    for (int i = 2; i < N; i++) {
        if (num[i]) continue;
        num[++num[0]] = i;
        for (int j = i; j < N / i; j++) {
            num[i * j] = 1;
        }
    }
    return ;
}

int main() {
    int *num = (int *)calloc(N, sizeof(int));
    init(num);
    printf("%d\n", num[10001]);
    return 0;
}
