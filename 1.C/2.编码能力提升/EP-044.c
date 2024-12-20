/*************************************************************************
	> File Name: EP-044.c
	> Author: 
	> Mail: 
	> Created Time: Sat 15 Jul 2023 02:44:17 PM CST

Problem 44: Pentagon numbers

Pentagonal numbers are generated by the formula, $P_n=n(3n−1)/2$. The first ten pentagonal numbers are:

$$1, 5, 12, 22, 35, 51, 70, 92, 117, 145, \ldots $$

It can be seen that $P_4 + P_7 = 22 + 70 = 92 = P_8$. However, their difference, $70 − 22 = 48$, is not pentagonal.

Find the pair of pentagonal numbers, $P_j$ and $P_k$, for which their sum and difference are pentagonal and $D = |P_k − P_j|$ is minimised; what is the value of $D$?

 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>

typedef long long lint;

lint f(lint n) {
    return n * (3 * n - 1) >> 1;
}

lint is_val(lint x, lint n) {
    lint head = 1, tail = n, mid;
    while (head <= tail) {
        mid = (head + tail) >> 1;
        if (f(mid) == x) return 1;
        if (f(mid) < x) head = mid + 1;
        else tail = mid - 1;
    }
    return 0;
}

int main() {
    lint ans = INT32_MAX, i = 1, j = 1;
    while (f(j + 1) - f(j) < ans) {
        j += 1;
        i = j - 1;
        for (; i >= 1 && f(j) - f(i) < ans; i--) {
            lint I = f(i), J = f(j);
            if (!is_val(J + I, 2 * j)) continue;
            if (!is_val(J - I, 2 * i)) continue;
            printf("%lld ---> %lld\n", J, I);
            ans = J - I;
        }
    }
    printf("ans = %lld\n", ans);
    return 0;
}
