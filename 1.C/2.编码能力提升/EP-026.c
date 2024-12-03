/*************************************************************************
	> File Name: EP-026.c
	> Author: 
	> Mail: 
	> Created Time: Fri 14 Jul 2023 01:04:21 PM CST

Problem 26: Reciprocal cycles

A unit fraction contains $1$ in the numerator. The decimal representation of the unit fractions with denominators $2$ to $10$ are given:

$$\begin{aligned}
1/2 &= 0.5\\
1/3 &= 0.(3)\\
1/4 &= 0.25\\
1/5 &= 0.2\\
1/6 &= 0.1(6)\\
1/7 &= 0.(142857)\\
1/8 &= 0.125\\
1/9 &= 0.(1)\\
1/10 &= 0.1\\
\end{aligned}$$

Where $0.1(6)$ means $0.166666\ldots$, and has a $1$-digit recurring cycle. It can be seen that $1/7$ has a $6$-digit recurring cycle.

Find the value of $d<1000$ for which $1/d$ contains the longest recurring cycle in its decimal fraction part.

 ************************************************************************/

#include <stdio.h>
#include <string.h>
#define MAX_N 1000

int keep[MAX_N] = {0};

int get_len(int x) {
    memset(keep, 0, sizeof(keep));
    int r = 1, t = 1;
    keep[1] = 1;
    while (r) {
        r *= 10;
        r %= x;
        t += 1;
        if (keep[r]) return t - keep[r];
        keep[r] = t;
    }
    return 0;
}

int main() {
    int d = 0, len = 0;
    for (int i = 2; i < MAX_N; i++) {
        int temp = get_len(i);
        if (temp < len) continue;
        len = temp;
        d = i;
    }
    printf("%d, len : %d\n", d, len);
    return 0;
}
