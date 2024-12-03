/*************************************************************************
	> File Name: 192.c
	> Author: 
	> Mail: 
	> Created Time: Fri 07 Jul 2023 10:05:05 AM CST
 ************************************************************************/

#include<stdio.h>
#include <math.h>

double f(double x) {
    return x * exp(x);
}

double slove(int a) {
    #define EPL 1e-6
    double head = 0, tail = a, mid;
    while (tail - head > EPL) {
        mid = (tail + head) / 2;
        if (f(mid) < a) head = mid;
        else tail = mid;
    }
    #undef EPL
    return head;
}

int main() {
    int a;
    scanf("%d", &a);
    printf("%.4lf\n", slove(a));
    return 0;
}
