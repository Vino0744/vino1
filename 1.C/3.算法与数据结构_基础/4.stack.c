/*************************************************************************
	> File Name: 3.queue.c
	> Author: 
	> Mail: 
	> Created Time: Tue 25 Jul 2023 10:28:25 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//定义
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

void output(Stack *s) {
    if (s == NULL) return ;
    if (empty(s)) return ;
    int len = 0;
    printf("\n");
    for (int i = 0; i <= s->top; i++) len += printf("%4d", s->data[i]);
    printf("\n");
    for (int i = 0; i < len; i++) printf("-");
    printf("\n");
    for (int i = 0; i <= s->top; i++) printf("%4d", i);
    printf("\n");
    return ;
}

int main() {
    srand(time(0));
    Stack *s = initStack(8);
    int op;
    int val;
    for (int i = 0; i < 20; i++) {
        op = rand() % 4;//0\1\2是入队,3是出队
        switch (op) {
            case 0:
            case 1:
            case 2: {
                val = rand() % 1000;
                printf("push %d in stack!\n", val);
                push(s, val);
            } break;
            case 3: {
                printf("erase stack!\n");
                pop(s);
            } break;
        }
        output(s);
    }
    return 0;
}
