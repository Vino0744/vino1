/*************************************************************************
	> File Name: 1.分别大小端机.c
	> Author: 
	> Mail: 
	> Created Time: Sat 08 Jul 2023 09:36:41 PM CST
 ************************************************************************/

#include<stdio.h>

int is_little() {
    int a = 1;
    printf("你的机器是%s\n",((char *)(&a))[0] == 0 ? "大端机" : "小端机");
    return 0;
}

int main() {
    is_little();
    return 0;
}
