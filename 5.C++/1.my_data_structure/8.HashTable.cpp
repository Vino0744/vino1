/*************************************************************************
	> File Name: 9.map.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 04 Jun 2024 09:33:07 AM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <functional>

namespace my {

class Node {
public:
    Node() = default;
    Node(std::string key, int value, Node *next = nullptr) : __key(key), value(value), __next(next) {}
    std::string key() { return __key; }
    Node *next() { return __next; }
    void set_next(Node *next) {
        __next = next;
        return ;
    }
    void insert(Node *node) {
        node->set_next(this->next());
        this->set_next(node);
        return ;
    }
    void erase_next() {
        Node *p = this->next();
        if (p == nullptr) return ;
        this->set_next(this->next()->next());
        return ;
    }
    int value;
private:
    std::string __key;
    Node *__next;
};

class HashTable {
public:
    typedef std::function<int(std::string)> HASH_FUNC_T;
    HashTable(HASH_FUNC_T hash_func, int size = 10) : hash_func(hash_func), data(size), __size(size), data_cnt(0) {}
    bool insert(std::string key, int value = 0) {
        Node *p = __insert(key, value);
        if (data_cnt >= __size * 2) __expand();
        return p != nullptr;
    }
    bool erase(std::string key) {
        int ind = hash_func(key) % __size;
        Node *p = &data[ind];
        while (p->next() && p->next()->key() != key) p = p->next();
        if (p->next() == nullptr) return false;
        p->erase_next();
        data_cnt -= 1;
        return true;
    }
    bool find(std::string key) {
        return __find(key) != nullptr;
    }
    int capacity() { return data_cnt; }
    int &operator[](std::string key) {
        Node *p = __find(key);
        if (p) return p->value;
        insert(key, 0);
        return __find(key)->value;
    }
    ~HashTable() {
        for (int i = 0; i < __size; i++) {
            while (data[i].next()) data[i].erase_next();
        }
        return ;
    }
private:
    Node *__insert(std::string key, int value) {
        if (find(key)) return nullptr;
        int ind = hash_func(key) % __size;
        Node *ret;
        data[ind].insert((ret = new Node(key, value)));
        data_cnt += 1;
        return ret;
    }
    Node *__find(std::string key) {
        int ind = hash_func(key) % __size;
        Node *p = data[ind].next();
        while (p && p->key() != key) p = p->next();
        return p;
    }
    void swap(HashTable &h) {
        std::swap(__size, h.__size);
        std::swap(data_cnt, h.data_cnt);
        std::swap(data, h.data);
        std::swap(hash_func, h.hash_func);
        return ;
    }
    void __expand() {
        HashTable h(hash_func, __size * 2);
        for (int i = 0; i < __size; i++) {
            Node *p = data[i].next();
            while (p) {
                h.insert(p->key(), p->value);
                p = p->next();
            }
        }
        this->swap(h);
        return ;
    }
    int __size, data_cnt;
    std::vector<Node> data;
    HASH_FUNC_T hash_func;
};

int BKDRHash(std::string s) {
    int seed = 131;
    int h = 0;
    for (int i = 0; s[i]; i++) {
        h = h * seed + s[i];
    }
    return h & 0x7fffffff;
}

class APHash_Class {
public:
    int operator()(std::string s) {
        int h = 0;
        for (int i = 0; s[i]; i++) {
            if (i % 2) {
                h = (h << 3) ^ s[i] ^ (h >> 5);
            } else {
                h = ~((h << 7) ^ s[i] ^ (h >> 11));
            }
        }
        return h & 0x7fffffff;
    }
};

}

int main() {
    my::APHash_Class APHash;
    my::HashTable h1(my::BKDRHash);
    my::HashTable h2(APHash);
    int op;
    std::string s;
    std::cout << h1.capacity() << std::endl;
    std::cout << h2.capacity() << std::endl;
    h1["hello"] = 123;
    h1["world"] = 456;
    h1["haizei"] = 789;
    std::cout << h1.capacity() << std::endl;
    std::cout << h2.capacity() << std::endl;
    std::cout << h1["hello"] << " " << h1["world"] << " " << h1["hahaha"] << std::endl;
    while (std::cin >> op >> s) {
        switch(op) {
            case 0: {
                std::cout << "insert " << s << " to hash table 1 = ";
                std::cout << h1.insert(s) << std::endl;
                std::cout << "insert " << s << " to hash table 2 = ";
                std::cout << h2.insert(s) << std::endl;
            } break;
            case 1: {
                std::cout << "erase " << s << " from hash table 1 = ";
                std::cout << h1.erase(s) << std::endl;
                std::cout << "erase " << s << " from hash table 2 = ";
                std::cout << h2.erase(s) << std::endl;
            } break;
            case 2: {
                std::cout << "find " << s << " at hash table 1 = ";
                std::cout << h1.find(s) << std::endl;
                std::cout << "find " << s << " at hash table 2 = ";
                std::cout << h2.find(s) << std::endl;
            } break;
        }
    }



    return 0;
}
