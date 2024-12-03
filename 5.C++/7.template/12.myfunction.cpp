/*************************************************************************
	> File Name: 12.myfunction.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 21 Oct 2024 01:01:23 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

template<typename T, typename ...ARGS>
class Base {
public:
    virtual T run(ARGS...) = 0;
    virtual Base<T, ARGS...> *funcCopy() = 0;
    // virtual ~Base();
};

template<typename T, typename ...ARGS>
class normal_function : public Base<T, ARGS...> {
public:
    normal_function(T (*ptr)(ARGS...)) : func(ptr) {};
    T run(ARGS... args) override {
        return func(forward<ARGS>(args)...);
    }
    Base<T, ARGS...> *funcCopy() override {
        return new normal_function(this->func);
    }
private:
    T (*func)(ARGS...);
};

template<typename CLASS_T, typename T, typename ...ARGS>
class functor : public Base<T, ARGS...> {
public:
    functor(CLASS_T func) : func(func) {};
    T run(ARGS... args) override {
        return func(forward<ARGS>(args)...);
    }
    Base<T, ARGS...> *funcCopy() override {
        return new functor(this->func);
    }
private:
    CLASS_T func;
};

template<typename T, typename ...ARGS> class function {};
template<typename T, typename ...ARGS>
class function<T(ARGS...)> {
public:
    function(T (*ptr)(ARGS...)) : func(new normal_function<T, ARGS...>(ptr)) {};

    template<typename CLASS_T>
    function(CLASS_T obj) : func(new functor<CLASS_T, T, ARGS...>(obj)) {};

    T operator()(ARGS... args) {
        return func->run(forward<ARGS>(args)...);
    } 

    function &operator=(function<T(ARGS...)> obj) {
        delete this->func;
        this->func = obj.func->funcCopy();
        return *this;
    }
private:
    Base<T, ARGS...> *func;
};

int add(int a, int b) {
    cout << "normal function : ";
    return a + b;
}

class ADD_MULT {
public:
    ADD_MULT(int x) : x(x) {}
    int operator()(int a, int b) {
        cout << "functor : ";
        return (a + b) * 2;
    }
private:
    int x;
};

int main() {
    ADD_MULT add_mult(2);
    function<int(int, int)> f1 = add;
    function<int(int, int)> f2 = add_mult;
    cout << f1(3, 4) << endl;
    cout << f2(3, 4) << endl;
    f1 = f2;
    cout << f1(3, 4) << endl;


    return 0;
}
