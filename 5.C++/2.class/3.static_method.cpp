/*************************************************************************
	> File Name: 3.static_method.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 23 Apr 2024 09:29:37 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class Point {
public:
    Point() : get_x_cnt(0), x(0), y(0) {}
    Point(int x, int y) : get_x_cnt(0), x(x), y(y) {}
    void set_x(int x) { this->x = x; }
    void set_y(int y) { this->y = y; }
    int get_x() const {
        this->get_x_cnt += 1;
        return this->x;
    }
    int get_y() const { return this->y; }
    int x_cnt() const {
        return this->get_x_cnt;
    }
private:
    mutable int get_x_cnt;//可以在const类型中修改
    int x, y;
};

//int Point::get_x_cnt = 0;//定义

int main() {
    //const类型只能调用const方法
    const Point p1(10, 15), p2(15, 20);
    cout << p1.get_x() << "," << p1.get_y() << endl;
    p1.get_x();
    p2.get_x();
    cout << "p1.x_cnt() = " << p1.x_cnt() << endl;
    cout << "p2.x_cnt() = " << p2.x_cnt() << endl;

    return 0;
}
