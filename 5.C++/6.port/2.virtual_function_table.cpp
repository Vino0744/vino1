/*************************************************************************
	> File Name: 2.virtual_function_table.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 21 May 2024 08:06:38 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

//每一个类型准备了一张虚函数表
//对象默认指向其对应类型的虚函数表
//也可以修改当前对象的虚函数表的指向

class Base {
public:
    virtual void say(int x) {
        cout << "class Base : " << x << endl;
    }
};

class A : public Base {
public:
    void say(int x) {
        cout << this << " : " << this->x << endl;
        cout << "class A : " << x << endl;
    }
    int x;
};

class B : public Base {
public:
    void say(int x) {
        cout << this << " : " << this->x <<  ", " << this->y << endl;
        cout << "class B : " << x << endl;
    }
    int y;
    int x;
};

typedef void (*FuncT)(void *, int);

int main() {
    A a1, a2;
    B b;
    a1.x = a2.x = 100;
    b.x = 10000;
    b.y = 9999;
    Base *p1 = &a1, *p2 = &a2, *p3 = &b; 
    cout << "sizeof(A) : " << sizeof(a1) << endl;
    cout << "sizeof(B) : " << sizeof(b) << endl;
    cout << "Class A(a1) virtual function address : " << ((void **)(&a1))[0] << endl;
    cout << "Class A(a2) virtual function address : " << ((void **)(&a2))[0] << endl;
    cout << "Class A(b) virtual function address : " << ((void **)(&b))[0] << endl;
    p1->say(1);
    p2->say(2);
    p3->say(3);
    ((void **)(&a1))[0] = ((void **)(&b))[0];
    p1->say(1);
    p2->say(2);
    p3->say(3);
    cout << "===========" << endl;
    ((FuncT **)(&a2))[0][0](&b, 1314);

    return 0;
}
