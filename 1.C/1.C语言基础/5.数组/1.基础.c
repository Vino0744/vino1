/*************************************************************************
	> File Name: 1.基础.c
	> Author: 
	> Mail: 
	> Created Time: Thu 06 Jul 2023 06:18:22 PM CST
 ************************************************************************/

#include<stdio.h>

void output(int (*arr)[100], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            j && printf(" ");
            printf("%d", arr[i][j]);
        }
        printf("\n");
    }
    return ;
}

int main() {
    int arr[2][100], n;
    scanf("%d", &n);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    output(arr, 2, n);
    return 0;
}
