/*************************************************************************
	> File Name: 2.B.c
	> Author: 
	> Mail: 
	> Created Time: Sun 17 Sep 2023 11:03:47 PM CST
 ************************************************************************/

#include<stdio.h>

#define N 100000

long long arr[N + 5], diff[N + 5];

int main() {
    long long n, m, q, l, r, x, a;
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a);
        arr[i] = a;
    }
    for (int i = 1; i <= n; i++) diff[i] = arr[i] - arr[i - 1];
    scanf("%lld", &m);
    for(int i = 0; i < m; i++) {
        scanf("%lld %lld %lld", &l, &r, &x);
        diff[l] += x;
        diff[r + 1] -= x;
    }
    for (int i = 1; i <= n; i++) arr[i] = arr[i - 1] + diff[i];
    for (int i = 1; i <= n; i++) arr[i] += arr[i - 1];
    scanf("%lld", &q);
    for (int i = 0; i < q; i++) {
        scanf("%lld %lld", &l, &r);
        printf("%lld\n", arr[r] - arr[l - 1]);
    }
    return 0;
}
