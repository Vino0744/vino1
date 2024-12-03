/*************************************************************************
	> File Name: 7.special_operator.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 28 Apr 2024 02:33:48 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class ArrayObject {
public:
    int operator[](int ind) {
        return 2 * ind;
    }
};

class FunctionObject {
public:
    int operator()(int x) {
        return 2 * x;
    }
};

class Point {
public:
    Point(int x, int y) : x(x), y(y) {}
    int x, y;
};

class PointObject {
public:
    PointObject() : p(new Point(rand() % 100, rand() % 100)) {}
    Point *operator->() {
        return p;
    }
    ~PointObject() {
        delete p;
    }
private:
    Point *p;
};

int main() {
    ArrayObject arr;
    for (int i = 0; i < 10; i++) cout << "arr[" << i << "] = " << arr[i] << endl;
    
    FunctionObject f;
    for (int i = 0; i < 10; i++) cout << "f(" << i << ") = " << f(i) << endl;

    PointObject p;
    cout << "p->x = " << p->x << " p->y = " << p->y << endl;

    return 0;
}
