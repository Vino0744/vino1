/*************************************************************************
	> File Name: 11.my_cout.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 28 Apr 2024 02:52:22 PM CST
 ************************************************************************/

#include<iostream>
#include <iomanip>

namespace my {

class setprecision {
public :
    setprecision(int n) : n(n) {}
    bool operator==(int n) {
        return this->n == n;
    }
    int operator()() { return n; }
private:
    int n;
};

class ostream {
public:
    ostream() : sp(-1) {}
    ostream &operator<<(const char *s) {
        printf("%s", s);
        return *this;
    }
    ostream &operator<<(const int &n) {
        printf("%d", n);
        return *this;
    }
    ostream &operator<<(const double &d) {
        char format[30];
        if (sp == -1) {
            snprintf(format, 29, "%%g");
        } else {
            snprintf(format, 29, "%%.%dg", sp());
        }
        printf(format, d);
        return *this;
    }
    ostream &operator<<(const setprecision &s) {
        sp = s;
        return *this;
    }
    setprecision sp;
};

ostream cout;
const char *endl = "\n";

}

int main() {
    std::cout << "hello world" << std::endl;
    my::cout << "hello world" << my::endl;
   
    int n = 123;
    std::cout << "n = " << n << std::endl;
    my::cout << "n = " << n << my::endl;

    double d = 1.23;
    std::cout << "d = " << d << std::endl;
    my::cout << "d = " << d << my::endl;
    
    double b = 0.12345, c = 1234.78956;
    std::cout << std::setprecision(3) << "b = " << b << " c = " << c << std::endl;
    my::cout << my::setprecision(3) << "b = " << b << " c = " << c << my::endl;
    


    return 0;
}
