/*************************************************************************
	> File Name: EP-010.c
	> Author: 
	> Mail: 
	> Created Time: Wed 12 Jul 2023 02:37:48 PM CST

Problem 10: Summation of primes

The sum of the primes below $10$ is $2 + 3 + 5 + 7 = 17$.

Find the sum of all the primes below two million.

 ************************************************************************/

#include<stdio.h>
#define MAX_N 2000000

int prime[MAX_N] = {0};
long long init() {
    long long sum = 0;
    for (int i = 2; i <= MAX_N; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            sum += i;
        }
        for (int j = 1; j <= MAX_N; j++) {
            if (prime[j] * i > MAX_N) break;
            prime[prime[j] * i] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    return sum;
}

int main() {
    printf("%lld\n", init());
    return 0;
}
