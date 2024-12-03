/*************************************************************************
	> File Name: 1003.c
	> Author: 
	> Mail: 
	> Created Time: Fri 07 Jul 2023 02:28:25 PM CST
 ************************************************************************/

#include<stdio.h>
#define MAX_N 10000

int binary_search(int *arr, int n) {
    int head = -1, tail = n, mid;
    while (tail - head > 1) {
        mid = (head + tail) >> 1;
        if (arr[mid] & 1  == 1) head = mid;
        else tail = mid;
    }
    if (tail == n) return -1;
    return tail;
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[MAX_N + 5] = {0};
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    printf("%d\n", binary_search(arr, n));
    return 0;
}
