/*************************************************************************
	> File Name: 2.linklist.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 30 May 2024 07:39:24 PM CST
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
        head = new Node<T>("");
        len = 0;
    };
    bool insert(T val, size_t pos) {
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

}

int main() {
    my::Linklist<std::string> linklist;
    while(1) {
        printf("输入1插入\n输入2删除\n输出0退出\n");
        int ch;
        std::cin >> ch;
        if (ch == 0) break;
        switch(ch) {
            case 1: {
                std::cout << "请分别输入插入的值和位置，用空格隔开" << std::endl;
                std::string val;
                int pos;
                std::cin >> val >> pos;
                linklist.insert(val, pos);
            } break;
            case 2: {
                std::cout << "请输入想删除的位置" << std::endl;
                int pos;
                std::cin >> pos;
                linklist.erase(pos);
            } break;
        }
        linklist.output();
    }

    return 0;
}
