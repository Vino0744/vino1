/*************************************************************************
	> File Name: 5.BinarySearchTree.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 30 May 2024 04:31:55 PM CST
 ************************************************************************/

#include<iostream>

namespace my {

template<typename T>
class Node {
public:
    Node(T val = T()) : val(val), lchild(nullptr), rchild(nullptr) {}
    T val;
    Node *lchild, *rchild;
};

template<typename T>
class BST {
public:
    BST() : root(nullptr) {}
    void insert(T val) {
        __insert(root, val);
        return ;
    }
    void erase(T val) {
        __erase(root, val);
        return ;
    }
    void pre_order() {
        std::cout << "pre_order : ";
        __pre_order(root);
        std::cout << std::endl;
        return ;
    }
    void in_order() {
        std::cout << "in_order : ";
        __in_order(root);
        std::cout << std::endl;
        return ;
    }
    void post_order() {
        std::cout << "post_order : ";
        __post_order(root);
        std::cout << std::endl;
        return ;
    }
    ~BST() {
        clearBST(root);
    }
private:
    Node<T> *root;
    void __insert(Node<T> *&node, T val) {
        if (node == nullptr) {
            node = new Node<T>(val);
            return ;
        }
        if (node->val == val) return ;
        if (node->val > val) __insert(node->lchild, val);
        else __insert(node->rchild, val);
        return ;
    }
    Node<T> *findMinNode(Node<T> *&node) {
        Node<T> *ret = node;
        while(ret && ret->lchild != nullptr) ret = ret->lchild;
        return ret;
    } 
    void __erase(Node<T> *&node, T val) {
        if (node == nullptr) return ;
        if (node->val > val) {
            __erase(node->lchild, val);
        } else if (node->val < val) {
            __erase(node->rchild, val);
        } else {
            if (node->lchild == nullptr && node->rchild == nullptr) {
                Node<T> *temp = node;
                node = nullptr;
                delete temp;
                return ;
            } else if (node->rchild == nullptr) {
                Node<T> *temp = node;
                node = node->lchild;
                delete temp;
                return ;
            } else if (node->lchild == nullptr) {
                Node<T> *temp = node;
                node = node->rchild;
                delete temp;
                return ;
            } else {
                Node<T> *min = findMinNode(node->rchild);
                node->val = min->val;
                //__erase(min, min->val);
                __erase(node->rchild, min->val);
                return ;
            }
        }
        return ;
    }
    void __pre_order(Node<T> *node) {
        if (node == nullptr) return ;
        std::cout << node->val << " ";
        __pre_order(node->lchild);
        __pre_order(node->rchild);
        return ;
    }
    void __in_order(Node<T> *node) {
        if (node == nullptr) return ;
        __in_order(node->lchild);
        std::cout << node->val << " ";
        __in_order(node->rchild);
        return ;
    }
    void __post_order(Node<T> *node) {
        if (node == nullptr) return ;
        __post_order(node->lchild);
        __post_order(node->rchild);
        std::cout << node->val << " ";
        return ;
    }
    void clearBST(Node<T> *&node) {
        if (node == nullptr) return ;
        clearBST(node->lchild);
        clearBST(node->rchild);
        delete node;
        return ;
    }
};

}

int main() {
    my::BST<int> bst;
    bst.insert(20);
    bst.insert(15);
    bst.insert(25);
    bst.insert(13);
    bst.insert(18);
    bst.insert(19);
    bst.insert(22);
    bst.insert(26);
    bst.insert(23);
    bst.insert(23);
    bst.in_order();
    bst.erase(20);
    bst.in_order();

    return 0;
}
