/*************************************************************************
	> File Name: call_function.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 30 May 2024 09:23:00 AM CST
 ************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <stdexcept>
#include <exception>
using namespace std;

//函数调用的流程
//1、将函数中的参数倒着压入栈
//2、将call函数的返回地址压入栈
//3、将栈底放到现在栈顶的位置（ebp->esp），栈顶往上放
//4、备份原栈帧，开辟新栈帧

//四种函数调用方式
//1、cdecl
//2、stdcall
//3、fastcall
//4、thiscall

int __cdecl test_cdecl(int parm1, int parm2) {
    return 1;
}
int __stdcall test_stdcall(int parm1, int parm2) {
    return 1;
}
int __fastcall test_fastcall(int parm1, int parm2) {
    return 1;
}
class A {
public:
    int __thiscall test_thiscall(int parm1, int parm2) {
        return 1;
    }
};
int main() {
    test_cdecl(0, 1);
    test_stdcall(0, 1);
    test_fastcall(0, 1);
    A a;
    a.test_thiscall(0, 1);


    return 0;
}
