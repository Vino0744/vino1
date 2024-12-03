/*************************************************************************
	> File Name: 179.c
	> Author: 
	> Mail: 
	> Created Time: Fri 07 Jul 2023 09:51:32 AM CST
 ************************************************************************/
#include <stdio.h>
#include <math.h>
#define EPSILON 1e-7

double bisection(int p, int q, double (*func)(int, int, double));
double f(int p, int q, double x);
int main() {
    int p;
    int q;
    scanf("%d %d", &p, &q);
    printf("%.4lf\n", bisection(p, q, f));
    return 0;
}

double bisection(int p, int q, double (*func)(int, int, double)) {
    double head = -20, tail = 20, mid;
    do {
        mid = (head + tail) / 2;
        if (func(p, q, head) * func(p, q, mid) < 0) tail = mid;
        else head = mid;
    } while (fabs(func(p, q, mid)) > EPSILON);
    return mid;
}

double f(int p, int q, double x) {
    return p * x + q;
}
