/*************************************************************************
	> File Name: 1.A.c
	> Author: 
	> Mail: 
	> Created Time: Sun 17 Sep 2023 10:08:39 PM CST
 ************************************************************************/

#include<stdio.h>

#define N 100000

int arr[N];

int main() {
    int n, q, l, r, a;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a);
        arr[i] = a;
    }
    for (int i = 1; i <= n; i++) arr[i] += arr[i - 1];
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        scanf("%d%d", &l, &r);
        printf("%d\n", arr[r] - arr[l - 1]);
    }
    return 0;
}
