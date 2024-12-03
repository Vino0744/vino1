/*************************************************************************
	> File Name: 7.RVO.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 24 Apr 2024 11:21:44 AM CST
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
    string s;
};

//优化：直接对a进行操作而不是temp，temp只是引用
A func() {
    A temp;
    cout << "temp = " << &temp << endl;
    temp.s = "hello func";
    return temp;
}

int main() {
    A a = func();
    cout << "a = " << &a << endl;


    return 0;
}
