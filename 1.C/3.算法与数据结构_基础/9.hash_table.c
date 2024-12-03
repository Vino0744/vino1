/*************************************************************************
	> File Name: 9.hash_table.c
	> Author: 
	> Mail: 
	> Created Time: Fri 04 Aug 2023 11:21:40 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char *str;
    struct Node *next;
} Node;

typedef struct HashTable {
    Node **data;
    int size;
} HashTable;

Node *initNode(char *str, Node *head) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->str = strdup(str);
    p->next = head;
    return p;
}

HashTable *initHashTable(int size) {
    HashTable *h = (HashTable *)malloc(sizeof(HashTable));
    h->size = size << 1;
    h->data = (Node **)malloc(sizeof(Node *) * h->size);
    return h;
}

//计算字符串的哈希值
int BKDR_Hash(char *str) {
    int seed = 31, hash = 0;
    for (int i = 0; str[i]; i++) {
        hash = hash * seed + (str[i] - '0');
    }
    return hash & 0x7fffffff;
}

void insert(HashTable *h, char *str) {
    int hash = BKDR_Hash(str);
    int ind = hash % h->size;
    h->data[ind] = initNode(str, h->data[ind]);
    return ;
}

int search(HashTable *h, char *str) {
    int hash = BKDR_Hash(str);
    int ind = hash % h->size;
    Node *p = h->data[ind];
    while (p) {
        if (strcmp(p->str, str) == 0) return 1;
        p = p->next;
    }
    return 0;
}

void clear_Node (Node *node) {
    if (node == NULL) return ;
    Node *p = node, *q;
    while (p) {
        q = p->next;
        free(p->str);
        free(p);
        p = q;
    }
    return ;
}

void clear_Hash(HashTable *h) {
    if (h == NULL) return ;
    for (int i = 0; i < h->size; i++) clear_Node(h->data[i]);
    free(h->data);
    free(h);
    return ;
}

int main() {
    int op;
    char str[100] = {0};
    HashTable *h = initHashTable(100);
    while (~scanf("%d%s", &op, str)) {
        switch(op) {
            case 0: {
                printf("insert %s in hash table\n", str);
                insert(h, str);
            } break;
            case 1: {
                printf("search %s in hash table\n", str);
                if (search(h, str)) printf("\033[34mExist!\033[0m\n");
                else printf("\033[32mNot found!\033[0m\n");
            }
        }
    }
    clear_Hash(h);
    return 0;
}
