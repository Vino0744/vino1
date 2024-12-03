/*************************************************************************
	> File Name: 6.operator=.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 26 Apr 2024 08:21:14 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class A {
public:
    A() {
        cout << this << " default constructor" << endl;
    }
    A(const A &) {
        cout << this << " copy constructor" << endl;
    }
    A &operator=(const A &a) {
        //原地构造
        //用拷贝构造来实现
        new(this) A(a);
        cout << this << " operator=" << endl;
        return *this;
    }
    A &operator=(A &&a) {
        //用移动构造实现
        new(this) A(move(a));
        cout << this << " right value operator=" << endl;
        return *this;
    }
    ~A() {
        cout << this << " destructor" << endl;
    }
};


//赋值运算和拷贝构造函数的区别
//1.调用时机不一样
//拷贝构造是被定义的时候使用
//赋值运算符是非定义的时候使用
//2.用拷贝构造来实现赋值运算符
int main() {
    A a, b(a);
    b = a;
    A c;
    c = move(a);


    return 0;
}
