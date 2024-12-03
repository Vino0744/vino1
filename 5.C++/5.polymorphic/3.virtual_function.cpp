/*************************************************************************
	> File Name: 3.virtual_function.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 20 May 2024 03:22:39 PM CST
 ************************************************************************/

#include <iostream>
#include <ctime>
using namespace std;

//virtual子类方法和父类可能不同
//virtual方法跟着对象
//非virtual方法跟着类

class Base {
public:
    virtual void say() {
        cout << "class Base" << endl;
    }
};

class Cat : public Base {
public:
    void say() override {
        cout << "class Cat" << endl;
    }
};

class Dog : public Base {
public:
    void say() override {
        cout << "class Dog" << endl;
    }
};

class Bat : public Base {
public:
    void say() override {
        cout << "class Bat" << endl;
    }
};

int main() {
    #define MAX_N 10
    srand(time(0));
    Base *arr[MAX_N + 5];
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
