/*************************************************************************
	> File Name: 2.override.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 20 May 2024 03:11:33 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class Base {
public:
    virtual void fo0() {
        cout << "class Base" << endl;
    }
};

class A : public Base {
public:
    void foo() override {
        cout << "class A" << endl;
    }
};

int main() {
    A a;
    a.fo0();



    return 0;
}
