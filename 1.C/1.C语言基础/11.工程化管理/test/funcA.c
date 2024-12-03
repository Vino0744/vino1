/*************************************************************************
	> File Name: funcA.c
	> Author: 
	> Mail: 
	> Created Time: Mon 10 Jul 2023 01:41:43 PM CST
 ************************************************************************/

#include<stdio.h>
#include "add.h"

void funcA(int n) {
    printf("funcA: %d + (%d - 1) = %d", n, n, add(n, n - 1));
    return ;
}
