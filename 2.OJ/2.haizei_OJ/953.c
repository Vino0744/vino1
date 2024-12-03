/*************************************************************************
	> File Name: 953.c
	> Author: 
	> Mail: 
	> Created Time: Thu 06 Jul 2023 11:18:22 AM CST
 ************************************************************************/

#include<stdio.h>
#include <inttypes.h>

int ret = INT32_MIN;

int max(int n) {
    if (n == 0) return ret;
    int x;
    scanf("%d", &x);
    if (x > ret) ret = x;
    max(n - 1);
    return ret;
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", max(n));
    return 0;
}
