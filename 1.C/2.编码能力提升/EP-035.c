/*************************************************************************
	> File Name: EP-035.c
	> Author: 
	> Mail: 
	> Created Time: Wed 12 Jul 2023 03:03:08 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_N 1000000

int is_prime[MAX_N] = {0};

void init(int *prime) {
    for (int i = 2; i <= MAX_N; i++) {
        if (!is_prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= MAX_N; j++) {
            if (prime[j] * i > MAX_N) break;
            is_prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    return ;
}

int is_val(int x) {
    int digit = floor(log10(x)) + 1;
    int h = pow(10, digit - 1);
    for (int i = 1; i < digit; i++) {
        x = ((x - x / h * h) * 10 + x / h);
        if (is_prime[x]) return 0;
    }
    return 1;
}

int main() {
    int *prime = (int *)calloc(MAX_N + 5, sizeof(int));
    init(prime);
    int cnt = 0;
    for (int i = 1; i <= prime[0]; i++) {
        if (is_val(prime[i])) cnt += 1;
    }
    printf("%d\n", cnt);
    return 0;
}
