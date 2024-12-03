/*************************************************************************
	> File Name: 4.double_array_tire.c
	> Author: 
	> Mail: 
	> Created Time: Thu 19 Oct 2023 08:49:15 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BASE 26

typedef struct Node {
    int flag;
    struct Node *next[BASE];
} Node;

Node *getNewNode() {
    Node *p = (Node *)malloc(sizeof(Node));
    p->flag = 0;
    memset(p->next, 0, sizeof(Node *) * BASE)
    return p;
}

int code(char ch) {
    return ch - 'a';
}

void insert(Node *root, const char *str) {
    Node *p = root;
    for (int i = 0; str[i]; i++) {
        int ind = code(str[i]);
        if (p->next[ind] == NULL) p->next[ind] = getNewNode();
        p = p->next[ind];
    }
    p->flag = 1;
    return ;
}

int search(Node *root, const char *str) {
    if (root == NULL) return ;
    Node *p = root;
    for (int i = 0; str[i]; i++) {
        int ind = code(str[i]);
        if (p->next[ind] == NULL) return 0;
        p = p->next[ind];
    }
    return p->flag;
}

void output(Node *root, int k, char *buff) {
    if (root == NULL) return ;
    buff[k] = '\0';
    if (root->flag) printf("%s\n", buff);
    for (int i = 0; i < BASE; i++) {
        buff[k] = 'a' + i;
        output(root->next[i], k + 1, buff);
    }
    return ;
}

void clear(Node *root) {
    if (root == NULL) return ;
    Node *p = root;
    for (int i = 0; i < BASE; i++) clear(root->next[i]);
    free(root);
    return ;
}

int main() {



    return 0;
}
