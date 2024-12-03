/*************************************************************************
	> File Name: 1.sort.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 22 Oct 2024 03:17:51 PM CST
 ************************************************************************/

#include<iostream>
#include<functional>
using namespace std;

//使用do {} while(0) 的作用：
//1、代码歧义
//2、支持的代码设计方式更多，设计分支结构等

//防止未使用的变量被优化 __x = __x;
#define __STL__REQUESTS(type, __concept) do { \
    function<void()> __x =  __concept<type>::__operator_concept; \
    __x = __x; \
} while(0);

//这段代码毫无意义，并不会真的被执行
template<typename type>
class _LessThanComparable {
public:
    static void __operator_concept() {
        function<type(type, type)> __x = __inner__operator_concept;
    }

    static type __inner__operator_concept(type a, type b) {
        if (a < b) return a;
        else return b;
    }
};

template<typename type>
class _DefaultConstructor {
public:
    static void __operator_concept() {
        function<void()> __x = __inner__operator_concept;
    }

    static void __inner__operator_concept() {
        type a;
        return ;
    }
};

template<typename type>
class _PreIncresment {
public:
    static void __operator_concept() {
        function<type(type)> __x = __inner__operator_concept;
    }

    static type __inner__operator_concept(type a) {
        ++a;
        return a;
    }
};

template<typename type>
class _Dereference {
public:
    static void __operator_concept() {
        function<type(type)> __x = __inner__operator_concept;
    }

    static type __inner__operator_concept(type a) {
        *a;
        return a;
    }
};

template<typename type>
class _IsPointerType {
public:
    static void __operator_concept() {
        function<type(type)> __x = __inner__operator_concept;
    }

    static type __inner__operator_concept(type a) {
        *a;
        ++a;
        // a++;
        // a--;
        // --a;
        // a += 2;
        // a -= 2;
        return a;
    }
};

class Base {
public:
    Base() = default;
    bool operator<(Base &obj) {
        return true;
    }
    void operator++() {
        return ;
    }
    void operator*() {
        return ;
    }
};



int main() {
    __STL__REQUESTS(Base, _LessThanComparable);
    __STL__REQUESTS(Base, _DefaultConstructor);
    __STL__REQUESTS(Base, _PreIncresment);
    __STL__REQUESTS(Base, _Dereference);
    __STL__REQUESTS(Base, _IsPointerType);

    return 0;
}

// 这段代码设计的精妙之处在于使用了函数指针
// 不使用模板是无法去编译模板
// 通过指针去检查语法是否存在问题来看是否存在小于比较
