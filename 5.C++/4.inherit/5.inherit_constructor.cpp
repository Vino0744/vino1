/*************************************************************************
	> File Name: 5.inherit_constructor.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 14 May 2024 08:39:12 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class A {
public:
    A() : x(99) {
        cout << "class A default constructor" << endl;
    }
    A(const A &a) : x(a.x) {
        cout << "class A copy constructor" << endl;
    }
    A(int x) : x(x) {
        cout << "class A A(int) constructor" << endl;
    }
    int x;
};

class B : public A {
public:
    B() : A(60), y(100) {
        cout << "class B default constructor" << endl;
    }
    B(const B &b) : A(b), y(b.y) {
        cout << "class B copy constructor" << endl;
    }
    B &operator=(const B &obj) {
        this->A::operator=(obj);
        this->y = obj.y;
        return *this;
    }
    void output() {
        cout << x << " " << y << endl;
    }
    int y;
};

int main() {
    B b;
    b.output();
    b.x = 10000;
    B c(b), d;
    b.output();
    c.output();
    d = b;
    d.output();



    return 0;
}
