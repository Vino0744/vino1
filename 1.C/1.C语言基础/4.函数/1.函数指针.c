/*************************************************************************
	> File Name: 1.函数指针.c
	> Author: 
	> Mail: 
	> Created Time: Tue 04 Jul 2023 06:38:39 PM CST
 ************************************************************************/

#include<stdio.h>
#include <math.h>

/*
* x <= 0, y = -1;
* x > 0 && x <100, y = x + 1;
* x >= 100, y = sqrt(x);
*/

int func1() {
    return -1;
}

int func2(int x) {
    return x + 1;
}

double func3(int x) {
    return sqrt(x);
}

double output(int (*f1)(), int (*f2)(int), double (*f3)(int),  int x) {
    if (x <= 0) {
        printf("func1 : ");
        return f1();
    } else if (x > 0 && x < 100) {
        printf("func2 : ");
        return f2(x);
    }
    printf("func3 : ");
    return f3(x);
} 

int main() {
    int x;
    while (~scanf("%d", &x)) {
        printf("%g\n", output(func1, func2, func3, x));
    }
    return 0;
}
