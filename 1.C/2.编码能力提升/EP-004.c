/*************************************************************************
	> File Name: EP-004.c
	> Author: 
	> Mail: 
	> Created Time: Mon 10 Jul 2023 10:27:08 PM CST

Problem 4:

Largest palindrome product
A palindromic number reads the same both ways. The largest palindrome made from the product of two $2$-digit numbers is $9009 = 91 \times 99$.

Find the largest palindrome made from the product of two $3$-digit numbers.

 ************************************************************************/

#include <stdio.h>

int is_reverse(int n) {
    int x = n, sum = 0;
    while (x) {
        sum = sum * 10 + x % 10;
        x /= 10;
    }
    return sum == n;
}

int main() {
    int ans = 0;
    for (int a = 100; a < 1000; a++) {
        for (int b = a; b < 1000; b++) {
            if (is_reverse(a * b) && a * b > ans) ans = a * b;
        }
    }
    printf("%d\n", ans);
    return 0;
}
