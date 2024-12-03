/*************************************************************************
	> File Name: EP-015.c
	> Author: 
	> Mail: 
	> Created Time: Tue 11 Jul 2023 04:00:03 PM CST

Problem 15: Lattice paths

Starting in the top left corner of a $2\times2$ grid, and only being able to move to the right and down, there are exactly $6$ routes to the bottom right corner.

How many such routes are there through a $20\times20$ grid?

 ************************************************************************/
//排列组合 C42

#include<stdio.h>

int main() {
    long long n = 40;
    for (int i = 39, I = 2; i > 20; i--, I++) n = n * i / I;
    printf("%lld\n", n);
    return 0;
}
