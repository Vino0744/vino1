/*************************************************************************
	> File Name: EP-038.c
	> Author: 
	> Mail: 
	> Created Time: Fri 14 Jul 2023 03:21:11 PM CST

Problem 38: Pandigital multiples
Take the number $192$ and multiply it by each of $1$, $2$, and $3$:

$192 × 1 = 192$

$192 × 2 = 384$

$192 × 3 = 576$

By concatenating each product we get the $1$ to $9$ pandigital, $192384576$. We will call $192384576$ the concatenated product of $192$ and $(1,2,3)$

The same can be achieved by starting with $9$ and multiplying by $1$, $2$, $3$, $4$, and $5$, giving the pandigital, $918273645$, which is the concatenated product of $9$ and $(1,2,3,4,5)$.

What is the largest $1$ to $9$ pandigital 9-digit number that can be formed as the concatenated product of an integer with $(1,2, … ,n)$ where $n>1$?

 ************************************************************************/

#include <stdio.h>
#include <math.h>
#define MAX_N 10000

int get_digit(int n) {
    return floor(log10(n)) + 1;
}

int calc(int x) {
    int n = 1, ans = 0;
    while (get_digit(ans) < 9) {
        ans *= (int)pow(10, get_digit(x * n));
        ans += x * n;
        n += 1;
    }
    if (get_digit(ans) != 9) return 0;
    int num[10] = {0};
    num[0] = 1;
    int temp = ans;
    while (temp) {
        if (num[temp % 10]) return 0;
        num[temp % 10] = 1;
        temp /= 10;
    }
    return ans;
}

int main() {
    int ans = 0;
    for (int i = 1; i < MAX_N; i++) {
        int temp = calc(i);
        if (ans < temp) ans = temp;
    }
    printf("%d\n", ans);
    return 0;
}
