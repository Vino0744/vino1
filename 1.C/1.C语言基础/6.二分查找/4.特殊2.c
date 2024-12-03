/*************************************************************************
	> File Name: 4.特殊2.c
	> Author: 
	> Mail: 
	> Created Time: Fri 07 Jul 2023 02:14:46 PM CST
 ************************************************************************/

//特殊2 查找第一个1
//0 0 0 0 1 1 1 1 1 1

#include<stdio.h>

int binary_search(int *arr, int n) {
    int head = -1, tail = n, mid;
    while (tail - head > 1) {
        mid = (tail + head) >> 1;
        if (arr[mid] == 1) tail = mid;
        else head = mid;
    }
    if (tail == n) return -1;
    return tail;
}

int main() {
    int arr[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    printf("%d\n", binary_search(arr, 10));
    return 0;
}
