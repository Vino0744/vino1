/*************************************************************************
	> File Name: 5.BinaryTree.c
	> Author: 
	> Mail: 
	> Created Time: Thu 27 Jul 2023 07:06:36 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Stack {
    int *data;
    int top;
    int size;
} Stack;

//操作
Stack *initStack(int size) {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->data = (int *)malloc(sizeof(int) * size);
    s->top = -1;
    s->size = size;
    return s;
}

int push(Stack *s, int val) {
    if (s == NULL) return 0;
    if (s->top == s->size - 1) {
        printf("\033[32mStack is full!\n\033[0m");
        return 0;
    }
    s->data[++s->top] = val;
    return 1;
}

int empty(Stack *s) {
    return s->top == -1;
}

int pop(Stack *s) {
    if (s == NULL) return 0;
    if (empty(s)) {
        printf("\033[32mStack is empty!\033[0m\n");
        return 0;
    }
    s->top -= 1;
    return 1;
}

void clear(Stack *s) {
    if (s == NULL) return ;
    free(s->data);
    free(s);
    return ;
}


//定义

typedef struct Node {
    int val;
    struct Node *lchild, *rchild;
} Node;

typedef struct Tree {
    Node *root;
    int n;
} Tree;

//操作

Node *initNewNode(int val) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->val = val;
    p->lchild = p->rchild = NULL;
    return p;
}

Tree *getNewTree() {
    Tree *tree = (Tree *)malloc(sizeof(Tree));
    tree->root = NULL;
    tree->n = 0;
    return tree;
}

//BST

Node *__insert(Node *root, int val, int *flag) {
    if (root == NULL) {
        *flag = 1;
        return initNewNode(val);
    }
    if (root->val == val) return root;
    if (val > root->val) root->rchild = __insert(root->rchild, val, flag);
    else root->lchild = __insert(root->lchild, val, flag);
    return root;
}

void insert(Tree *tree, int val) {
    int flag = 0;
    tree->root = __insert(tree->root, val, &flag);
    tree->n += flag;
    return ;
}

//三种遍历输出

void __pre_order(Node *root) {
    if (root == NULL) return ;
    printf("%d ", root->val);
    __pre_order(root->lchild);
    __pre_order(root->rchild);
    return ;
}

void pre_order(Tree *tree) {
    printf("Pre_order : ");
    __pre_order(tree->root);
    printf("\n");
    return ;
}

void __in_order(Node *root) {
    if (root == NULL) return ;
    __in_order(root->lchild);
    printf("%d ", root->val);
    __in_order(root->rchild);
    return ;
}

void in_order(Tree *tree) {
    printf("In_order : ");
    __in_order(tree->root);
    printf("\n");
    return ;
}

void __post_order(Node *root) {
    if (root == NULL) return ;
    __post_order(root->lchild);
    __post_order(root->rchild);
    printf("%d ", root->val);
    return ;
}

void post_order(Tree *tree) {
    printf("Post_order : ");
    __post_order(tree->root);
    printf("\n");
    return ;
}

//广义表输出

void table(Node *root) {
    if (root == NULL) return ;
    printf("%d", root->val);
    if (root->lchild == NULL && root->rchild == NULL) return ;
    printf("(");
    if (root->lchild) table (root->lchild);
    printf(",");
    if (root->rchild) table (root->rchild);
    printf(")");
    return ;
}

void output(Tree *tree) {
    if (tree == NULL) return ;
    printf("table : ");
    table(tree->root);
    printf("\n");
    return ;
}

Node *build(char *str) {
    Node **s = (Node **)malloc(sizeof(Node *) * 100);
    Node *p = NULL, *root = NULL;
    int flag = 0, scode = 0, top = -1;
    for (int i = 0; str[i]; i++) {
        switch (scode) {
            case 0: {
                if (str[i] >= '0' && str[i] <= '9') scode = 1;
                else if (str[i] == '(') scode = 2;
                else if (str[i] == ',') scode = 3;
                else if (str[i] == ')') scode = 4;
                i -= 1;
            } break;
            case 1: {
                int data = 0;
                while (str[i] >= '0' && str[i] <= '9') {
                    data = data * 10 + (str[i] - '0');
                    i += 1;
                }
                i -= 1;
                p = initNewNode(data);
                if (top >= 0 && flag == 0) s[top]->lchild = p;
                else if (top >= 0 && flag == 1) s[top]->rchild = p;
                scode = 0;
            } break;
            case 2: {
                s[++top] = p;
                scode = 0;
            } break;
            case 3: {
                flag = 1;
                scode = 0;
            } break;
            case 4: {
                //root = s[top--];
                flag = 0;
                scode = 0;
            } break;
        }
    }
    return s[0];
}

void ClearNode(Node *root) {
    if (root == NULL) return ;
    ClearNode(root->lchild);
    ClearNode(root->rchild);
    free(root);
    return ;
}

void ClearTree(Tree *tree) {
    if (tree == NULL) return ;
    ClearNode(tree->root);
    free(tree);
    return ;
}

int main() {
    srand(time(0));
    /*
    Tree *tree = getNewTree();
    for (int i = 0; i < 10; i++) {
        int val = rand() % 100;
        insert(tree, val);
    }
    pre_order(tree);
    in_order(tree);
    post_order(tree);
    output(tree);
    ClearTree(tree);
    */
    char str[100] = "130(8,9(,20))";
    __pre_order(build(str));
    return 0;
}
