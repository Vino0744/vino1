/*************************************************************************
	> File Name: 4.辗转相除法.c
	> Author: 
	> Mail: 
	> Created Time: Wed 05 Jul 2023 06:14:49 PM CST
 ************************************************************************/

//求最小公约数
//gcd(a, b) => gcd(b, a % b)

#include<stdio.h>

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    printf("gcd(%d, %d) = %d\n", a, b, gcd(a, b));
    return 0;
}
