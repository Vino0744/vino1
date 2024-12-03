/*************************************************************************
	> File Name: 1.constructor.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 22 Apr 2024 09:06:43 PM CST
 ************************************************************************/

#include<iostream>
#include <map>
using namespace std;

class A;
class MyMap : public map<A *, string> {
public:
    void output(A *p, string s) {
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
    //构造函数
    A() {
        name.output(this, "default constructor");
        //cout << naem[this] << "default constructor" << endl;
    }
    //转换构造
    //可以将一个整形值转换为A类型的对象
    A(int x) {
        name.output(this, "transform constructor");
        //cout << name[this] << "transform constructor" << endl;
        this->x = x;
        this->y = 0;
    }
    //拷贝构造
    A(const A &a) {
        name.output(this, " copy constructor");
        //cout << name[this] << "copy constructor" << endl;
        this->x = a.x;
        this->y = a.y;
    }
    A(int x, int y) {
        name.output(this, " 2 arguments constructor");
        //cout << name[this] << "2 arguments constructor" << endl;
        this->x = x;
        this->y = y;
    }
    void operator=(const A &a) {
        name.output(this, "operator=");
        this->x = a.x;
        this->y = a.y;
        return ;
    }
    void output() {
        cout << '(' << x << ", " << y << ')' << endl;
    }
    //析构函数
    ~A() {
        name.output(this, " destructor");
        //cout << "destructor" << endl;
    }
private:
    int x, y;
};

void func(A a) {
    cout << "func : ";
    a.output();
    return ;
}

namespace test1 {

int main() {
    A a(3, 4), b(3);
    A c = 4;//调用转换构造 == c(4), 类型必须匹配
    func(a);
    func(b);
    cout << "=======" << endl;
    func(6);
    return 0;
}
}

namespace copy_constructor {
    
int main() {
    A a;
    A b = a;//拷贝构造函数
    A c;
    name[&a] = "a";
    name[&b] = "b";
    name[&c] = "c";
    c = a;//构造函数而非拷贝构造函数
    cout << "a = " << &a << endl;
    cout << "b = " << &b << endl;
    cout << "c = " << &c << endl;

    return 0;
}
}

int main() {
    //test1::main();
    copy_constructor::main();
    return 0;
}
