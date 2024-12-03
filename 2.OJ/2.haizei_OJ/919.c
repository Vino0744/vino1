/*************************************************************************
	> File Name: 919.c
	> Author: 
	> Mail: 
	> Created Time: Thu 06 Jul 2023 11:05:41 AM CST
 ************************************************************************/

#include<stdio.h>
#include <string.h>
#define MAX_N 50

int reverse_str(const char *str) {
    for (int i = 0, j = strlen(str) - 1; i <= j; i++, j--) {
        if (str[i] != str[j]) return 0;
    }
    return 1;
}

int main() {
    char str[MAX_N + 5];
    scanf("%s", str);
    printf("%s\n", reverse_str(str) ? "YES" : "NO");
    return 0;
}
