/*************************************************************************
	> File Name: 2.trie.c
	> Author: 
	> Mail: 
	> Created Time: Thu 19 Oct 2023 08:39:51 AM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BASE 26

#define COLOR(a, b) "\033[" #b "m" a "\033[0m"

#define RED(a) COLOR(a, 31)
#define GREEN(a) COLOR(a, 32)
#define YELLOW(a) COLOR(a, 33)
#define BULE(a) COLOR(a, 34)

typedef struct Node {
    int flag;//是否独立成词
    struct Node *next[BASE];
} Node;

Node *getNewNode() {
    Node *p = (Node *)malloc(sizeof(Node));
    p->flag = 0;
    memset(p->next, 0, sizeof(Node *) * BASE);
    return p;
}

int code(char c) {
    return c - 'a';
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
    Node *p = root;
    for (int i = 0; str[i]; i++) {
        int ind = code(str[i]);
        p = p->next[ind];
        if (p == NULL) return 0;
    }
    return p->flag;
}

void clear(Node *root) {
    if (root == NULL) return ;
    for (int i = 0; i < BASE; i++) clear(root->next[i]);
    free(root);
    return ;
}

int main() {
    Node *root = getNewNode();
    char str[100] = {0};
    while (~scanf("%s", str)) {
        if (strcmp(str, "__end__") == 0) break;
        insert(root, str);
        printf(GREEN("insert") YELLOW("  \"%s\"") " done\n", str);
    }
    while (~scanf("%s", str)) {
        printf(RED("search") BULE("  \"%s\"") " ---> %d\n", str, search(root, str));
    }
    clear(root);
    return 0;
}
