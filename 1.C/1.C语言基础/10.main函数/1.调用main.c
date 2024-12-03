/*************************************************************************
	> File Name: 1.调用main.c
	> Author: 
	> Mail: 
	> Created Time: Sun 09 Jul 2023 04:02:58 PM CST
 ************************************************************************/

#include<stdio.h>

//OS调用main
//向上调用软件，向下调用硬件

int main(int argc, char *argv[], char **env) {
    //argc: 命令行的参数个数
    //argv[]: 本质上是一维数组（每个数组中的元素是 char *），储存的是字符串
    //env: 本质上是二级指针（*env[]），同等与argv，记录了环境变量（操作系统提供的）
    
    printf("argc = %d\n", argc);
    for (int i = 0; i < argc; i++) printf("%s\n", argv[i]);
    for (int i = 0; env[i]; i++) printf("env[%d] = %s\n", i, env[i]);
    return 0;
}
