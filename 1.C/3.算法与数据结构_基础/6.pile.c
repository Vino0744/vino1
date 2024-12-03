/*************************************************************************
	> File Name: 6.pile.c
	> Author: 
	> Mail: 
	> Created Time: Sat 29 Jul 2023 11:25:52 PM CST
 ************************************************************************/
//尾部插入，头部弹出（优先队列）
//尾部插入最后一个节点再向上调整
//头部弹出后将最小的节点交换向下调整

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define swap(a, b) { \
    __typeof(a) __c = a; \
    a = b; \
    b = __c; \
}

//优先队列，建大顶堆
typedef struct priority_queue {
    int *data;
    int cnt, size;
} priority_queue;

priority_queue *initHeap(int size) {
    priority_queue *h = (priority_queue *)malloc(sizeof(priority_queue));
    h->data = (int *)malloc(sizeof(int) * size);
    h->cnt = 0;
    h->size = size;
    return h;
}

int empty(priority_queue *h) {
    return h->cnt == 0;
}

int top(priority_queue *h) {
    return h->data[1];
}

int push(priority_queue *h, int val) {
    if (h == NULL) return 0;
    if (h->cnt == h->size) return 0;
    h->data[++h->cnt] = val;
    int ind = h->cnt;
    while (ind >> 1 && h->data[ind] > h->data[ind >> 1]) {
        swap(h->data[ind], h->data[ind >> 1]);
        ind >>= 1;
    }
    return 1;
}

int pop(priority_queue *h) {
    if (h == NULL) return 0;
    if (empty(h)) return 0;
    h->data[1] = h->data[h->cnt--];
    int ind = 1;
    while (ind * 2 <= h->cnt) {
        int temp = ind, l = ind * 2, r = ind * 2 + 1;
        if (h->data[l] > h->data[temp]) temp = l;
        if (r <= h->cnt && h->data[r] > h->data[temp]) temp = r;
        if (temp == ind) break;
        swap(h->data[temp], h->data[ind]);
        ind = temp;
    }
    return 1;
}

void clearHeap(priority_queue *h) {
    if (h == NULL) return ;
    free(h->data);
    free(h);
    return ;
}

void output(priority_queue *h) {
    if (h == NULL) return ;
    printf("priority_queue : ");
    for (int i = 1; i <= h->cnt; i++) {
        printf("%d ", h->data[i]);
    }
    printf("\n");
    return ;
}

int main() {
    srand(time(0));
    priority_queue *h = initHeap(10);
    int val, op;
    for (int i = 0; i < 10; i++) {
        op = rand() % 4;//0\1\2插入，3弹出
        switch(op) {
            case 0:
            case 1:
            case 2: {
                val = rand() % 1000;
                printf("push %d\n", val);
                push(h, val);
            } break;
            case 3: {
                printf("pop\n");
                pop(h);
            } break;
        }
        output(h);
    }
    return 0;
}
