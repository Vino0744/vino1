/*************************************************************************
	> File Name: 3.merge_sort.c
	> Author: 
	> Mail: 
	> Created Time: Tue 01 Aug 2023 09:58:13 PM CST
 ************************************************************************/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "sort_test.h"

void merge_sort(int *arr, int l, int r) {
    if (r - l <= 2) {
        if (r - l <= 1) return ;
        if (arr[l] > arr[l + 1]) swap(arr[l], arr[l + 1]);
        return ;
    }
    int mid = (r + l) >> 1;
    merge_sort(arr, l, mid);
    merge_sort(arr, mid, r);
    int *temp = (int *)malloc(sizeof(int) * (r - l));
    int k1 = l, k2 = mid, k = 0;
    while (k1 < mid || k2 < r) {
        if (k2 == r || (k1 < mid && arr[k1] <= arr[k2])) temp[k++] = arr[k1++];
        else temp[k++] = arr[k2++];
    }
    memcpy(arr + l, temp, sizeof(int) * (r - l));
    free(temp);
    return ;
}

int main() {
    int *arr = getRandData(BIG_DATA_N);
    test(merge_sort, arr, BIG_DATA_N);
    return 0;
}
