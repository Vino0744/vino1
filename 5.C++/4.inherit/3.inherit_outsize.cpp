/*************************************************************************
	> File Name: 3.inherit_outsize.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 13 May 2024 05:25:10 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class A {
public:
    int public_int;
private:
    int private_int;
protected:
    int protected_int;
};

class B_public : public A {};
class B_private : private A {};
class B_protected : protected A {};

//public->protected->private
//只有在更加严格的条件下继承权限才可以发挥作用

int main() {
    B_public b_pub;
    b_pub.public_int = 1;
    //b_pub.private_int = 1;
    //b_pub.protected_int = 1;

    B_private b_pri;
    //b_pri.public_int = 1;
    //b_pri.private_int = 1;
    //b_pri.protected_int = 1;

    B_protected b_pro;
    //b_pro.public_int = 1;
    //b_pro.private_int = 1;
    //b_pro.protected_int = 1;

    return 0;
}
