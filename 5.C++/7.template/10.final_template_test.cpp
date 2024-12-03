/*************************************************************************
	> File Name: 10.final_template_test.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 30 Jul 2024 02:05:20 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

#define BEGIN(x) namespace x {
#define END(x) }

BEGIN(sum_test)

template<int M>
class sum {
public:
    static constexpr int r = M + sum<M - 1>::r;
};

template<>
class sum<1> {
public:
    static constexpr int r = 1;
};

int main() {
    cout << sum<5>::r << endl;
    cout << sum<7>::r << endl;
    cout << sum<100>::r << endl;
    return 0;
}

END(sum_test)

BEGIN(even_test)

template<int N>
class YES_OR_NO {
public:
    static const char *r;
};

template<>
class YES_OR_NO<0> {
public:
    static const char *r;
};

template<int N>
const char *YES_OR_NO<N>::r = "yes";
const char *YES_OR_NO<0>::r = "no";

template<int N>
class is_even {
public:
    static const char *r;
};

template<int N>
const char *is_even<N>::r = YES_OR_NO<!(N % 2)>::r;

int main() {
    cout << is_even<5>::r << endl; // no
    cout << is_even<6>::r << endl; // yes
    return 0;
}

END(even_test)

BEGIN(good_bad_test)

template<int M>
class score_judge {
public:
    static const string r;
};

template<int M>
class Zero {
public:
    static const string r;
};

template<int M>
const string Zero<M>::r = Zero<(M >= 60 ? 1 : 0)>::r;

template<>
const string Zero<1>::r = "good";

template<>
const string Zero<0>::r = "bad";

template<int M>
const string score_judge<M>::r = Zero<M>::r;

int main() {
    cout << score_judge<60>::r << endl; // good   
    cout << score_judge<54>::r << endl; // bad   
    return 0;
}

END(good_bad_test)

BEGIN(is_prime_test)

template<int i, int N>
struct getNext {
    static constexpr int r = (N % i ? i + 1 : 0);
};

template<int i, int N>
struct test {
    static constexpr const char *r = ((i * i > N) ? "yes" : test<getNext<i, N>::r, N>::r);
};

template<int N>
struct test<0, N> {
    static constexpr const char *r = "no"; 
};

template<int N>
struct is_prime {
    static constexpr const char *r = test<2, N>::r;
};

int main() {
    cout << "2 : " << is_prime<2>::r << endl;
    cout << "3 : " << is_prime<3>::r << endl;
    cout << "5 : " << is_prime<5>::r << endl;
    cout << "8 : " << is_prime<8>::r << endl;
    cout << "103 : " << is_prime<103>::r << endl;

    return 0;
}

END(is_prime_test)

int main() {
    sum_test::main();
    even_test::main();
    good_bad_test::main();
    is_prime_test::main();

    return 0;
}
