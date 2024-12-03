/*************************************************************************
	> File Name: 2.LinkedList.c
	> Author: 
	> Mail: 
	> Created Time: Fri 21 Jul 2023 05:17:27 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//定义
typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct LinkedList {
    Node *head;
    int len;
} LinkedList;

//操作:链表初始化，插入，删除，清空

Node *getNewNode(int val) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = val;
    p->next = NULL;
    return p;
}

LinkedList *initLinkedList() {
    LinkedList *l = (LinkedList *)malloc(sizeof(LinkedList));
    l->head = getNewNode(0);
    l->len = 0;
    return l;
}

int insert(LinkedList *l, int ind, int val) {
    if (l == NULL) return 0;
    if (l->len < ind) {
        printf("\033[31mThe ind is error!\033[0m\n");
        return 0;
    }
    printf("insert %d in %d\n", val, ind);
    Node *p = getNewNode(val);
    Node *q = l->head;
    for (int i = 0; i < ind; i++) q = q->next;
    p->next = q->next;
    q->next = p;
    l->len += 1;
    return 1;
}

int delete_1(LinkedList *l, int ind) {
    if (l == NULL) return 0;
    if (l->len <= ind) {
        printf("\033[31mThe ind is error!\033[0m\n");
        return 0;
    }
    printf("delete %d\n", ind);
    Node *p = l->head;
    for (int i = 0; i < ind; i++) p = p->next;
    if (ind == l->len - 1) p->next = NULL;
    else p->next = p->next->next;
    l->len -= 1;
    return 1;
}

int find(LinkedList *l, int ind) {
    if (l == NULL) return 0;
    if (l->len <= ind) {
        printf("\033[31mThe ind is error!\033[0m\n");
        return 0;
    }
    Node *p = l->head;
    for (int i = 0; i < ind; i++) p = p->next;
    printf("find %d is %d\n", ind,  p->next->data);
    return 1;
}

void clear(LinkedList *l) {
    Node *p = l->head;
    Node *q = p;
    for (int i = 0; i <= l->len; i++) {
        p = p->next;
        free(q);
        q = p;
    }
    return ;
}

void output(LinkedList *l) {
    Node *p = l->head;
    for (int i = 0; i < l->len; i++) {
        i && printf("->");
        printf("%d", p->next->data);
        p = p->next;
    }
    printf("\n");
    return ;
}

int main() {
    srand(time(0));
    LinkedList *l = initLinkedList();
    int ind, val;
    int op;//0\1\2是增加元素，3是删除元素
    for (int i = 0; i < 20; i++) {
        op = rand() % 4;
        ind = rand() % (l->len + 1);
        switch(op) {
            case 0:
            case 1:
            case 2: {
                val = rand() % 1000;
                insert(l, ind, val);
            } break;
            case 3: {
                delete_1(l, ind);
            } break;
        }
        output(l);
    }
    clear(l);
    return 0;
}
