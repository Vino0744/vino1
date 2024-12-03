/*************************************************************************
	> File Name: 997.c
	> Author: 
	> Mail: 
	> Created Time: Tue 04 Jul 2023 08:16:29 PM CST
 ************************************************************************/

#include<stdio.h>

#define MAX_N 100000

int binary_search(int *arr, int n, int x) {
    int l = 0, r = n - 1, mid;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (arr[mid] == x) return mid;
        else if (arr[mid] < x) r = mid - 1;
        else l = mid + 1;
    }
    return 0;
}

int main() {
    int arr[MAX_N + 5] = {0}, x, n, y;
    scanf("%d%d", &n, &x);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    printf("%d\n", binary_search(arr, n, x));
    return 0;
}
