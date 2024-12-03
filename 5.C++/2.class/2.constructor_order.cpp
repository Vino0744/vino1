/*************************************************************************
	> File Name: 2.constructor_order.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 23 Apr 2024 08:20:54 AM CST
 ************************************************************************/

#include<iostream>
#include <map>
using namespace std;

//1.先构造的后析构
//2.先构造属性再构造对象
//3.初始化列表顺序只和属性定义顺序有关
//4.使用顺序和声明顺序相同

class A;
class MyMap : public map<A *, string> {
public:
    void output(void *p, string s) {
        if (find(p) == end()) {
            cout << "unknown name";
        } else {
            cout << operator[](p);
        }
        cout << s << endl;
        return ;
    }
} name;

class A {
public:
    A(string n) {
        name[this] = n;
        name.output(this, "class A constructor");
    }
    ~A() {
        name.output(this, "class A destructor");
    }
    int *p;
};

class B {
public:
    B(string n, A &a) : a(a) {
        name[this] = n;
        name.output(this, "class B constructor");
        a.p = new int;
    }
    ~B() {
        delete a.p;
        name.output(this, "class B destructor");
    }
    A a;
};

class C {
public:
    C(string n) : a(n + ".a"), b(n + ".b", a) {
        name[this] = n;
        name.output(this, "class C constructor");
    }
    A a, b;
    ~C() {
        name.output(this, "class C destructor");
    }
};

int main() {
    C c("c");

    return 0;
}
