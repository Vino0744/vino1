/*************************************************************************
	> File Name: 2.解方程.c
	> Author: 
	> Mail: 
	> Created Time: Fri 07 Jul 2023 08:16:07 AM CST
 ************************************************************************/

#include <stdio.h>
#include <math.h>

double my_sqrt(double n) {
    #define EPSL 1e-6
    double head = 0, tail = n + 1, mid;
    while (tail - head > EPSL) {
        mid = (head + tail) / 2;
        if (mid * mid < n) head = mid;
        else tail = mid;
    }
    #undef EPSL
    return tail;
}

int main() {
    double n;
    while (~scanf("%lf", &n)) {
        printf("sqrt(%g) = %g\n", n, sqrt(n));
        printf("sqrt(%g) = %g\n", n, my_sqrt(n));
    }
    return 0;
}
