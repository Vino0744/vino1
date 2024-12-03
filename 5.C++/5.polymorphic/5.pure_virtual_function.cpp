/*************************************************************************
	> File Name: 3.virtual_function.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 20 May 2024 03:22:39 PM CST
 ************************************************************************/

#include <iostream>
#include <ctime>
using namespace std;

//************************************
//纯虚函数希望在子类中必须实现这个方法
//子类不重写父类方法会报错
//拥有纯虚函数的类就是抽象类 abstract class
//抽象类无法定义对象
//************************************

namespace test1 {

class Animal {
public:
    virtual void say() = 0;
};

class Cat : public Animal {
public:
    void say() override {
        cout << "class Cat" << endl;
    }
};

class Dog : public Animal {
public:
    void say() override {
        cout << "class Dog" << endl;
    }
};

class Bat : public Animal {
public:
    void say() override {
        cout << "class Bat" << endl;
    }
};

int main() {
    #define MAX_N 10
    srand(time(0));
    Animal *arr[MAX_N + 5];
    for (int i = 0; i < MAX_N; i++) {
        switch(rand() % 3) {
            case 0:
                arr[i] = new Cat();
                break;
            case 1:
                arr[i] = new Dog();
                break;
            case 2:
                arr[i] = new Bat();
                break;
        }
    }
    for (int i = 0; i < MAX_N; i++) arr[i]->say();

    return 0;
}

}

namespace test2 {

class Base {
public:
    virtual void say() = 0;
};

class A : public Base {
public:
    void say() {
        cout << "class A" << endl;
    }

};

int main() {
    A a;
    a.say();


    return 0;
}

}

int main() {
    test1::main();
    test2::main();
    


    return 0;
}
