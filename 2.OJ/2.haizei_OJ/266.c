/*************************************************************************
	> File Name: 266.c
	> Author: 
	> Mail: 
	> Created Time: Sat 29 Jul 2023 09:35:44 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#define INF 0x3f3f3f3f

bool is_operator(char c) {
    switch(c) {
        case '+' :
        case '-' :
        case '*' :
        case '/' :
        case '^' : return true;
        default : return false;
    }
    return false;
}

long long calResult(char *str, int l, int r) {
    long long pri = INF - 1, cur_pri = INF, temp_pri = 0;
    int pos = -1;
    for (int i = l; i < r; i++) {
        cur_pri = INF;
        switch(str[i]) {
            case '(' : temp_pri += 100; break;
            case ')' : temp_pri -= 100; break;
            case '+' :
            case '-' : cur_pri = 1 + temp_pri; break;
            case '*' :
            case '/' : cur_pri = 2 + temp_pri; break;
            case '^' : cur_pri = 3 + temp_pri; break;
        }
        if ((str[i] == '+' || str[i] == '-') && (i - 1 < 0 || is_operator(str[i - 1]))) {
            cur_pri += 1000;
        }
        if (pri >= cur_pri) {
            pri = cur_pri;
            pos = i;
        }
    }
        if (pos == -1) {
            long long num = 0;
            for (int i = l; i < r; i++) {
                if (str[i] < '0' || str[i] > '9') continue;
                num = num * 10 + (str[i] - '0');
            }
            return num;
        } else {
            long long a = calResult(str, l, pos);
            long long b = calResult(str, pos + 1, r);
            switch(str[pos]) {
                case '+' : return a + b;
                case '-' : return a - b;
                case '*' : return a * b;
                case '/' : return a / b;
                case '^' : return pow(a, b);
            }
        }
    return 0;
}

int main() {
    char str[1005] = {0};
    scanf("%s", str);
    long long result = calResult(str, 0, strlen(str));
    printf("%lld\n", result);
    return 0;
}
