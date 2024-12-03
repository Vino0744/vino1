/*************************************************************************
	> File Name: 876.c
	> Author: 
	> Mail: 
	> Created Time: Wed 05 Jul 2023 09:10:48 PM CST
 ************************************************************************/

#include<stdio.h>
#include <string.h>
#define MAX_N 100

int main() {
    char s1[MAX_N + 5] = {0}, s2[MAX_N] = {0};
    scanf("%s%s", s1, s2);
    sprintf(s1 + strlen(s1), "%s", s2);
    printf("%s\n", s1);
    return 0;
}
