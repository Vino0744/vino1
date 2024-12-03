/*************************************************************************
	> File Name: 6.template.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 04 Jun 2024 05:42:32 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

#define BEGINS(x) namespace x {
#define ENDS(X) } // end of namespace

BEGINS(test1)

template<typename T>
T add(T a, T b) {
    return a + b;
}

int main() {
    cout << "add(3, 4) = " << add(3, 4) << endl;
    cout << "add(3.1, 4.4) = " << add(3.1, 4.4) << endl;
    cout << "add(3.1, 4) = " << add<double>(3.1, 4) << endl;
    return 0;
}

ENDS(test1)

BEGINS(test2)

/*
 * BUGS
 *可能没有默认构造函数
template<typename T, typename U>
decltype(T() + U()) add(T a, U b) {
    return a + b;
}
*/

template<typename T, typename U>
auto add(T a, U b) -> decltype(a + b) {
    return a + b;
}

void judge(int a) {
    cout << "int type" << endl;
    return ;
}

void judge(string a) {
    cout << "string type" << endl;
    return ;
}

void judge(double a) {
    cout << "double type" << endl;
    return ;
}

int main() {
    cout << "add(3, 4) = " << add(3, 4) << endl;
    cout << "add(3.1, 4.4) = " << add(3.1, 4.4) << endl;
    cout << "add(3.1, 4) = " << add(3.1, 4) << endl;
    decltype(3 + 4.1)       a;
    decltype(3.2 + 4)       b;
    decltype(3 + 4)         c;
    decltype((string)"abc" + (string)"def") d;
    judge(a), judge(b), judge(c), judge(d);

    return 0;
}

ENDS(test2)

BEGINS(test3)

class A {
public:
    A() = delete;
    A(int x) : x(x) {}
    int x;
};

class B {
public:
    B() = delete;
    B(int x) : x(x) {}
    int x;
};

class C {
public:
    C() = delete;
    C(int x) : x(x) {}
    int x;
};

C operator+(const A &a, const B &b) {
    return C(a.x + b.x);
}

/*
BUGS : 可能没有默认构造函数
template<typename T, typename U>
decltype(T() + U()) add(T a, U b) {
    return a + b;
}

int main() {
    A a(65);
    B b(78);
    cout << "add(A + B) = " << add(a, b) << endl;


    return 0;
}
*/

ENDS(test3)

BEGINS(test4)

template<typename T>
class PrintAny {
public:
    PrintAny(ostream &out) : out(out) {}
    PrintAny Print (T a) {
        out << a;
        return *this;
    }
    PrintAny endl() {
        out << std::endl;
        return *this;
    }
private:
    ostream &out;
};

int main() {
    PrintAny<int>       pint(cout);
    PrintAny<double> pdouble(cout);
    PrintAny<string> pstring(cout);
    pint.Print(3).endl();
    pdouble.Print(3.2).endl();
    pstring.Print("hello world").endl();


    return 0;
}

ENDS(test4)

BEGINS(test5)

class PrintAny {
public:
    PrintAny(ostream &out) : out(out) {}
    template<typename T>
    PrintAny Print (T a) {
        out << a;
        return *this;
    }
    PrintAny endl() {
        out << std::endl;
        return *this;
    }
private:
    ostream &out;
};

int main() {
    PrintAny p(cout);
    p.Print(3).endl().Print(3.2).endl().Print("hello").endl();

    return 0;
}

ENDS(test5)

int main() {
    // test1::main();
    //test2::main();
    //test3::main();
    //test4::main();
    test5::main();
    return 0;
}
