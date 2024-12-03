/*************************************************************************
	> File Name: EP-047.c
	> Author: 
	> Mail: 
	> Created Time: Thu 13 Jul 2023 02:42:39 PM CST

Problem 47: Distinct primes factors

The first two consecutive numbers to have two distinct prime factors are:
$$
\begin{aligned}
14 &= 2 × 7 \\
15 &= 3 × 5
\end{aligned}
$$

The first three consecutive numbers to have three distinct prime factors are:
$$
\begin{aligned}
644 &= 2^2 × 7 × 23 \\
645 &= 3 × 5 × 43 \\
646 &= 2 × 17 × 19
\end{aligned}
$$

Find the first four consecutive integers to have four distinct prime factors. What is the first of these numbers?

 ************************************************************************/

#include<stdio.h>
#define MAX_N 1000000

int prime[MAX_N + 5] = {0};
void init() {
    for (int i = 2; i <= MAX_N; i++) {
        if (!prime[i]) {
            prime[i] = 1;
            for (int j = 2; j <= MAX_N / i; j++) {
                prime[i * j] += 1;
            }
        }
    }
    return ;
}

int is_val() {
    for (int i = 1; i <= MAX_N - 3; i++) {
        if (prime[i] == 4 && prime[i + 1] == 4 && prime[i + 2] == 4 && prime[i + 3] == 4) return i;
    }
    return 0;
}

int main() {
    init();
    printf("%d\n", is_val());
    return 0;
}
