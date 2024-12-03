/*************************************************************************
	> File Name: 3.递归函数.c
	> Author: 
	> Mail: 
	> Created Time: Tue 04 Jul 2023 11:03:28 PM CST
 ************************************************************************/

#include<stdio.h>

 //系统栈为8MB segmentation fault : 11

long long fac(int n){ //调用函数慢于循环
    if (n == 1) return 1;
    return n * fac(n - 1);
}

void func1() {
    static int n = 0;//静态变量 跟着整个程序走 延长生命周期 程序结束变量空间才会被回收
    n += 1;
    printf("n = %d\n", n);
    return ;
}

int main() {
    int n;
    /*
    while (~scanf("%d", &n)) {
        printf("%d! = %lld", n,  fac(n));
    }
    */
    for (int i = 0; i < 5; i++) func1();
    return 0;
}
