/*************************************************************************
	> File Name: 7.G.c
	> Author: 
	> Mail: 
	> Created Time: Thu 21 Sep 2023 01:01:04 PM CST
 ************************************************************************/

#include<stdio.h>

void f(long long n) {
    long long ret = 0;
    while (n) {
        if (n & 1) ret += 1;
        n >>= 1;
    }
    printf("%lld ", ret);
}

int main() {
    int n;
    scanf("%d", &n);
    long long a;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a);
        f(a);
    }
    return 0;
}
