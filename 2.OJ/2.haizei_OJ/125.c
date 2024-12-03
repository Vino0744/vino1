/*************************************************************************
	> File Name: 125.c
	> Author: 
	> Mail: 
	> Created Time: Wed 20 Sep 2023 11:23:59 PM CST
 ************************************************************************/

#include<stdio.h>

int main() {
    int h, m, s, t;
    scanf("%d%d%d%d", &h, &m, &s, &t);
    int h1 = h, m1 = m, s1 = s, flag = 0;
    s1 += t;
    m1 += (s1 / 60);
    s1 %= 60;
    h1 += (m1 / 60);
    m1 %= 60;
    if ((h1 / 12) & 1) flag = 1;
    h1 %= 12;
    if (h1 == 0) h1 = 12;
    printf("%d:%d:%d", h1, m1, s1);
    if (flag) printf("pm\n");
    else printf("am\n");
    printf("%.2lf%%\n", 100 * t / (60 * 60 * 24.0));
    return 0;
}
