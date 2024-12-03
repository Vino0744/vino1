/*************************************************************************
	> File Name: EP-003.c
	> Author: 
	> Mail: 
	> Created Time: Tue 11 Jul 2023 03:34:51 PM CST

Problem 3: Largest prime factor

The prime factors of $13195$ are $5$, $7$, $13$ and $29$.

What is the largest prime factor of the number $600851475143$?

 ************************************************************************/
#include <math.h>
#include<stdio.h>
#define N 600851475143LL

int main() {
    long long i = 2, ans = 0, sum = N;
    while (i * i <= sum) {
        if (sum % i == 0) ans = i;
        while (sum % i == 0) sum /= i;
        i++;
    }
    if (sum != 1) ans = sum;
    printf("%lld\n", ans);
    return 0;
}
