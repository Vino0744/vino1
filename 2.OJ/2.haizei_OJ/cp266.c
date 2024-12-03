/*************************************************************************
	> File Name: cp266.c
	> Author: 
	> Mail: 
	> Created Time: Mon 31 Jul 2023 06:48:16 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define INF 0x3f3f3f3f

int is_symbol(char c) {
    switch(c) {
        case '+':
        case '-':
        case '*':
        case '/':
        case '^': return 1;
        default : return 0;
    }
    return 0;
}

long long judge(char *str, int l, int r) {
    long long pri = INF - 1, cur_pri, temp_pri = 0, ind = -1;
    for (int i = l; i < r; i++) {
        cur_pri = INF;
        switch(str[i]) {
            case '(': temp_pri += 100; break;
            case ')': temp_pri -= 100; break;
            case '+':
            case '-': cur_pri = 1 + temp_pri; break;
            case '*':
            case '/': cur_pri = 2 + temp_pri; break;
            case '^': cur_pri = 3 + temp_pri; break;
        }
        if ((str[i] == '-' || str[i] == '+') && (i <= 0 || is_symbol(str[i - 1]))) cur_pri += 1;
        if (pri >= cur_pri) {
            pri = cur_pri;
            ind = i;
        }
    }
    if (ind == -1) {
        long long sum = 0;
        for (int i = l; i < r; i++) {
            if (str[i] < '0' || str[i] > '9') continue;
            sum = sum * 10 + (str[i] - '0');
        }
        return sum;
    } else {
        long long a = judge(str, l, ind);
        long long b = judge(str, ind + 1, r);
        switch(str[ind]) {
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
            case '/': return a / b;
            case '^': return pow(a, b);
        }
    }
    return 0;
}

int main() {
    char str[1005] = {0};
    scanf("%s", str);
    printf("%lld\n", judge(str, 0, strlen(str)));
    return 0;
}
