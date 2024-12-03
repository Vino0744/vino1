/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 23 May 2024 08:53:08 PM CST
 ************************************************************************/

#include "pai.h"
#include "tree.h"
#include <stack>

int a[MAX_N + 5] = {0};
int b[MAX_N + 5] = {0};

void read(FILE *file, int *arr) {
    int x;
    while (fscanf(file, "%d", &x) != EOF) {
        if (x == 0) break;
        arr[x] += 1;
    }
    return ;
}

void read_data() { 
    FILE *fin = fopen("input.txt", "r");
    read(fin, a);
    read(fin, b);
    fclose(fin);
    return ;
}

void output_solution(Node *root, int *a, int *b) {
    stack<Node *> s;
    s.push(root);
    while (!s.empty()) {
        printf("%s : ", s.size() % 2 ? "--->" : "    "); PAI::output_arr(a);
        printf("%s : ", s.size() % 2 ? "    " : "--->"); PAI::output_arr(b);
        Node *node = s.top();
        int num;
        do {
            printf("[%3d] : back\n", -1);
            for (int i = 0; i < node->child.size(); i++) {
                printf("[%3d]%s : ", i, (node->child[i]->win ? "" : "(win)"));
                node->child[i]->p->output() << endl;
            }
            cout << "input : ";
            cin >> num;
            if (num >= -1 && num < node->child.size()) break;
        } while (1);
        if (num == -1) {
            node->p->back(s.size() % 2 ? a : b);
            s.pop();
        } else {
            node->child[num]->p->take(s.size() % 2 ? a : b);
            s.push(node->child[num]);
        }
        if (checkEmpty(a)) {
            cout << "Win the game!!" << endl;
            return ;
        }
    }
    return ;
}

int main() {
    read_data();
    cout << "read data done" << endl;
    Node *root = new Node();
    cout << "start analysising..." << endl;
    getTree(root, a, b);
    cout << "start analysis done" << endl;
    output_solution(root, a, b);
    return 0;
}
