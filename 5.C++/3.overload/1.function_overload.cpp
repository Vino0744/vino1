/*************************************************************************
	> File Name: 8.function_overload.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 24 Apr 2024 08:00:14 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

void output(int x) {
    printf("output int : %d\n", x);
    return ;
}

void output(long long x) {
    printf("output long long : %lld\n", x);
    return ;
}

void output(const char *s) {
    if (!s) {
        printf("output string : nullptr\n");
        return ;
    }
    printf("output string : %s\n", s);
    return ;
}

void output(int x, int y) {
    printf("output int int : %d %d\n", x, y);
    return ;
}

void output(int a, int b, int c) {
    
    return ;
}

int main() {
    output(3);
    output(3LL);
    output("hello world");
    output(3, 4);
    output(3LL, 4);
    output(nullptr);

    

    return 0;
}
