/*************************************************************************
	> File Name: 7.rvalue.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 05 Jun 2024 03:32:13 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

#define BEGINS(x) namespace x {
#define ENDS(x) }

BEGINS(test1)

void judge2(int &x) {
    cout << "(left value -> 2) ";
    return ;
}

void judge2(int &&x) {
    cout << "(right value -> 2) ";
    return ;
}

//左值引用
void judge(int &x) {
    judge2(x);
    cout << "left value" << endl;
    return ;
}

//右值引用
void judge(int &&x) {
    judge2(x);
    cout << "right value" << endl;
    return ;
}

#define TEST(a) { \
    cout << "judge " << #a << " : "; \
    judge(a); \
}

int main() {
    int n = 123;
    TEST(n);
    TEST(n + 1);
    TEST(n++);
    TEST(++n);
    TEST(1 + 2);
    TEST(n += 2);

    return 0;
}

ENDS(test1)

BEGINS(test2)

#define TEST(a) { \
    cout << "judge " << #a << " : "; \
    judge(a); \
}

void judge(int &x) {
    cout << "left value" << endl;
    return ;
}

void judge(int &&x) {
    cout << "right value" << endl;
    return ;
}

int main() {
    int n = 123;
    //move() -> right value
    judge(move(n));
    judge(forward<int &&>(n));

    return 0;
}

ENDS(test2)

BEGINS(test3)

//左值：返回应用
//右值：返回值

class Point {
public:
    Point(int x, int y) : __x(x), __y(y) {}
    int x() { return __x; }
    int y() { return __y; }
    Point &operator+=(int a) {
        __x += a;
        __y += a;
        return *this;
    }
    Point operator+(int a) {
        return *this += a;
    }
private:
    int __x, __y;
};

void judge(Point &p) {
    cout << "left value" << endl;
    return ;
}

void judge(Point &&p) {
    cout << "right value" << endl;
    return ;
}
/*
#define TEST(a) { \
    cout << "judge " << #a << " : "; \
    judge(a); \
}
*/

int main() {
    Point p1(3, 4);
    TEST(p1);
    TEST(p1 += 1);
    TEST(p1 + 1);


    return 0;
}

ENDS(test3)

BEGINS(test4)

class Array {
public:
    Array(int n = 100) : __size(n), data(new int[n]) {
        cout << this << " default constructor" << endl;
    }
    Array(const Array &a) : __size(a.size()), data(new int[a.size()]) {
        for (int i = 0; i < a.size(); i++) {
            data[i] = a[i];
        }
        cout << this << " deep copy constructor" << endl;
    }
    Array(Array &&a) : __size(a.size()), data(a.data) {
        cout << this << " move constructor" << endl;
        a.data = nullptr;
        a.__size = 0;
    }
    int &operator[](int ind) const {
        return data[ind];
    }
    Array operator+(Array &a) {
        Array ret(a.size() + __size);
        for (int i = 0; i < __size; i++) {
            ret[i] = data[i];
        }
        for (int i = __size; i < ret.size(); i++) {
            ret[i] = a[i - __size];
        }
        return ret;
    }
    int size() const { return __size; }
    ~Array() {
        cout << this << " destructor" << endl;
    }
private:
    int __size;
    int *data;
};

int main() {
    Array a, b;
    Array c = a + b;

    return 0;
}

ENDS(test4)

int main() {
    //test1::main();    
    //test2::main();
    //test3::main();
    test4::main();

    return 0;
}
