/*************************************************************************
	> File Name: EP-020.c
	> Author: 
	> Mail: 
	> Created Time: Sun 16 Jul 2023 07:56:47 PM CST

Problem 20: Factorial digit sum

$n!$ means $n \times (n − 1) \times … \times 3 \times 2 \times 1$.

For example, $10! = 10 \times 9 \times … \times 3 \times 2 \times 1 = 3628800$, and the sum of the digits in the number $10!$ is $3 + 6 + 2 + 8 + 8 + 0 + 0 = 27$.

Find the sum of the digits in the number $100!$.

 ************************************************************************/

#include<stdio.h>

int main() {
    int arr[10000];
    arr[0] = arr[1] = 1;
    for (int i = 1; i < 100; i++) {
        for (int j = 1; j <= arr[0]; j++) arr[j] *= i;
        for (int k = 1; k <= arr[0]; k++) {
            if (arr[k] < 10) continue;
            arr[k + 1] += arr[k] / 10;
            arr[k] %= 10;
            arr[0] += (k == arr[0]);
        }
    }
    int sum = 0;
    for (int i = arr[0]; i > 0; i--) sum += arr[i];
    printf("%d\n", sum);
    return 0;
}
