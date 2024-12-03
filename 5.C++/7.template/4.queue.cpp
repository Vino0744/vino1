/*************************************************************************
	> File Name: 4.queue_stack.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 28 May 2024 10:18:01 PM CST
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
    virtual ~vector() {
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
    T *_Finish, *_M_pos;//finish是存储区域的最后一个地址，m_pos是最后一个元素所存储的位置后一位地址
    
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

template<typename T>
class queue {
public:
    typedef T* iterator;
    queue(size_t n = 10) : data(n) {
        __size = n;
        __cnt = 0;
        head = tail = data.begin();
    }
    bool full() {
        return __cnt == __size;
    }
    bool empty() {
        return __cnt == 0;
    }
    void push(const T &obj) {
        if (full()) {
            std::cout << "Error : queue is full" << std::endl;
            return ;
        }
        if (tail == data.begin() + __size) tail = data.begin();
        new(tail) T(obj);
        __cnt += 1;
        tail += 1;
        return ;
    }
    void pop() {
        if (empty()) {
            std::cout << "Error : queue is empty" << std::endl;
            return ;
        }
        if (head == data.begin() + __size) head = data.begin();
        __cnt -= 1;
        head += 1;
        return ;
    }
    void output() {
        std::cout << "queue : ";
        if (empty()) return ;
        if (head < tail) {
            T *p = head;
            while (p < tail) {
                std::cout << *p << " ";
                p += 1;
            }
        } else {
            T *p = head;
            while (p < data.begin() + __size) {
                std::cout << *p << " ";
                p += 1;
            }
            p = data.begin();
            while (p < tail) {
                std::cout << *p << " ";
                p += 1;
            }
        }
        std::cout << std::endl;
        return ;
    }
    ~queue() {
        head = tail = nullptr;
    }
public:
    size_t __size, __cnt;
    my::vector<T> data;
    iterator head, tail;
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
    my::queue<int> q1;
    while (1) {
        int ch;
        std::cin >> ch;
        if (ch == 0) break;
        switch(ch) {
            case 1: {
                int x;
                std::cin >> x;
                q1.push(x);
            } break;
            case 2: {
                q1.pop();
            } break;
        }
        q1.output();
    }

    //my::queue<float> q2;



    return 0;
}
