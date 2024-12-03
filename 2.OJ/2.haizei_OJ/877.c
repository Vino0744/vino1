/*************************************************************************
	> File Name: 877.c
	> Author: 
	> Mail: 
	> Created Time: Wed 05 Jul 2023 09:56:13 PM CST
 ************************************************************************/

#include<stdio.h>
#include <string.h>
#define MAX_N 30

void slove(char *str) {
    char temp[MAX_N] = {0};
    int a, b, c;
    sscanf(str, "%d is %s", &a, temp);
    if (strncmp(temp, "greater", 7) == 0) {
        sscanf(str, "%d is greater than %d", &a, &b);
        printf("%s\n", a > b ? "Yes" : "No");
    } else if (strncmp(temp, "equal", 5) == 0) {
        sscanf(str, "%d is equal to %d plus %d", &a, &b, &c);
        printf("%s\n", a == b + c ? "Yes" : "No");
    } else {
        printf("???\n");
    }
    return ;
}

int main() {
    char str[MAX_N + 5] = {0};
    scanf("%[^\n]", str);
    slove(str);
    return 0;
}
