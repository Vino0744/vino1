/*************************************************************************
	> File Name: 2.bubble_sort.c
	> Author: 
	> Mail: 
	> Created Time: Tue 01 Aug 2023 09:10:40 PM CST
 ************************************************************************/

#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include "sort_test.h"

void bubble_sort(int *arr, int l, int r) {
    int flag = 1;
    for (int i = l; flag && i < r - 1; i++) {
        flag = 0;
        for (int j = l; j < r - i - 1; j++) {
            if (arr[j] <= arr[j + 1]) continue;
            swap(arr[j], arr[j + 1]);
            flag = 1;
        }
    }
    return ;
}

int main() {
    int *arr = getRandData(SMALL_DATA_N);
    test(bubble_sort, arr, SMALL_DATA_N);
    return 0;
}
