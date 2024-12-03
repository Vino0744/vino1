/*************************************************************************
	> File Name: 6.pile.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 30 May 2024 04:32:47 PM CST
 ************************************************************************/

#include <iostream>

namespace my {

template<typename T>
void swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
    return ;
}

//大顶堆
template<typename T>
class priority_queue {
public:
    priority_queue(size_t n = 20) {
        data = new T[n + 1];
        cnt = 0;
        size = n;
    }
    bool empty() { return cnt == 0; }
    T top() { return data[1]; }
    bool push(T val) {
        if(cnt == size) return false;
        data[++cnt] = val;
        size_t ind = cnt;
        while (ind >> 1 && data[ind >> 1] < data[ind]) {
            swap(data[ind >> 1], data[ind]);
            ind >>= 1;
        }
        return true;
    }
    bool pop() {
        if (empty()) return false;
        swap(data[1], data[cnt--]);
        size_t ind = 1;
        while ((ind << 1) <= cnt) {
            int temp = ind, l = ind << 1, r = ind << 1 | 1;
            if (data[temp] < data[l]) temp = l;
            if (r <= cnt && data[r] > data[temp]) temp = r;
            if (ind == temp) return true;
            swap(data[temp], data[ind]);
            ind = temp;
        }
        return true;
    }
    void output() {
        std::cout << "priority_queue : " << std::endl;
        for (size_t i = 1; i <= cnt; i++) std::cout << data[i] << " ";
        std::cout << std::endl;
    }
    ~priority_queue() {
        delete data;
    }
private:
    T *data;
    size_t cnt, size;
};

}

int main() {
    my::priority_queue<int> pq(30);
    pq.push(20); 
    pq.push(15); 
    pq.push(25); 
    pq.push(27); 
    pq.push(18); 
    pq.push(23); 
    pq.push(14); 
    pq.push(16); 
    pq.push(24); 
    pq.push(16); 
    pq.output();
    pq.pop();
    pq.output();

    return 0;
}
