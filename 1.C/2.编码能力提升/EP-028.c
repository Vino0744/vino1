/*************************************************************************
	> File Name: EP-028.c
	> Author: 
	> Mail: 
	> Created Time: Tue 11 Jul 2023 03:13:57 PM CST

Problem 28: Number spiral diagonals

Starting with the number $1$ and moving to the right in a clockwise direction, a $5$ by $5$ spiral is formed as follows:

21 22 23 24 25
20  7  8  9 10
19  6  1  2 11
18  5  4  3 12
17 16 15 14 13
It can be verified that the sum of the numbers on the diagonals is $101$.

What is the sum of the numbers on the diagonals in a $1001$ by $1001$ spiral formed in the same way?

 ************************************************************************/

#include<stdio.h>
#define MAX_N 500

int init() {
    int sum = 1, k = 1;
    for (int i = 1; i <= MAX_N; i++) {
        for (int j = 1; j <= 4; j++) {
            k += 2 * i;
            sum += k;
        }
    }
    return sum; 
}

int main() {
    printf("%d\n", init());
    return 0;
}
