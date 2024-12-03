/*************************************************************************
	> File Name: 9.template_args.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 25 Jul 2024 02:49:57 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

#define BEGIN(x) namespace x {
#define END(x) }

BEGIN(test1)

class A {
public:
    A(int x, int y) : x(x), y(y) {}
    int x, y;
};

ostream &operator<<(ostream &out, const A &a) {
    out << "class A : " << a.x << ", " << a.y;
    return out;
}

template<typename T>
void Print(T a) {
    cout << a << endl;
    return ;
}

template<typename T, typename ...ARGS>
void Print(T a, ARGS... args) {
    cout << a << " | ";
    Print(args...);
    return ;
}

int main() {
    A a(2, 3);
    Print("hello world");
    Print("hello", 3, 6.7, a);
    Print(a, 3.4, "hello", 3);
    return 0;
}

END(test1)

BEGIN(test2)

template<typename T, typename ...ARGS>
class ARG {
public:
    typedef T type;
    typedef ARG<ARGS...> rest;
};

template<typename T>
class ARG<T> {
public:
    typedef T type;
};

template<typename T, typename ...ARGS>
class Test {
public:
    T operator()(typename ARG<ARGS...>::type a, typename ARG<ARGS...>::rest::type b) {
        return a + b;
    }
};

int main() { 
    Test<int, int, int> t1;
    Test<double, double, int> t2;
    cout << t1(3, 4) << endl;
    cout << t2(5.2, 3) << endl;
    return 0;
}

END(test2)

BEGIN(test3)

template<typename T, typename ...ARGS>
class ARG {
public:
    typedef T type;
    typedef ARG<ARGS...> rest;
};

template<typename T>
class ARG<T> {
public:
    typedef T ftype;
};

template<typename T, typename ...ARGS>
class Test {
public:
    T operator()(typename ARG<ARGS...>::type a, typename ARG<ARGS...>::rest::ftype b) {
        return a + b;
    }
};

int main() {
    Test<int, int, int> t1;
    Test<double, double, int> t2;
    //Test<double, int, int, int> t3;
    cout << t1(3, 4) << endl;
    cout << t2(5.2, 3) << endl;
    return 0;
}

END(test3)

BEGIN(test4)

template<typename T, typename ...ARGS>
class ARG {
public:
    typedef T type;
    typedef ARG<ARGS...> rest;
};

template<typename T>
class ARG<T> {
public:
    typedef T ftype;
};

template<typename T, typename ...ARGS> class Test;
template<typename T, typename ...ARGS>
class Test<T(ARGS...)> {
public:
    T operator()(typename ARG<ARGS...>::type a, typename ARG<ARGS...>::rest::ftype b) {
        return a + b;
    }
};

int main() {
    Test<int(int, int)> t1;
    Test<double(double, int)> t2;
    cout << t1(3, 4) << endl;
    cout << t2(5.2, 3) << endl;
    return 0;
}

END(test4)

BEGIN(test5)

template<int M>
void Print() {
    cout << M << ", ";
    Print<M - 1>();
    return ;
}

template<>
void Print<1>() {
    cout << "1" << endl;
    return ;
}

int main() {
    Print<10>();
    return 0;
}

END(test5)

BEGIN(test6)

template<int N, typename T, typename ...ARGS>
class ARG {
public:
    typedef typename ARG<N - 1, ARGS...>::type type;
};

template<typename T, typename ...ARGS>
class ARG<1, T, ARGS...> {
public:
    typedef T type;
};

template<typename T>
class ARG<1, T> {
public:
    typedef T type;
};

template<typename T, typename ...ARGS>
class NUM_ARGS {
public:
    static constexpr int r = NUM_ARGS<ARGS...>::r + 1;
};

template<typename T>
class NUM_ARGS<T> {
public:
    static constexpr int r = 1;
};

template<int N>
class Zero {
public:
    typedef int no;
};

template<>
class Zero<0> {
public:
    typedef int yes;
};

template<typename T, typename ...ARGS> class Test;
template<typename T, typename ...ARGS>
class Test<T(ARGS...)> {
public:
    typedef typename Zero<2 - NUM_ARGS<ARGS...>::r>::yes TYPE_NUM_2;
    T operator()(typename ARG<1, ARGS...>::type a, typename ARG<2, ARGS...>::rest::ftype b) {
        return a + b;
    }
};

int main() {
    //Test<bool(int, int)> t1;
    //cout << t1(3, 4) << endl;
    Test<bool(int, int, int)> t2;

    return 0;
}

END(test6)

int main() {
    //test1::main();
    //test2::main();
    //test3::main();
    //test4::main();
    //test5::main();
    test6::main();
    return 0;
}
