/*************************************************************************
	> File Name: 5.AC_automation.c
	> Author: 
	> Mail: 
	> Created Time: Mon 06 Nov 2023 03:04:31 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BASE 26

typedef struct Node {
    int flag;//是否成词 1表示成词
    struct Node *next[BASE], *fail;
} Node;

typedef struct Queue {
    Node **data;
    int head, tail, size;
} Queue;

Queue *init_Queue(int size) {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->data = (Node **)malloc(sizeof(Node *) * size);
    q->head = q->tail = 0;
    q->size = size;
    return q;
}

Node *front(Queue *q) {
    return q->data[q->head];
}

int empty(Queue *q) {
    return q->head == q->tail;
}

void push(Queue *q, Node *node) {
    q->data[q->tail++] = node;
    return ;
}

void pop(Queue *q) {
    if (empty(q)) return ;
    q->head++;
    return ;
}

void clear_Queue(Queue *q) {
    if (q == NULL) return ;
    free(q->data);
    free(q);
    return ;
}

Node *getNewNode() {
    Node *p = (Node *)calloc(1, sizeof(Node));
    return p;
}

int code(char c) {
    return c - 'a';
}

//记录节点个数用于开队列
int insert(Node *root, const char *str) {
    int cnt = 0;
    Node *p = root;
    for (int i = 0; str[i]; i++) {
        int ind = code(str[i]);
        if (p->next[ind] == NULL) p->next[ind] = getNewNode(), cnt++;
        p = p->next[ind];
    }
    p->flag = 1;
    return cnt;
}

//bfs
void build_ac(Node *root, int n) {
    Queue *q = init_Queue(n + 10);
    root->fail = NULL;
    for (int i = 0; i < BASE; i++) {
        if (root->next[i] == NULL) {
            root->next[i] = root;
            continue;
        }
        root->next[i]->fail = root;
        push(q, root->next[i]);
    }
    while (!empty(q)) {
        Node *now_node = front(q);//父亲节点
        pop(q);
        for (int i = 0; i < BASE; i++) {
            if (!now_node->next[i]) {
                now_node->next[i] = now_node->fail->next[i];//建立等价路径
                continue;
            }
            //如果该路径存在，需要将第i个孩子和他的等价节点建立一个失败指针
            now_node->next[i]->fail = now_node->fail->next[i];
            push(q, now_node->next[i]);
        }
    }
    clear_Queue(q);
    return ;
}

int match(Node *root, const char *str) {
    int cnt = 0;
    Node *p = root;
    for (int i = 0; str[i]; i++) {
        int ind = code(str[i]);
        p = p->next[ind];//因为确定路径是有效的，所有的节点都不为NULL
        //回溯的过程，当前的字符串中有多少独立成词
        Node *q = p;
        while (q) cnt += q->flag, q = q->fail;
    }
    return cnt;
}

void clear(Node *root) {
    if (root == NULL) return ;
    for (int i = 0; i < BASE; i++) clear(root->next[i]);
    free(root);
    return ;
}

int main() {
    //核心是字典数和kmp组成的多模匹配 无回溯
    //失配后找到一个和自己后缀和另一个前缀相同的字符
    Node *root = getNewNode();
    int n, cnt = 0;
    scanf("%d", &n);
    char str[100];
    for (int i = 0; i < n; i++) {
        scanf("%s", str);
        cnt += insert(root, str);
    }
    //build AC
    build_ac(root, cnt);
    scanf("%s", str);
    printf("match words count = %d\n", match(root, str));
    //clear(root);
    return 0;
}
