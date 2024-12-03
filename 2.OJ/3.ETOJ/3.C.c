/*************************************************************************
	> File Name: 4.D.c
	> Author: 
	> Mail: 
	> Created Time: Tue 19 Sep 2023 11:45:18 AM CST
 ************************************************************************/

#include<stdio.h>

#define N 1000
int arr[N + 5][N + 5], prefix[N + 5][N + 5];

int main() {
    int m, n, a, q;
    scanf("%d %d %d", &n, &m, &q);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &a);
            arr[i][j] = a;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            prefix[i][j] += arr[i][j];
            prefix[i][j + 1] += prefix[i][j];
            prefix[i + 1][j] += prefix[i][j];
            prefix[i + 1][j + 1] -= prefix[i][j];
        }
    }
    int x1, x2, y1, y2;
    for (int i = 0; i < q; i++) {
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        printf("%d\n", (prefix[x2][y2] - prefix[x1 - 1][y2] - prefix[x2][y1 - 1] + prefix[x1 - 1][y1 - 1]));
    }
    return 0;
}
