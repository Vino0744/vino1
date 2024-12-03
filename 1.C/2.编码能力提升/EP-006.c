/*************************************************************************
	> File Name: EP-006.c
	> Author: 
	> Mail: 
	> Created Time: Mon 10 Jul 2023 11:07:08 PM CST

Problem 6 :

Sum square difference
The sum of the squares of the first ten natural numbers is,

$$1^2+2^2+\ldots +10^2=385$$

The square of the sum of the first ten natural numbers is,

$$(1+2+\ldots+10)^2 = 55^2 = 3025$$

Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is $3025 − 385 = 2640$.

Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.

 ************************************************************************/

#include<stdio.h>

int main() {
    int n = 100;
    int sum1 = (n * (n + 1) * (2 * n + 1) / 6);
    int sum2 = ((1 + n) * n / 2);
    printf("%d\n", sum2 * sum2 - sum1);
    return 0;
}
