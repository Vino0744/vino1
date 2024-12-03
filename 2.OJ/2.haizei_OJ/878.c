/*************************************************************************
	> File Name: 878.c
	> Author: 
	> Mail: 
	> Created Time: Wed 05 Jul 2023 10:26:43 PM CST
 ************************************************************************/

#include<stdio.h>
#define MAX_N 100

int main() {
    int y, m, d, h, M, s;
    scanf("%d%d%d%d%d%d", &y, &m, &d, &h, &M, &s);
    char str[MAX_N + 5] = {0};
    sprintf(str, "%0004d-%02d-%02d %02d:%02d:%02d", y, m, d, h, M, s);
    printf("%s\n", str);
    return 0;
}
