/*************************************************************************
	> File Name: 5.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 13 May 2024 09:56:48 PM CST
 ************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

class BigInt : private vector<int> {
public:
    using reverse_iterator = vector<int>::reverse_iterator;
    using const_reverse_iterator = vector<int>::const_reverse_iterator;

    reverse_iterator rbegin() { return vector<int>::rbegin(); }
    const_reverse_iterator rbegin() const { return vector<int>::rbegin(); }
    const_reverse_iterator rend() const { return vector<int>::rend(); }

    BigInt() { push_back(0); }
    BigInt(int x) {
        push_back(x);
        process_digit();
    }
    BigInt &operator+=(const BigInt &a) {
        for (size_t i = 0; i < a.size(); i++) {
            if (i >= size()) push_back(a[i]);
            else at(i) += a[i];
        }
        process_digit();
        return *this;
    }
    BigInt operator+(const BigInt &a) const {
        BigInt ret = *this;
        ret += a;
        return ret;
    }
    void process_digit() {
        for (size_t i = 0; i < size(); i++) {
            if (at(i) <= 9) continue;
            if (i == size() - 1) push_back(0);
            at(i + 1) += at(i) / 10;
            at(i) %= 10;
        }
    }
};

ostream &operator<<(ostream &out, const BigInt &a) {
    for (auto x = a.rbegin(); x != a.rend(); ++x) {
        out << *x;
    }
    return out;
}

int main() {
    BigInt a(102398);
    BigInt b(32804);
    BigInt c = a + b;
    cout << c << endl;

    return 0;
}

