/*************************************************************************
	> File Name: 2.generic_class.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 27 May 2024 09:15:07 AM CST
 ************************************************************************/

#include <iostream>
#include <ctime>
#include <algorithm>
#include <functional>
using std::cout;
using std::end;

#define MAX_N 10

int *getRandData(int n) {
    int *arr = new int[n];
    for (int i = 0; i < n; i++) arr[i] = rand() % 100;
    return arr;
}

template<typename T>
void output(T *begin, T *end) {
    printf("arr : ");
    for (T *i = begin; i < end; i++) printf("%d ", *i);
    printf("\n");
    return ;
}

bool cmp1(int a, int b) { return a > b; }

class CMP {
public:
    bool operator()(int a, int b) { return a < b; }
} cmp2;

namespace my {

template<typename T, typename Func_T>
T __median(T a, T b, T c, Func_T cmp) {
    if (cmp(b, a)) std::swap(a, b);
    if (cmp(c, b)) std::swap(c, b);
    return b;
}

template<typename iterator, typename _Compare>
void sort(iterator begin, iterator end, _Compare cmp) {
    if (end - begin < 2) return ;
    iterator x = begin, y = end - 1;
    typename std::remove_reference<decltype(*begin)>::type z = __median(*x, *(begin + (end - begin) / 2), *y, cmp);
    do {
        while (cmp(*x, z)) ++x;
        while (cmp(z, *y)) --y;
        if (x <= y) {
            std::swap(*x, *y);
            ++x, --y;
        }
    } while(x <= y);
    ++y;//区间左闭右开
    my::sort(begin, y, cmp);
    my::sort(x, end, cmp);
    return ;
}

template<typename iterator>
void sort(iterator begin, iterator end) {
    my::sort(begin, end, std::less<decltype(*begin)>());
    return ;
}

}

int main() {
    srand(time(0));

    int *arr1 = getRandData(MAX_N);
    output(arr1, arr1 + MAX_N);
    
    my::sort(arr1, arr1 + MAX_N);
    output(arr1, arr1 + MAX_N);

    my::sort(arr1, arr1 + MAX_N, cmp1);
    output(arr1, arr1 + MAX_N);

    my::sort(arr1, arr1 + MAX_N, cmp2);
    output(arr1, arr1 + MAX_N);

    my::sort(arr1, arr1 + MAX_N, std::greater<int>());
    output(arr1, arr1 + MAX_N);

    return 0;
}
