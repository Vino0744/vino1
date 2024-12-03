/*************************************************************************
	> File Name: 1.inherit.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 13 May 2024 04:45:30 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;
 
//向下派生，向上继承

class Animal {
public:
    string name;
    void say() {
        cout << this->name << endl;
        return ;
    }
};

class Cat : public Animal {
public:
    Cat() { this->name = "Cat"; }
};

class Dog : public Animal {
public :
    Dog() { this->name = "Dog"; }
};

class Snake : public Animal {
public :
    Snake() { this->name = "Snake"; }
};

int main() {
    Cat c1;
    Dog d1;
    Snake s1;
    c1.say();
    d1.say();
    s1.say();


    return 0;
}
