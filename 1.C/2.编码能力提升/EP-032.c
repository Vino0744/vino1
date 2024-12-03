/*************************************************************************
	> File Name: EP-032.c
	> Author: 
	> Mail: 
	> Created Time: Fri 14 Jul 2023 10:18:16 PM CST

Problem 32: Pandigital products

We shall say that an $n$-digit number is pandigital if it makes use of all the digits $1$ to $n$ exactly once; for example, the $5$-digit number, $15234$, is $1$ through $5$ pandigital.

The product $7254$ is unusual, as the identity, $39\times186 = 7254$, containing multiplicand, multiplier, and product is $1$ through $9$ pandigital.

Find the sum of all products whose multiplicand/multiplier/product identity can be written as a $1$ through $9$ pandigital.

HINT: Some products can be obtained in more than one way so be sure to only include it once in your sum.

 ************************************************************************/

#include<stdio.h>
#include <math.h>
#define MAX_N 10000

int arr[10000] = {0};

int digit (int n) {
    return floor(log10(n)) + 1;
}

int add_num(int n, int *num) {
    while (n) {
        if (num[n % 10]) return 0;
        num[n % 10] = 1;
        n /= 10;
    }
    return 1;
}
    
int is_val(int a, int b, int c) {
    if (digit(a) + digit(b) + digit(c) != 9) return 0;
    int num[10] = {0};
    num[0] = 1;
    int flag = 1;
    flag = flag && add_num(a, num);
    flag = flag && add_num(b, num);
    flag = flag && add_num(c, num);
    return flag;
}

int main() {
    int sum = 0;
    for (int a = 1; a < 100; a++) {
        for (int b = a + 1; b < MAX_N; b++) {
            if (!is_val(a, b, a * b) || arr[a * b]) continue;
            arr[a * b] = 1;
            sum += a * b;
        }
    }
    printf("%d\n", sum);
    return 0;
}
