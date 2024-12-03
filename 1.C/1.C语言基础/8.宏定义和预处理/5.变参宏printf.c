/*************************************************************************
	> File Name: 5.宏定义提示.c
	> Author: 
	> Mail: 
	> Created Time: Sat 08 Jul 2023 09:45:43 AM CST
 ************************************************************************/

#include<stdio.h>

#define DEBUG

//条件式编译
#ifdef DEBUG
#define LOG(format, arg...) { \
    printf("FILE = %s, FUNC = %s, LINE = %d, %s = ", __FILE__, __func__, __LINE__, #arg); \
    printf(format, ##arg); \
    printf("\n"); \
}
#endif

int main() {
    int a = 123;
    LOG("%d", a);
    LOG("hello");
    return 0;
}
