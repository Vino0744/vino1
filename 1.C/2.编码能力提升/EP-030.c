/*************************************************************************
	> File Name: EP-030.c
	> Author: 
	> Mail: 
	> Created Time: Mon 10 Jul 2023 11:27:39 PM CST

Problem 30 :

Digit fifth powers
Surprisingly there are only three numbers that can be written as the sum of fourth powers of their digits:
$$1634=1^4+6^4+3^4+4^4$$
$$8208=8^4+2^4+0^4+8^4$$
$$9474=9^4+4^4+7^4+4^4$$

As $1 = 1^4$ is not a sum it is not included.

The sum of these numbers is $1634 + 8208 + 9474 = 19316$.

Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.

 ************************************************************************/

#include <stdio.h>
#include <math.h>

int is_point(int n) {
    int x = n, sum = 0;
    while (x) {
        sum += pow(x % 10, 5);
        x /= 10;
    }
    return sum == n;
}

int main() {
    int sum = 0;
    for (int i = 2; i <= pow(9, 5) * 6; i++) {
        if (!is_point(i)) continue;
        sum += i;
    }
    printf("%d\n", sum);
    return 0;
}
