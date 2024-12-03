/*************************************************************************
	> File Name: EP-14.c
	> Author: 
	> Mail: 
	> Created Time: Thu 13 Jul 2023 08:49:53 PM CST

Problem 14: Longest Collatz sequence

The following iterative sequence is defined for the set of positive integers:

$n \rightarrow n/2$ ($n$ is even)

$n \rightarrow 3n + 1$ ($n$ is odd)

Using the rule above and starting with $13$, we generate the following sequence:

$$13 \rightarrow 40 \rightarrow 20 \rightarrow 10 \rightarrow 5 \rightarrow 16 \rightarrow 8 \rightarrow 4 \rightarrow 2 \rightarrow 1$$

It can be seen that this sequence (starting at $13$ and finishing at $1$) contains $10$ terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at $1$.

Which starting number, under one million, produces the longest chain?

NOTE: Once the chain starts the terms are allowed to go above one million.
 
 ************************************************************************/

#include<stdio.h>
#define MAX_N 1000000

int keep[MAX_N + 5] = {0};

long long get_len(long long n) {
    if (n == 1) return 1;
    if (n <= MAX_N && keep[n]) return keep[n];
    int ret = (n & 1) ? get_len(3 * n + 1) : get_len(n >> 1);
    ret += 1;
    if (n <= MAX_N) keep[n] = ret;
    return ret;
}

int main() {
    long long ans = 0, len = 0;
    for (int i = 1; i <= MAX_N; i++) {
        long long l = get_len(i);
        if (l < len) continue;
            len = l;
            ans = i;
    }
    printf("val : %lld, len : %lld\n", ans, len);
    return 0;
}
