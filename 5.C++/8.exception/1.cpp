/*************************************************************************
	> File Name: 1.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 30 May 2024 01:44:32 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int main() {
    try {
        //可能含有的异常
        cout << "throwing" << endl;
        throw string("abc");
        cout << "will not execute" << endl; //unreachable code
    } catch (string &e) {
        cout << "caught an integer" << endl;
    } catch (...) { //捕捉其余异常
        cout << "exception caught" << endl;
    }

    return 0;
}
