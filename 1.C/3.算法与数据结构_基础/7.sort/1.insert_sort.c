/*************************************************************************
	> File Name: 1.insert_sort.c
	> Author: 
	> Mail: 
	> Created Time: Tue 01 Aug 2023 10:26:22 AM CST
 ************************************************************************/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "sort_test.h"

void insert_sort(int *arr, int l, int r) {
    for (int i = l + 1; i < r; i++) {
        for (int j = i; j > l && arr[j] < arr[j - 1]; j--) {
            swap(arr[j], arr[j - 1]);
        }
    }
    return ;
}

int main() {
    int *arr = getRandData(SMALL_DATA_N);
    test(insert_sort, arr, SMALL_DATA_N);
    return 0;
}
