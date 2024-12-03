/*************************************************************************
	> File Name: 2.标准宏.c
	> Author: 
	> Mail: 
	> Created Time: Fri 07 Jul 2023 09:35:18 PM CST
 ************************************************************************/

#include<stdio.h>

int main() {
    printf("%s\n", __DATE__);
    printf("%s\n", __TIME__);//设置时间指纹
    printf("%s\n", __FILE__);
    printf("%d\n", __LINE__);
    printf("%s\n", __func__);
    return 0;
}
