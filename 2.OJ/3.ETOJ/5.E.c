/*************************************************************************
	> File Name: 5.E.c
	> Author: 
	> Mail: 
	> Created Time: Tue 19 Sep 2023 10:21:30 PM CST
 ************************************************************************/

#include<stdio.h>
#include <limits.h>

#define N 100000
long long arr[N + 5], weight[N + 5], prefix[N + 5];

#define max(a, b) (a) > (b) ? (a) : (b)
#define min(a, b) (a) < (b) ? (a) : (b)

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        long long n, a, ret = 0, max = LLONG_MIN, min = 0;
        scanf("%lld", &n);
        for (int j = 1; j <= n; j++) {
            scanf("%lld", &a);
            arr[j] = a;
        }
        for (int j = 1; j <= n; j++) {
            scanf("%lld", &a);
            weight[j] = a;
            prefix[j] = prefix[j - 1] + (arr[j] ? -1 : 1) * weight[j];
            ret += weight[j] * arr[j];
        }
        //for (int j = 1; j <= n; j++) printf("%lld ", prefix[j]);
        
        long long mi = 0, fix = 0;
        for (int j = 1; j <= n; j++) {
            fix = max(fix, (prefix[j] - mi));
            mi = min(mi, prefix[j]);
        }
        
        ret += fix;
        printf("%lld\n", ret);
    }
    return 0;
}
