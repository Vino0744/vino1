/*************************************************************************
	> File Name: 5.reference_object.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 24 Apr 2024 10:49:08 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class A {
public:
    
private:
};

class C {
public:
    C() = default;
    C(const C &) = default;
    static void destroy(C *c) {
        delete c;
        return ;
    }
private:
    ~C() {}
};

int main() {
    C *c = new C();
    //delete c;
    C::destroy(c);


    return 0;
}
