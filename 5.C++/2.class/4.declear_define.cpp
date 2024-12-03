/*************************************************************************
	> File Name: 4.declear_define.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 23 Apr 2024 08:01:28 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class A {
public:
    A() {
        cout << "class A : default constructor" << endl;
    }
    A(const A &a) {
        cout << "class A : copy constrcutor" << endl;
    }
};

class Point {
public:
    Point() = default;
    Point(int x, int y) : p(new int(4)), x(x), y(y) {}
    Point(const Point &a) : x(a.x + 1), y(a.y + 2), a(a.a){
        this->x = a.x + 1;
        this->y = a.y + 2;
        this->p = a.p;
        this->a = a.a;
    }
    ~Point() {
        delete p;
    }
private:
    int *p;
    int x, y;
    A a;
};

int main() {
    Point p1(3, 4), p2 = p1;
    


    return 0;
}
