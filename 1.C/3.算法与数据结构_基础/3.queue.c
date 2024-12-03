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
typedef struct Queue {
    int *data;
    int head, tail;
    int size, count;
} Queue;

//操作
Queue *initQueue(int size) {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->data = (int *)malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) q->data[i] = -1;
    q->head = q->tail = 0;
    q->size = size;
    q->count = 0;
    return q;
}

int push(Queue *q, int val) {
    if (q == NULL) return 0;
    if (q->count == q->size) {
        printf("\033[32mQueue is full!\n\033[0m");
        return 0;
    }
    q->data[q->head] = val;
    q->head = (q->head + 1) % q->size;
    q->count += 1;
    return 1;
}

int pop(Queue *q) {
    if (q == NULL) return 0;
    if (q->count == 0) {
        printf("\033[32mQueue is empty!\033[0m\n");
        return 0;
    }
    q->data[q->tail] = -1;
    q->tail = (q->tail + 1) % q->size;
    q->count -= 1;
    return 1;
}

void clear(Queue *q) {
    if (q == NULL) return ;
    free(q->data);
    free(q);
    return ;
}

void output(Queue *q) {
    if (q == NULL) return ;
    int len = 0;
    printf("\n");
    for (int i = 0; i < q->size; i++) {
        if (q->data[i] == -1) len += printf("    ");
        else len += printf("%4d", q->data[i]);
    }
    printf("\n");
    for (int i = 0; i < len; i++) printf("-");
    printf("\n");
    for (int i = 0; i < q->size; i++) printf("%4d", i);
    printf("\n\n");
    return ;
}

int main() {
    srand(time(0));
    Queue *q = initQueue(8);
    int op;
    int val;
    for (int i = 0; i < 20; i++) {
        op = rand() % 4;//0\1\2是入队,3是出队
        switch (op) {
            case 0:
            case 1:
            case 2: {
                val = rand() % 1000;
                printf("push %d in queue!\n", val);
                push(q, val);
            } break;
            case 3: {
                printf("erase queue!\n");
                pop(q);
            } break;
        }
        output(q);
    }
    return 0;
}
