/*************************************************************************
	> File Name: 4.D.c
	> Author: 
	> Mail: 
	> Created Time: Tue 19 Sep 2023 08:38:43 PM CST
 ************************************************************************/

#include<stdio.h>

#define N 1000
int arr[N + 5][N + 5], prefix[N + 5][N + 5], diff[N + 5][N + 5];

int main() {
    int m, n, q, a;
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &a);
            arr[i][j] = a;
        }
    }
    //初始差分数组
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            diff[i][j] += arr[i][j];
            diff[i][j + 1] -= arr[i][j];
            diff[i + 1][j] -= arr[i][j];
            diff[i + 1][j + 1] += arr[i][j];
        }
    }
    int x1, x2, y1, y2, c;
    for (int i = 0; i < q; i++) {
        scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &c);
        diff[x1][y1] += c;
        diff[x1][y2 + 1] -= c;
        diff[x2 + 1][y1] -= c;
        diff[x2 + 1][y2 + 1] += c;
    }
    //还原arr数组
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            diff[i + 1][j] += diff[i][j];
            diff[i][j + 1] += diff[i][j];
            diff[i + 1][j + 1] -= diff[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            printf("%d ", diff[i][j]);
        }
        printf("\n");
    }
    return 0;
}
