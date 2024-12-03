/*************************************************************************
	> File Name: 3.条件式编译.c
	> Author: 
	> Mail: 
	> Created Time: Fri 07 Jul 2023 09:53:01 PM CST
 ************************************************************************/

#include<stdio.h>

#ifdef XXX//是否定义了XXX宏
#ifndef XXX//是否没定义XXX宏
#if XXX == a//XXX是否等于a
#elif XXX == a//否则XXX是否等于a
#else 
#endif//对应#if

int main() {
    
    return 0;
}
