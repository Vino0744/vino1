/*************************************************************************
	> File Name: 4.polymorphic_destructor.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 20 May 2024 04:29:51 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

//在存在继承关系的情况下，父类的析构函数一定要设置成虚函数
//如果希望我们设计的类被继承，一定要将析构函数设计成虚函数
//否则会发生内存泄漏

class Base {
public:
    Base() {
        cout << "class Base constructor" << endl;
    }
    virtual ~Base() {
        cout << "class Base destructor" << endl;
    }
};

class A : public Base {
public:
    A() : data(new int[10]) {
        cout << "class A constructor" << endl;
    }
    ~A() {
        delete[] data;
        cout << "class A destructor" << endl;
    }
    int *data;
};

int main() {
    Base *p = new A();
    delete p;


    return 0;
}
