/*************************************************************************
	> File Name: 1.polymorphic.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 20 May 2024 02:44:59 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

//************************
//普通的成员方法跟着类型走
//虚函数是跟着对象走
//同名的虚函数要用override来修饰 用于代码检查
//************************

class Animal {
public:
    virtual void run() {
        cout << "I'm don't know how to run" << endl;
    }
};

class Cat : public Animal {
public:
    void run() override {
        cout << "I can run with four legs" << endl;
    }
};

class Bat : public Animal {
public:
    void run() override {
        cout << "I can fly" << endl;
    }
};

#define P(func) { \
    printf("%s : ", #func); \
    func; \
}

int main() {
    Cat c;
    Animal &a = c;
    Animal *p = &c;
    P(c.run());
    P(a.run());
    P(p->run());


    return 0;
}
