/*************************************************************************
	> File Name: EP-005.c
	> Author: 
	> Mail: 
	> Created Time: Tue 11 Jul 2023 02:28:15 PM CST

Problem 5: Smallest multiple

$2520$ is the smallest number that can be divided by each of the numbers from $1$ to $10$ without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from $1$ to $20$?

 ************************************************************************/

#include<stdio.h>

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    int ans = 2520;
    for (int i = 11; i <= 20; i++) {
        if (ans % i == 0) continue;
        ans = ans / gcd(ans, i) * i;
    }
    printf("%d\n", ans);
    return 0;
}
