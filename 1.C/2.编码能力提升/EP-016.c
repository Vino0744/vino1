/*************************************************************************
	> File Name: EP-016.c
	> Author: 
	> Mail: 
	> Created Time: Sun 16 Jul 2023 06:17:49 PM CST

Problem 16: Power digit sum

$2^{15}=32768$ and the sum of its digits is $3 + 2 + 7 + 6 + 8 = 26$.

What is the sum of the digits of the number $2^{1000}$?

 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>

int *get_num(int a, int n) {
    int *arr = (int *)calloc(n + 5, sizeof(int));
    arr[0] = 1;
    arr[1] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= arr[0]; j++) {
            arr[j] *= a;
        }
        for (int k = 1; k <= arr[0]; k++) {
            if (arr[k] < 10) continue;
            arr[k + 1] += arr[k] / 10;
            arr[k] %= 10;
            arr[0] += (k == arr[0]);
        }
    }
    return arr;
}

void output(int *arr) {
    int sum = 0;
    for (int i = arr[0]; i > 0; i--) sum += arr[i];
    printf("%d\n", sum);
    return ;
}

int main() {
    int *num = get_num(2, 1000);
    output(num);
    return 0;
}
