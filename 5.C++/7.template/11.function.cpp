/*************************************************************************
	> File Name: 11.function.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 17 Oct 2024 04:18:13 PM CST
 ************************************************************************/

#include <iostream>
#include <functional>
using namespace std;

#define BEGIN(x) namespace x {
#define END(x) }

BEGIN(reference_param)

template<typename T>
struct remove_reference {
    typedef T type;
};

template<typename T>
struct remove_reference<T &> {
    typedef T type;
};

template<typename T>
struct remove_reference<T &&> {
    typedef T type;
};

template<typename T>
struct add_const {
    typedef const T type;
};

template<typename T>
struct add_const<const T> {
    typedef const T type;
};

template<typename T>
struct add_lvalue_reference {
    typedef T & type;
};

template<typename T>
struct add_lvalue_reference<T &> {
    typedef T & type;
};

template<typename T>
struct add_lvalue_reference<T &&> {
    typedef T & type;
};

template<typename T>
struct remove_pointer {
    typedef T type;
};

template<typename T>
struct remove_pointer<T *> {
    typedef typename remove_pointer<T>::type type;
};

template<typename T>
void func(T &&a) { // 在模板中&&符号代表的是应用，而不是右值引用。
    // 左值折叠问题：当&为奇数时为左值引用，为偶数时为右值引用，在这个问题中当传入左值时，T被推导成int&
    typename remove_reference<T>::type c;
    cout << "function T& a = " << a << endl;
    return ;
}

int main() {
    cout << sizeof(typename remove_reference<int **>::type) << endl;
    int n = 123;
    func(n);
    func(123);


    return 0;
}


END(reference_param)

BEGIN(bind_usage)

int add(int a, int b) {
    cout << "add(a, b) = ";
    return a + b;
}

void add_one(int &n) {
    n += 1;
    return ;
}

void func(int a, const char *b) {
    cout << a << " " << b << endl;
    return ;
}

int main() {
    auto t1 = bind(add, 3, 4);
    cout << t1() << endl;
    cout << t1() << endl;
    cout << t1() << endl;

    int n = 1;
    auto t2 = bind(add_one, ref(n));
    t2(), t2(), t2();
    cout << n << endl;

    //使用bind来调换参数顺序
    func(3, "hello world");
    //placeholder 参数占位符
    //调用传入参数的第n个参数
    auto t3 = bind(func, std::placeholders::_4, std::placeholders::_1);
    t3("hello world", 5, 4, 3);
    

    return 0;
}

END(bind_usage)

BEGIN(function_impl)

template<typename T, typename ...ARGS>
class Base {
public:
    virtual T run(ARGS...) = 0;
    virtual Base<T, ARGS...> *getCopy() = 0;
    virtual ~Base() {} //!
};

template<typename T, typename ...ARGS>
class normal_function : public Base<T, ARGS...> {
public:
    normal_function(T (*ptr)(ARGS...)) : func(ptr) {}
    T run(ARGS... args) override {
        return func(forward<ARGS>(args)...);
    }
    Base<T, ARGS...> *getCopy() override {
        return new normal_function(*this);
    }
private:
    T (*func)(ARGS...);
};

template<typename CLASS_T, typename T, typename ...ARGS>
class functor : public Base<T, ARGS...> {
public:
    functor(CLASS_T obj) : obj(obj) {};
    T run(ARGS... args) override {
        return obj(std::forward<ARGS>(args)...);
    }
    Base<T, ARGS...> *getCopy() {
        return new functor(*this);
    }
private:
    CLASS_T obj;
};

template<typename T, typename ...ARGS> class function;
template<typename T, typename ...ARGS>
class function<T(ARGS...)> {
public:
    function(T (*ptr)(ARGS...)) : ptr(new normal_function<T, ARGS...>(ptr)) {};
    template<typename CLASS_T>
    function(CLASS_T obj) : ptr(new functor<CLASS_T, T, ARGS...>(obj)) {};

    T operator()(ARGS... args) {
        return ptr->run(forward<ARGS>(args)...);
    }
    function &operator=(const function<T(ARGS...)> &func) {
        delete this->ptr;
        this->ptr = func.ptr->getCopy();
        return *this;
    }
    ~function() {
        delete this->ptr;
    }
private:
    Base<T, ARGS...> *ptr;
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

END(function_impl)



int main() {
    //reference_param::main();
    //bind_usage::main();
    function_impl::main();
    return 0;
}
