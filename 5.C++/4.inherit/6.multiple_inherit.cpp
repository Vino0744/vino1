/*************************************************************************
	> File Name: 6.multiple_inherit.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 14 May 2024 09:02:31 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class A {
public:
    int x, y;
};

class B : virtual public A {
public:
    void set_x() { this->x = 99; }
};

class C : virtual public A {
public:
    void set_y() { this->y = 100; }
    void output() {
        cout << x << " " << y << endl;
    }
};

class D : public B, public C {
public:
};

int main() {
    D d;
    d.set_x();
    d.set_y();
    d.output();



    return 0;
}
