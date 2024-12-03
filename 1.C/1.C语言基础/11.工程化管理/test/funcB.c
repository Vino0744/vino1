/*************************************************************************
	> File Name: funcB.c
	> Author: 
	> Mail: 
	> Created Time: Mon 10 Jul 2023 01:44:06 PM CST
 ************************************************************************/

#include<stdio.h>
#include "add.h"

void funcB(int n) {
    printf("funcB: %d + 1 = %d", n, add(n, 1));
    return ;
}
