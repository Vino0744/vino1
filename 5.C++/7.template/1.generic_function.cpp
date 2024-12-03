/*************************************************************************
	> File Name: 1.add.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 26 May 2024 02:14:37 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

/*******************
int add(int a, int b) {
    return a + b;
}
********************/

#define P(func) { \
    cout << #func " = " << func << endl; \
}

class No_Default_Constructor {
public:
    No_Default_Constructor() = delete;
    No_Default_Constructor(double y) : y(y) {}
    double operator+(int x) { return x + y; }
    double y;
};

template<typename T, typename U>
//返回值后置
auto add(T a, U b) -> decltype(a + b) {
    return a + b;
}

int main() {
    No_Default_Constructor ndc(3.4);
    cout << ndc + 4 << endl;
    P(add(ndc, 4));
    P(add(2, 3));
    P(add(5, 6));
    P(add(1930.12, 1033.98));
    //显示调用
    P(add<long long>(5, 1LL));
    P(add(2, 1.3));
    P(add(1.3, 2));
    string a = "123", b = "xyz";
    P(add(a, b));

    return 0;
}
