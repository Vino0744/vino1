/*************************************************************************
	> File Name: 12.my_map.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 28 Apr 2024 04:47:31 PM CST
 ************************************************************************/

#include <iostream>
#include <map>
#include <functional>

//map<string, int>
//底层红黑树（二叉排序树）

namespace my {

std::string key(const std::pair<std::string, int> &v) {
    return v.first;
}

class Node {
public:
    typedef std::pair<std::string, int> value_type;
    Node(const value_type &data = value_type("", 0), Node *father = nullptr) : data(data), lchild(nullptr), rchild(nullptr), father(father){}
    value_type data;
    Node *father;
    Node *lchild, *rchild;
};

class binary_search_tree {
public :
    typedef std::string key_type;
    typedef std::pair<std::string, int> value_type;
    typedef std::function<const std::string(const value_type &)> select_key;
    binary_search_tree(select_key key) : key(key) {}
    Node *getNewNode(const value_type &v, Node *father) {
        return new Node(v, father);
    }
    Node *insert(Node *root, const value_type &v, Node *father) {
        if (root == NULL) return getNewNode(v, father);
        if (key(root->data) == key(v)) return root;
        if (key(root->data) > key(v)) {
            root->lchild = insert(root->lchild, v, root);
        } else { 
            root->rchild = insert(root->rchild, v, root);
        }
        return root;
    }
    Node *find(Node *root, const key_type &k) {
        if (root == NULL) return nullptr;
        if (key(root->data) == k) return root;
        if (key(root->data) > k) {
            return find(root->lchild, k);
        } else {
            return find(root->rchild, k);
        }
    }
    static Node *leftmost(Node *root) {
        Node *temp = root;
        while (temp->lchild) temp = temp->lchild;
        return temp;
    }
    static Node *successors(Node *node) {
        if (node->rchild) return leftmost(node->rchild);
        Node *father = node->father;
        while (node && node != father->lchild) {
            node = father;
            father = node->father;
        }
        return father;
    }
private :
    select_key key;
};

class binary_search_tree_iterator {
public:
    typedef std::pair<std::string, int> value_type;
    binary_search_tree_iterator(Node *node) : node(node) {}
    value_type *operator->() {
        return &(node->data);
    }
    bool operator==(const binary_search_tree_iterator &iter) {
        return node == iter.node;;
    }
    bool operator!=(const binary_search_tree_iterator &iter) {
        return !(*this == iter);
    }
    binary_search_tree_iterator operator++(int) {
        binary_search_tree_iterator iter(*this);
        node = binary_search_tree::successors(node);
        return iter;
    }
    binary_search_tree_iterator &operator++() {
        node = binary_search_tree::successors(node);
        return *this;
    }
    value_type operator*() {
        return node->data;
    }
private:
    Node *node;
};

class map {
public :
    typedef std::string key_type;
    typedef int data_type;
    typedef std::pair<key_type, data_type> value_type;
    typedef binary_search_tree_iterator iterator;
    map() : tree(key), root(new Node()) {}
    iterator begin() { return tree.leftmost(root); }
    iterator end() { return root; }
    iterator find(const key_type &key) {
        Node *ret = tree.find(root->lchild, key);
        if (ret == nullptr) return root;
        return ret;
    }
    data_type &operator[](const key_type &key_value) {
        if (find(key_value) == end()) {
            root->lchild = tree.insert(root->lchild, value_type(key_value, 0), root);
        }
        return find(key_value)->second;
    }
private :
    binary_search_tree tree;
    Node *root;
};

}

int main() {
    std::map<std::string, int> std_map;
    my::map my_map;

    std::cout << "std_map : " << std::endl;
    std_map["Hello"] = 123;
    std_map["world"] = 456;
    std_map["captain"] = 789;
    std_map["hu"] = 10086;
    std::cout << std_map["haha"] << std::endl;
    std::cout << std_map["hello"] << std::endl;
    std::cout << std_map["hu"] << std::endl;
    
    for (auto x : std_map) {
        std::cout << x.first << " " << x.second << std::endl;
    }
    
    std::cout << "\nmy_map : " << std::endl;
    my_map["Hello"] = 123;
    my_map["world"] = 456;
    my_map["captain"] = 789;
    my_map["hu"] = 10086;
    std::cout << my_map["haha"] << std::endl;
    std::cout << my_map["hello"] << std::endl;
    std::cout << my_map["hu"] << std::endl;
    
    // for (my::map::iterator iter = my_map.begin(); iter != my_map.end(); iter++) {
    //     std::cout << iter->first << " " << iter->second << std::endl;
    // }

    for (auto x : my_map) {
        std::cout << x.first << " " << x.second << std::endl;
    }

    return 0;
}
