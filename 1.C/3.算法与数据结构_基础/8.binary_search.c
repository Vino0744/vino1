/*************************************************************************
	> File Name: 8.binary_search.c
	> Author: 
	> Mail: 
	> Created Time: Wed 02 Aug 2023 09:44:44 PM CST
 ************************************************************************/

#include<stdio.h>

int binary_search(int *arr, int l, int r, int val) {
    while (r >= l) {
        int mid = (l + r) >> 1;
        if (arr[mid] == val) return mid;
        if (arr[mid] > val) r = mid - 1;
        else l = mid + 1;
    }
    return -1;
}

int binary_search_special01(int *arr, int n) {
    int head = 0, tail = n - 1, mid;
    while (head <= tail) {
        if (head == tail && arr[head] == 1) return head;
        else if (head == tail && arr[head] != 1) return -1;
        mid = (head + tail) >> 1;
        if (arr[mid] == 0) head = mid + 1;
        else tail = mid;
    }
    return -1;
}

int binary_search_special10(int *arr, int n) {
    int head = 0, tail = n - 1, mid;
    while (head <= tail) {
        if (head == tail && arr[head] == 1) return head;
        else if (head == tail && arr[head] == 0) return -1;
        mid = (head + tail) / 2 + 1;
        if (arr[mid] == 1) head = mid;
        else tail = mid - 1;
    }
    return -1;
}

int main() {

    int test1[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int test2[10] = {0, 0, 0 ,0, 1, 1, 1, 1, 1, 1};
    int test3[10] = {1, 1, 1, 1, 0, 0, 0, 0, 0, 0};
    int test4[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int test5[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

    printf("7 : %d\n", binary_search(test1, 0, 9, 7));
    printf("4 : %d\n", binary_search_special01(test2, 10));
    printf("-1 : %d\n", binary_search_special01(test4, 10));
    printf("0 : %d\n", binary_search_special01(test5, 10));
    printf("3 : %d\n", binary_search_special10(test3, 10));
    printf("-1 : %d\n", binary_search_special10(test4, 10));
    printf("9 : %d\n", binary_search_special10(test5, 10));
    return 0;
}
