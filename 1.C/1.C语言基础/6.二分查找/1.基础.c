/*************************************************************************
	> File Name: 1.基础.c
	> Author: 
	> Mail: 
	> Created Time: Thu 06 Jul 2023 11:16:07 PM CST
 ************************************************************************/

//二分前提 单调
//找到的结果在原数组内是相同的数字中随机的

#include<stdio.h>

int binary_search(int *arr, int n, int val) {
    int head = 0, tail = n - 1, mid;
    while (head <= tail) {
        mid = (head + tail) >> 1;
        if (arr[mid] == val) return mid;
        if (arr[mid] > val) tail = mid - 1;
        else head = mid + 1;
    }
    return -1;
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", arr + i);
    int x;
    scanf("%d", &x);
    printf("%d\n", binary_search(arr, n, x));
    return 0;
}
