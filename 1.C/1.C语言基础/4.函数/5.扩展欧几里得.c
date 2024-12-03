/*************************************************************************
	> File Name: 5.欧几里得进阶.c
	> Author: 
	> Mail: 
	> Created Time: Wed 05 Jul 2023 06:58:54 PM CST
 ************************************************************************/

/*
求二元一次方程的一组解
ax + by = gcd(a, b)

映射结果
f(x) -> f(x - 1)
x -> y
y -> x - ky
*/

#include<stdio.h>

int ex_gcd(int a, int b, int *x, int *y) {
    //边界条件
    if (b == 0) {
        *x = 1;
        *y = 0;
        return a;
    }
    //递归
    int x1, y1, ret;
    ret = ex_gcd(b, a % b, &x1, &y1);
    *x = y1;
    *y = x1 - a / b * y1;
    return ret;
}

int main() {
    int a, b, x, y;
    while (~scanf("%d%d", &a, &b)) {//a和b互素才有正整数解
        int ret = ex_gcd(a, b, &x, &y);
        printf("x : %d, y = %d\n", x, y);
        printf("%d * %d + %d * %d = %d", a, x, b, y, a * x + b * y);
    }
    return 0;
}
