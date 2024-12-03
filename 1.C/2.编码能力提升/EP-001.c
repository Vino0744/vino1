/*************************************************************************
	> File Name: EP-001.c
	> Author: 
	> Mail: 
	> Created Time: Mon 10 Jul 2023 07:47:57 PM CST

Problem :

Multiples of $3$ or $5$
If we list all the natural numbers below $10$ that are multiples of $3$ or $5$, we get $3$, $5$, $6$ and $9$. The sum of these multiples is $23$.

Find the sum of all the multiples of $3$ or $5$ below $1000$.

 ************************************************************************/

#include <stdio.h>

int main() {
    int sum3 = (3 + 999) * (999 / 3) / 2;
    int sum5 = (5 + 995) * (999 / 5) / 2;
    int sum15 = (15 + 999 / 15 * 15) * (999 / 15) / 2;
    printf("%d\n", sum3 + sum5 - sum15);
    return 0;
}
