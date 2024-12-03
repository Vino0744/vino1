/*************************************************************************
	> File Name: 1.victor.c
	> Author: 
	> Mail: 
	> Created Time: Thu 20 Jul 2023 07:05:30 PM CST
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//顺序表
//定义

typedef struct Vector {
    int *data;
    int size, length;
} Vector;

//操作:初始化 插入 删除 查找 清空 扩容

Vector *init(int n) {
    Vector *vec = (Vector *)malloc(sizeof(Vector));
    vec->data = (int *)malloc(sizeof(int) * n);
    vec->size = n;
    vec->length = 0;
    return vec;
}

int expend(Vector *vec) {
    int exp_size = vec->size * 2;
    int *exp_data = (int *)realloc(vec->data, sizeof(int) * exp_size);
    if (exp_data == NULL) return 0;
    vec->data = exp_data;
    vec->size = vec->size * 2;
    printf("\033[31mVector expend %d to %d\033[0m\n", vec->size / 2, vec->size);
    return 1;
}

int insert(Vector *vec, int ind, int val) {
    if (vec == NULL) return 0;
    if (ind < 0 || ind > vec->length) {
        printf("The ind is error!\n"); 
        return 0;
    }
    if (vec->length == vec->size) {
        if (!expend(vec)) return 0;
    }
    for(int i = vec->length; i > ind; i--) {
        vec->data[i] = vec->data[i - 1];
    }
    vec->data[ind] = val;
    vec->length += 1;
    printf("Insert %d in %d\n", val, ind);
    return 1;
}

int delete(Vector *vec, int ind) {
    if (vec == NULL) return 0;
    if (ind < 0 || ind >= vec->length) {
        printf("Delete is error!\n"); 
        return 0;
    }
    for (int i = ind; i < vec->length - 1; i++) {
        vec->data[i] = vec->data[i + 1];
    }
    vec->length -= 1;
    printf("Delete vec[%d]\n", ind);
    return 1;
}

void clear(Vector *vec) {
    if (vec == NULL) return ;
    if (vec->data != NULL) free(vec->data);
    free(vec);
    return ;
}

void output(Vector *vec) {
    if (vec == NULL) return ;
    if (vec->length < 0) {
        printf("The vector is empty\n"); 
        return ;
    }
    for (int i = 0; i < vec->length; i++) {
        i && printf(" ");
        printf("%d", vec->data[i]);
    }
    printf("\n");
    return ;
}

int main() {
    srand(time(0));
    Vector *vec = init(1);
    int op;//0\1\2插入节点，3删除节点
    int ind, val;
    for (int i = 0; i < 20; i++) {
        op = rand() % 4;
        ind = rand() % (vec->length + 1);
        switch (op) {
            case 0:
            case 1:
            case 2: {
                val = rand() % 1000;
                insert(vec, ind, val);
            } break;
            case 3: {
                delete(vec, ind);
            } break;
        }
        output(vec);
    }
    clear(vec);
    return 0;
}
