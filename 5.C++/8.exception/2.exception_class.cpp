/*************************************************************************
	> File Name: 2.exception_class.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 30 May 2024 01:55:02 AM CST
 ************************************************************************/

#include <iostream>
//常用两个错误类声明
#include <stdexcept>
#include <exception>
using namespace std;

class Helper { // 工具人
public:
    Helper() { cout << "helper constructor" << endl; }
    ~Helper() { cout << "helper destructor" << endl; }
    void boom() { cout << "boom" << endl; }
};

void inner() {
    // 其中如果是内存分配在堆上时，异常处理中则无法处理堆区，如new malloc global
    // 如果内存是分配在栈区，异常处理中会清理栈区，如main中定义
    // 下面异常处理的过程中，stack区中会执行析构函数，而heap区中则不会执行
    // inner->outer->main
    // ------>隐性代码泄露
    // Helper *h = new Helper[3]; // heap
    Helper h[3]; // stack
    throw(1);
    h[0].boom();
}

void outer() {
    try {
        inner();
    } catch(...) {
        cout << "exception caught" << endl;
    }
    return ;
}

class MyException : public runtime_error {
public:
    MyException(const string &s) : runtime_error(s) {
        cout << "MyException ctor" << endl;
    } 
    //noexcept 函数本身不会抛出异常
    const char *what() const noexcept override { //自定义异常信息
        return "123";
    }
};

int main() {
    outer();

    return 0;
}
