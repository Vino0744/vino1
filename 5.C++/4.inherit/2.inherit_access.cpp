/*************************************************************************
	> File Name: 2.inherit_access.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 13 May 2024 05:03:43 PM CST
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

//继承权限不影响子类对父类的访问
//继承权限只影响外部对子类的访问
//其中protected只有子类可以访问该字段
class B_public : public A {
public :
    B_public() {
        public_int = 1;
        private_int = 1;
        protected_int = 1;
    }
};

class B_private : private A {
public:
    B_private() {
        public_int = 1;
        private_int = 1;
        protected_int = 1;
    }
};

class B_protected : protected A {
public:
    B_protected() {
        public_int = 1;
        private_int = 1;
        protected_int = 1;
    }
};

int main() {




    return 0;
}
