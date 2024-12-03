/*************************************************************************
	> File Name: 915.c
	> Author: 
	> Mail: 
	> Created Time: Thu 06 Jul 2023 10:26:47 PM CST
 ************************************************************************/

#include<stdio.h>
 
int main() {
    int n, arr[37] = {0}, cnt = 0;
    scanf("%d", &n);
    do {
        arr[cnt++] = n % 2;
        n /= 2;
    } while(n);
    for (int i = cnt - 1; i >= 0; i--) printf("%d", arr[i]);
    printf("\n");
    return 0;
}
