/*************************************************************************
	> File Name: EP-034.c
	> Author: 
	> Mail: 
	> Created Time: Tue 11 Jul 2023 01:56:09 PM CST
    
Problem 34:

Digit factorials
$145$ is a curious number, as $1! + 4! + 5! = 1 + 24 + 120 = 145$.

Find the sum of all numbers which are equal to the sum of the factorial of their digits.

Note: as $1! = 1$ and $2! = 2$ are not sums they are not included.

 ************************************************************************/
#include <stdio.h>
#define MAX_N 3628800

void init(int *num) {
    num[0] = 1;
    for (int i = 1; i < 10; i++) {
        num[i] = num[i - 1] * i;
    }
    return ;
}

int is_val(int *num, int n) {
    int x = n, temp = 0;
    while (x) {
        temp += num[x % 10];
        x /= 10;
    }
    return n == temp;
}

int main() {
    int sum = 0, num[10] = {0};
    init(num);
    for (int i = 11; i <= MAX_N; i++) {
        if (!is_val(num, i)) continue;
        sum += i;
    }
    printf("%d\n", sum);
    return 0;
}
