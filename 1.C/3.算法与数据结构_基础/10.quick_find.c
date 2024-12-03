/*************************************************************************
	> File Name: 10.quick_find.c
	> Author: 
	> Mail: 
	> Created Time: Sun 06 Aug 2023 12:02:37 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct UnionSet {
    int *color;
    int n;
} UnionSet;

UnionSet *init(int n) {
    UnionSet *u = (UnionSet *)malloc(sizeof(UnionSet));
    u->color = (int *)malloc(sizeof(int) * n);
    u->n = n;
    for (int i = 0; i < n; i++) u->color[i] = i;
    return u;
}

//查找节点颜色
int find(UnionSet *u, int n) {
    return u->color[n];
}

//合并并查集
int merge(UnionSet *u, int a, int b) {
    if (find(u, a) == find(u, b)) return 0;
    int color_a = find(u, a);
    for (int i = 0; i < u->n; i++) {
        if (find(u, i) == color_a) u->color[i] = u->color[b];
    }
    return 1;
}

//释放空间
void clear(UnionSet *u) {
    if (u == NULL) return ;
    free(u->color);
    free(u);
    return ;
}

void output(UnionSet *u) {
    for (int i = 0; i < u->n; i++) {
        if (i % 5 == 0) printf("\n");
        printf("%d ", find(u, i));
    }
    printf("\n");
}


int main() {
    srand(time(0));
    UnionSet *u = init(10);
    int a, b;
    for (int i = 0; i < 5; i++) {
        a = rand() % 10;
        b = rand() % 10;
        merge(u, a, b);
        output(u);
    }
    return 0;
}
