/*************************************************************************
	> File Name: EP-046.c
	> Author: 
	> Mail: 
	> Created Time: Wed 12 Jul 2023 09:18:15 PM CST

Problem 46: Goldbach’s other conjecture

It was proposed by Christian Goldbach that every odd composite number can be written as the sum of a prime and twice a square.

$9 = 7 + 2\times 1^2$

$15 = 7 + 2\times 2^2$

$21 = 3 + 2\times 3^2$

$25 = 7 + 2\times 3^2$

$27 = 19 + 2\times 2^2$

$33 = 31 + 2\times 1^2$

It turns out that the conjecture was false.

What is the smallest odd composite that cannot be written as the sum of a prime and twice a square?

 ************************************************************************/

#include <stdio.h>
#define MAX_N 100000

int prime[MAX_N] = {0};
int is_prime[MAX_N] = {1, 1};

int func(int x) {
    return 2 * x * x;
}

int binary_search(int (*f)(int), int head, int tail, int val) {
    int mid;
    while (head <= tail) {
        mid = (head + tail) >> 1;
        if (f(mid) == val) return 1;
        else if (f(mid) < val) head = mid + 1;
        else tail = mid - 1;
    }
    return 0;
}

int is_val(int n) {
    for (int i = 1; i <= prime[0] && prime[i] < n; i++) {
        int val = n - prime[i];
        if (binary_search(func, 1, val, val)) return 1;
    }
    return 0;
}

void init() {
    for (int i = 2; i <= MAX_N; i++) {
        if (!is_prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0]; j++) {
            if (prime[j] * i > MAX_N) break;
            is_prime[prime[j] * i] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    return ;
}

int main() {
    init();
    for (int i = 11; i <= MAX_N; i += 2) {
        if (is_prime[i] == 0) continue;
        if (is_val(i)) continue;
        printf("%d\n", i);
        break;
    }
    return 0;
}
