/*************************************************************************
	> File Name: 5.c
	> Author: 
	> Mail: 
	> Created Time: Mon 18 Sep 2023 04:20:47 PM CST
 ************************************************************************/

#include<stdio.h>

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}


int main() {
    int a, b;
    while (~scanf("%d%d", &a, &b)) {
        int ret = gcd(a, b);
        printf("(%d, %d) = %d\n[%d, %d] = %d", a, b, ret, a, b, a * b / ret);
    }    
    return 0;
}
