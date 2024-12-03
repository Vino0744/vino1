/*************************************************************************
	> File Name: 5.select_sort.c
	> Author: 
	> Mail: 
	> Created Time: Wed 02 Aug 2023 02:44:54 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "sort_test.h"

void select_sort(int *arr, int l, int r) {
    for (int i = l; i < r - 1; i++) {
        int ind = i;
        for (int j = i + 1; j < r; j++) {
            if (arr[ind] > arr[j]) ind = j;
        }
        swap(arr[i], arr[ind]);
    }
    return ;
}

int main() {
    int *arr = getRandData(SMALL_DATA_N);
    test(select_sort, arr, SMALL_DATA_N);
    return 0;
}
