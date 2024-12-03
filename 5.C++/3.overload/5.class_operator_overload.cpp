/*************************************************************************
	> File Name: class_operator_overload.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 25 Apr 2024 08:40:46 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class Point {
public:
    Point(int x, int y) : x(x), y(y) {}
    Point operator+(const Point &a) {
        return Point(this->x + a.x, this->y + a.y);
    }
    Point &operator++() {//前++ 返回左值 无参数
        this->x += 1;
        this->y += 1;
        return *this;
    }
    Point operator++(int) {//后++ 返回右值 有参数
        Point ret(*this);
        ++(*this);
        return ret;
    }

    friend ostream &operator<<(ostream &, const Point &);
private:
    int x, y;
};

ostream &operator<<(ostream &out, const Point &p) {
    out << "(" << p.x << ", " << p.y << ")";
    return out;
}

int main() {
    Point a(1, 2), b(3, 4);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << a + b << endl;
    cout << a.operator+(b) << endl;
    cout << "++a = " << ++a << endl;
    cout << "b++ = " << b++ << endl;

    return 0;
}
