/*************************************************************************
	> File Name: 3.generic_class.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 28 May 2024 08:43:58 AM CST
 ************************************************************************/

#include <iostream>
#include <cstdlib>

namespace my {

template<typename T>
class vector {
public:
    typedef T *iterator;
    vector(size_t n = 2) {
        __size = n;
        data = (T *)malloc(sizeof(T) * __size);
        _Finish = data + __size;
        _M_pos = data;
    }
    vector(const vector &v) {
        __size = v.__size;
        data = (T *)malloc(sizeof(T) * __size);
        for (size_t i = 0; i < v.size(); i++) {
            new(data + i) T(v[i]);
        }
        _M_pos = data + v.size();
        _Finish = data + __size;
    }
    vector(vector &&v) {
        __size  = v.__size;
        data    = v.data;
        _M_pos  = v._M_pos;
        _Finish = v._Finish;
        v.__size = v.data = v._M_pos = v._Finish = nullptr;
    }
    iterator begin() { return data; }
    iterator end() { return _M_pos; }
    T &operator[](size_t ind) const { return data[ind]; }
    void push_back(const T &obj) {
        if (_M_pos == _Finish && !__expend()) {
            std::cout << "expand failed" << std::endl;
            return ;
        }
        new(_M_pos) T(obj);
        _M_pos += 1;
        return ;
    }
    size_t size() const { return _M_pos - data; }
    ~vector() {
        if (data == nullptr) return ;
        for (size_t i = 0; i < size(); i++) {
            data[i].~T();
        }
        free(data);
        return ;
    }
private:
    size_t __size;//总大小
    T *data;//数据存储区
    T *_Finish, *_M_pos;//finish是存储区域的最后一个地址，m_pos是最后一个元素所村粗的位置后一位地址
    
    bool __expend() {
        T *p = (T *)realloc(data, sizeof(T) * __size * 2);
        if (p == nullptr) return false;
        size_t offset = _M_pos - data;
        data = p;
        __size *= 2;
        _M_pos = data + offset;
        _Finish = data + __size;
        return true;
    }
}; 

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

}// end of namespace my

int main() {
    #define MAX_N 10
    srand(time(0));

    my::vector<int> v1;
    for (int i = 0; i < 10; i++) v1.push_back(rand() % 100); 
    for (auto x : v1) std::cout << x << " "; std::cout << std::endl;
    my::sort(v1.begin(), v1.end());
    for (auto x : v1) std::cout << x << " "; std::cout << std::endl; 

    my::vector<float> v2;
    for (int i = 0; i < 10; i++) v2.push_back(rand() % 10000 * 1.0 / 100.0); 
    for (auto x : v2) std::cout << x << " "; std::cout << std::endl;
    my::sort(v2.begin(), v2.end());
    for (auto x : v2) std::cout << x << " "; std::cout << std::endl; 

    my::vector<my::vector<int>> v3;
    for (int i = 0; i < 3; i++) {
        v3.push_back(my::vector<int>());
        for (int j = 0; j < 4; j++) {
            v3[i].push_back(0);
        }
    }
    my::vector<my::vector<int>> v4(v3);
    v3[1][2] = 123;
    for (auto x : v3) {
        for (auto y : x) {
            std::cout << y << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "================" << std::endl;
    for (auto x : v4) {
        for (auto y : x) {
            std::cout << y << " ";
        }
        std::cout << std::endl;
    }



    return 0;
}
