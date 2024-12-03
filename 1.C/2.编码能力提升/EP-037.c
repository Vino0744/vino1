/*************************************************************************
	> File Name: EP-037.c
	> Author: 
	> Mail: 
	> Created Time: Wed 12 Jul 2023 03:43:06 PM CST

Problem 37: Truncatable primes

The number $3797$ has an interesting property. Being prime itself, it is possible to continuously remove digits from left to right, and remain prime at each stage: 
$3797$, $797$, $97$, and $7$. Similarly we can work from right to left: $3797$, $379$, $37$, and $3$.

Find the sum of the only eleven primes that are both truncatable from left to right and right to left.

NOTE: $2$, $3$, $5$, and $7$ are not considered to be truncatable primes.

 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_N 1000000

int prime[MAX_N + 5];
int is_prime[MAX_N + 5] = {1, 1};

void init() {
    for (int i = 2; i < MAX_N; i++) {
        if (!is_prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j < MAX_N; j++) {
            if (prime[j] * i > MAX_N) break;
            is_prime[prime[j] * i] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    return ;
}

int is_val(int n) {
    //从右向左
    int x = n;
    while (x) {
        if (is_prime[x]) return 0;
        x /= 10;
    }
    //从左向右
    int digit = floor(log10(n));
    x = n;
    for (int i = digit; i >= 1; i--) {
        if (is_prime[(x % (int)pow(10, i))]) return 0;
        x = x - (x / (int)pow(10, i) * (int)pow(10, i));
    }
    return 1;
}

int main() {
    init();
    int sum = 0, flag = 11;
    for (int i = 5; flag && i <= prime[0]; i++) {
        if (!is_val(prime[i])) continue;
        sum += prime[i];
        flag--;
    }
    printf("flag : %d, sum = %d\n", flag, sum);
    return 0;
}
