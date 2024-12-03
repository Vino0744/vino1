/*************************************************************************
	> File Name: 4.stack.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 30 May 2024 04:31:33 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdlib>

namespace my {

template<typename T>
class Vector {
public:
    Vector(size_t n = 2) {
        data = (T *)malloc(sizeof(T) * n);
        __size = n;
        length = 0;
    }
    bool insert(T val, size_t pos) {
        if (pos > length || pos < 0) {
            std::cout << "pos isvaild" << std::endl;
            return false;
        }
        if (__size == length && !expand()) {
            std::cout << "expand error!" << std::endl;
            return false;
        }
        for (size_t i = length; i > pos; i--) {
            data[i] = data[i - 1];
        }
        data[pos] = val;
        length += 1;
        return true;
    }
    bool erase(size_t pos) {
        if (length == 0) {
            std::cout << "vector is empty" << std::endl;
            return false;
        }
        if (pos >= length || pos < 0) {
            std::cout << "pos isvaild" << std::endl;
            return false;
        }
        for (size_t i = pos; i < length - 1; i++) {
            data[i] = data[i + 1];
        }
        length -= 1;
        return true;
    }
    T &operator[](size_t pos) { return data[pos]; }
    void output() {
        std::cout << "vector : ";
        for (size_t i = 0; i < length; i++) std::cout << data[i] << " ";
        std::cout << std::endl;
        return ;
    }
    ~Vector() {
        free(data);
    }
private:
    T *data;
    size_t __size, length;
    bool expand() {
        std::cout << "expand vector!" << std::endl;
        T *p = (T *)realloc(data, sizeof(T) * __size * 2);
        if (p == nullptr) return false;
        data = p;
        __size *= 2;
        return true;
    }
};

template<typename T>
class Node {
public:
    Node(T val = T()) : val(val), next(nullptr) {}
    T getVal() { return val; }
    Node<T> *next;
    ~Node() = default;
private:
    T val;
};

template<typename T>
class Linklist {
public:
    Linklist() {
        head = new Node<T>(0);
        len = 0;
    };
    bool insert(const T val, size_t pos) {
        if (pos > len + 1 || pos <= 0) {
            std::cout << "pos isvaild" << std::endl;
            return false;
        }
        Node<T> *node = new Node<T>(val);
        Node<T> *p = head;
        for (size_t i = 1; i < pos; i++) p = p->next;
        node->next = p->next;
        p->next = node;
        len += 1;
        return true;
    }
    bool erase(size_t pos) {
        if (pos > len || pos <= 0) {
            std::cout << "pos isvaild" << std::endl;
            return false;
        }
        Node<T> *p = head;
        for (size_t i = 1; i < pos; i++) p = p->next;
        Node<T> *q = p->next;
        p->next = p->next->next;
        delete q;
        len -= 1;
        return false;
    }
    void output() {
        std::cout << "Linklist : ";
        Node<T> *p = head;
        for (size_t i = 0; i < len; i++) {
            i && printf(" ---> ");
            p = p->next;
            std::cout << p->getVal();
        }
        std::cout << std::endl;
        return ;
    }
    ~Linklist() {
        Node<T> *p = head;
        while(p != nullptr) {
            Node<T> *next = p->next;
            delete p;
            p = next;
        }
    }
private:
    Node<T> *head;
    size_t len;
};

template<typename T>
class queue {
public:
    typedef T* iterator;
    queue(size_t n = 2) : data(n) {
        head = tail = 0;
    }
    bool empty() { return head == tail; }
    void push(T val) {
        data[tail++] = val;
        return ;
    }
    bool pop() {
        if (empty()) {
            return false;
        }
        head += 1;
        return true;
    }
    void output() {
        if (empty()) {
            std::cout << "queue is empty" << std::endl;
            return ;
        }
        std::cout << "queue : ";
        for (size_t i = head; i < tail; i++) std::cout << data[i] << " ";
        std::cout << std::endl;
        return ;
    }
private:
    my::Vector<T> data;
    size_t head, tail;
};

template<typename T>
class stack {
public:
    stack(size_t n = 2) : data(n) {
        top = -1;
    }
    bool empty() { return top == -1; }
    void push(T val) {
        data[top++] = val;
        return ;
    }
    bool pop() {
        if (empty()) {
            return false;
        }
        top -= 1;
        return true;
    }
    void output() {
        if (empty()) {
            std::cout << "stack is empty" << std::endl;
            return ;
        }
        for (size_t i = 0; i <= top; i++) std::cout << data[i] << " ";
        return ;
    }

private:
    my::Vector<T> data;
    size_t top;
};

}

int main() {
    


    return 0;
}
