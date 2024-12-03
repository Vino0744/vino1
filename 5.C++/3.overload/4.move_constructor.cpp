/*************************************************************************
	> File Name: 4.move_constructor.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 26 Apr 2024 07:48:47 AM CST
 ************************************************************************/

#include<iostream>
#include <ctime>
#include <assert.h>
using namespace std;

class Array {
public:
    Array(int n) : n(n), arr(new int[n]) {
        cout << "default constructor" << endl;
    }
    Array(const Array &a) : n(a.n), arr(new int[n]) {
        cout << "copy constructor" << endl;
        for (int i = 0; i < n; i++) arr[i] = a[i];
        return ;
    } 
    Array(Array &&a) : n(a.n), arr(a.arr) {
        cout << "move constructor" << endl;
        a.n = 0;
        a.arr = nullptr;
        return ;
    }
    void output(const char *frm) {
        for (int i = 0; i < n; i++) {
            printf(frm, i, arr[i]);
        }
    }
    int &operator[](int &ind) const {//返回的是元素而不是一个值
        assert(ind >= 0 && ind < n);
        return arr[ind];
    }
    ~Array() {
        cout << "array destructor" << endl;
        if (arr = nullptr) return ;
        delete[] arr;
        return ;
    }

private:
    int n;
    int *arr;
};

Array func() {
    Array a(7);
    for (int i = 0; i < 7; i++) a[i] = i;
    return a;
}

int main() {
    Array a(10);
    for (int i = 0; i < 10; i++) {
        a[i] = rand() % 100;
    }
    a.output("a[%d] = %d\n");
    Array b = func();
    b.output("b[%d] = %d\n");
    Array c(move(a));//将a当成临时参数 右值
    c.output("c[%d] = %d\n");
    return 0;
}
