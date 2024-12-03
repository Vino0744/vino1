/*************************************************************************
	> File Name: EP-024.c
	> Author: 
	> Mail: 
	> Created Time: Fri 14 Jul 2023 06:24:10 PM CST

Problem 24: Lexicographic permutations

A permutation is an ordered arrangement of objects. For example, $3124$ is one possible permutation of the digits $1$, $2$, $3$ and $4$. If all of the permutations are listed numerically or alphabetically, we call it lexicographic order. The lexicographic permutations of $0$, $1$ and $2$ are:

$$012 \quad 021 \quad 102 \quad 120 \quad 201 \quad 210$$

What is the millionth lexicographic permutation of the digits $0$, $1$, $2$, $3$, $4$, $5$, $6$, $7$, $8$ and $9$

 ************************************************************************/

#include<stdio.h>
#define MAX_N 1000000

int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

int f(int n) {
    int sum = 1;
    for (int i = 1; i <= n; i++) sum *= i;
    return sum;
}

int get_p(int n) {
    for (int i = 1; i < 10; i++) {
        if (n >= f(i) && n < f(i + 1)) return i;
    }
}

void round_arr(int p, int x) {
    p = 9 - p;
    int k = arr[p + x];
    for (int i = p + x; i >= p + 1; i--) {
        arr[i] = arr[i - 1];
    }
    arr[p] = k;
    return ;
}

void output() {
    for (int i = 0; i < 10; i++) printf("%d", arr[i]);
    printf("\n");
    return ;
}

int main() {
    int n = MAX_N - 1;
    while (n) {
        int p = get_p(n);
        round_arr(p, (n / f(p)));
        n %= f(p);
    }
    output();
    return 0;
}
