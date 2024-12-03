/*************************************************************************
	> File Name: 3.test2.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 22 May 2024 11:10:04 AM CST
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    Node(int n, int win_flag = 0) : n(n), win_flag(win_flag) {}
    void output() {
        printf("[%d, %d] : ", n, win_flag);
        for (int i = 0; i < next.size(); i++) {
            printf("%d, ", this->next[i]->n);
        }
        cout << endl;
        return ;
    }
    int n;
    vector<Node *> next;
    int win_flag;//必胜态为1
};

Node *getNewNode(int n) {
    return new Node(n);
}

Node *getTree(int n) {
    if (n == 1) return getNewNode(n);
    Node *root = getNewNode(n);
    root->next.push_back(getTree(n - 1));
    root->next.push_back(getTree(n - n / 2));
    for (int i = 0; i < root->next.size(); i++) {
        if (root->next[i]->win_flag == 1) continue;
        root->win_flag = 1;
        break;
    }
    return root;
}

void outputTree(Node *root) {
    if (root == NULL) return ;
    root->output();
    for (int i = 0; i < root->next.size(); i++) {
        outputTree(root->next[i]);
    }
    return ;
}

int main() {
    int n; cin >> n;
    Node *root = getTree(n);
    outputTree(root);

    return 0;
}
