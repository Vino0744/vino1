/*************************************************************************
	> File Name: 3.指针.c
	> Author: 
	> Mail: 
	> Created Time: Sun 09 Jul 2023 12:35:14 PM CST
 ************************************************************************/

#include<stdio.h>

#define P(func) { \
    printf("%s = %d\n", #func, func); \
}

struct data {
    int x, y;
};

int main() {
    struct data a[2], *p = a;
    a[0].x = 0, a[0].y = 1;
    a[1].x = 2, a[1].y = 3;
    //表示a[1].x
    P((p + 1)->x);
    P((*(p + 1)).x);
    P((a + 1)->x);
    P((*(a + 1)).x);
    P(a[1].x);
    P((&a[1])->x);
    P((&(a[0]) + 1)->x);
    P((*(&(a[0]) + 1)).x);
    P(((&a[0] + 1)[0]).x);
    return 0;
}
