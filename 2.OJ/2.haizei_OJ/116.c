/*************************************************************************
	> File Name: 116.c
	> Author: 
	> Mail: 
	> Created Time: Wed 06 Sep 2023 06:38:14 PM CST
 ************************************************************************/
#include <stdio.h>

#define swap(a, b) { \
	__typeof(a) __a = a; \
	__typeof(b) __b = b; \
	a = __b; \
	b = __a; \
}

#define max(a, b, c) { \
	__typeof(a) __a = a; \
	__typeof(b) __b = b; \
	__typeof(c) __c = c; \
	if (b < c) swap(b, c); \
	if (a < b) swap(a, b); \
}

void f(int a, int b, int c) {
    if (a >= b + c) {
        printf("illegal triangle\n");
        return ;
    }
    if (a * a > b * b + c * c) printf("obtuse triangle\n");
    else if (a * a == b * b + c * c) printf("right triangle\n");
    else printf("acute triangle\n");
    return ;
}

int main() {
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
    max(a, b, c);
    f(a, b, c);
	return 0;
}
