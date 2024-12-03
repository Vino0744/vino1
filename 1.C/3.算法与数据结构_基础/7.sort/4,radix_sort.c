/*************************************************************************
	> File Name: 4,radix_sort.c
	> Author: 
	> Mail: 
	> Created Time: Tue 01 Aug 2023 11:20:41 PM CST
 ************************************************************************/

#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include "sort_test.h"

void radix_sort(int *arr, int l, int r) {
    #define exp 65526//2^16
    int n = r - l;
    int count[exp] = {0};
    int *temp = (int *)malloc(sizeof(int) * n);
    //round 1
    for (int i = l; i < r; i++) count[(arr[i] % exp)] += 1;
    for (int i = 1; i < exp; i++) count[i] += count[i - 1];
    for (int p = r - 1; p >= 0; p--) temp[count[arr[p] % exp]--] = arr[p] % exp;
    memcpy(arr, temp, sizeof(int) * n);
    //round 2
    for (int i = l; i < r; i++) count[(arr[i] / exp)] += 1;
    for (int i = 1; i < exp; i++) count[i] += count[i - 1];
    for (int p = r - 1; p >= 0; p--) temp[count[arr[p] / exp]--] = arr[p] / exp;
    memcpy(arr, temp, sizeof(int) * n);
    free(temp);
    return ;
}

int main() {
    int *arr = getRandData(BIG_DATA_N);
    test(radix_sort, arr, BIG_DATA_N);
    return 0;
}
