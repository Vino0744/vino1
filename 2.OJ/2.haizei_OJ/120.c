/*************************************************************************
	> File Name: 120.c
	> Author: 
	> Mail: 
	> Created Time: Mon 03 Jul 2023 12:14:53 PM CST
 ************************************************************************/

#include<stdio.h>

int check_data(int y, int m, int d) {
    int mouth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (y <= 0 || m <= 0 || m >12 || d <= 0 || d > 31) return 0;
    if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) mouth[2] += 1;
    return d <= mouth[m];
}

int main() {
    int y, m, d;
    scanf("%d%d%d", &y, &m, &d);
    printf("%s\n", check_data(y, m, d) ? "YES" : "NO");  
    return 0;
}
