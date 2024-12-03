/*************************************************************************
	> File Name: 8.H.c
	> Author: 
	> Mail: 
	> Created Time: Thu 21 Sep 2023 01:12:55 PM CST
 ************************************************************************/

#include<stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int a, t, ret = 0;
        scanf("%d", &t);
        for (int j = 0; j < t; j++) {
            scanf("%d", &a);
            ret ^= a;
        }
        printf("%d\n", ret);
    }
    return 0;
}
