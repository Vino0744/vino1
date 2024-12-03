/*************************************************************************
	> File Name: 1.c
	> Author: 
	> Mail: 
	> Created Time: Fri 07 Jul 2023 02:45:54 PM CST
 ************************************************************************/

//素数 = 质数
//N = 1 * N

#include<stdio.h>
#include <stdlib.h>
#define MAX_N 100

void is_prime(int *prime, int n) {
    for (int i = 2; i < n; i++) {
        if(prime[i]) continue;
        prime[++prime[0]] = i;//非常秀
        for(int j = 2, I = n / i; j <= I; j++) {//i为素数 j为倍数
            prime[i * j] = 1;
        }
    }
    return ;
}

int main() {
    int *prime = (int *)calloc(MAX_N + 5, sizeof(int));
    is_prime(prime, MAX_N);//对数组进行标记
    for (int i = 1; i <= prime[0]; i++) {
        printf("%d\n ", prime[i]);
    }
    return 0;
}
