/*************************************************************************
	> File Name: 3.left_right.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 25 Apr 2024 09:01:32 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

#define LEFT_OR_RIGHT(expr) { \
    printf("%s\n", #expr); \
    left_or_right(expr); \
}

void left_or_right(int &x, int flag = 1) {
    printf("left value : %d\n", x);
    if (flag) left_or_right(x, 0);
    return ;
}

void left_or_right(int &&x, int flag = 1) {
    printf("right value : %d\n", x);
    //if (flag) left_or_right(forward<int &&>(x), 0);
    if (flag) left_or_right(move(x), 0);
    return ;
}

//左值表示持续态
//右值表示暂时态
//在函数内部传参时右值变为左值
//
//准确传递左右值
//1.move()
//2.forward<>()

int main() {
    int a = 123;
    LEFT_OR_RIGHT(a);
    LEFT_OR_RIGHT(a + 1);
    LEFT_OR_RIGHT(123);
    LEFT_OR_RIGHT(a++);
    LEFT_OR_RIGHT(++a);
    LEFT_OR_RIGHT(a += 2);

    return 0;
}
