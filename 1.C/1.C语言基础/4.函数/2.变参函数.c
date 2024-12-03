/*************************************************************************
	> File Name: 2.变参函数.c
	> Author: 
	> Mail: 
	> Created Time: Tue 04 Jul 2023 09:52:48 PM CST
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>
#include <stdarg.h>

int max_int(int n, ...) {
    va_list arg; //设置变参列表 
    va_start(arg, n); //从变量n的后面开始
    int ans = INT32_MIN;
    while (n--) {
        int temp = va_arg(arg, int); //读取下一个int（char *, double）类型
        if (temp > ans) ans = temp;
    }
    va_end(arg); //va结束
    return 1;
}

int main() {
    printf("%d\n", max_int(3, -1, -99, 0));
    return 0;
}
