/*************************************************************************
	> File Name: 3.特殊1.c
	> Author: 
	> Mail: 
	> Created Time: Fri 07 Jul 2023 01:54:56 PM CST
 ************************************************************************/

//特殊情况
//0 0 0 0 0 0 0 0 1 1 1 1 1 1 1 1
//找最后一个0

#include<stdio.h>

int binary_search(int *arr, int n) {
    int head = -1, tail = n - 1, mid;
    while (tail - head > 1) {
        mid = (head + tail) >> 1;
        if (arr[mid] == 0) head = mid;
        else tail = mid;
    }
    return head;
}

int main() {
    int arr[11] = {0, 0, 0, 0, 0};
    printf("%d\n", binary_search(arr, 5));
    return 0;
}
