/*************************************************************************
	> File Name: EP-025.c
	> Author: 
	> Mail: 
	> Created Time: Sun 16 Jul 2023 08:33:29 PM CST

Problem 25: $1000$-digit Fibonacci number

The Fibonacci sequence is defined by the recurrence relation:
$F_n = F_{n-1} + F_{n-2}$, where $F_1 = 1$ and $F_2 = 1$.

Hence the first 12 terms will be:
$$\begin{aligned}
F_1&=1\\
F_2&=1\\
F_3&=2\\
F_4&=3\\
F_5&=5\\
F_6&=8\\
F_7&=13\\
F_8&=21\\
F_9&=34\\
F_{10}&=55\\
F_{11}&=89\\
F_{12}&=144\\
\end{aligned}$$

The $12$th term, $F_{12}$, is the first term to contain three digits.

What is the first term in the Fibonacci sequence to contain $1000$ digits?

 ************************************************************************/

#include <stdio.h>

#define MAX(a, b) ({ \
    __typeof(a) _a = a; \
    __typeof(b) _b = b; \
    _a > _b ? _a : _b; \
})

int main() {
    int arr[3][1005] = {0};
    arr[0][0] = arr[0][1] = arr[1][0] = arr[1][1] = arr[2][0] = 1;
    int cnt = 2;
    while (arr[2][0] < 1000) {
        for (int i = 1; i <= (MAX(arr[0][0], arr[1][0])); i++) arr[2][i] = arr[0][i] + arr[1][i];
        for (int j = 1; j <= arr[2][0]; j++) {
            if (arr[2][j] < 10) continue;
            arr[2][j + 1] += arr[2][j] / 10;
            arr[2][j] %= 10;
            arr[2][0] += (j == arr[2][0]);
        }
        for (int i = 0; i <= arr[1][0]; i++) arr[0][i] = arr[1][i];
        for (int i = 0; i <= arr[2][0]; i++) arr[1][i] = arr[2][i];
        cnt++;
    }
    printf("%d\n", cnt);
    return 0;
}
