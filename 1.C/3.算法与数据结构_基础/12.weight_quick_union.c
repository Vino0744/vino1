/*************************************************************************
	> File Name: 11.quick_union.c
	> Author: 
	> Mail: 
	> Created Time: Mon 07 Aug 2023 10:33:54 AM CST
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>

typedef struct UnionSet {
    int *father;
    int *size;
    int n;
} UnionSet;

UnionSet *init(int n) {
    UnionSet *u = (UnionSet *)malloc(sizeof(UnionSet));
    u->father = (int *)malloc(sizeof(int) * n);
    u->size = (int *)malloc(sizeof(int) * n);
    u->n = n;
    for (int i = 0; i < n; i++) {
        u->father[i] = i;
        u->size[i] = 1;
    }
    return u;
}

//查找节点颜色
int find(UnionSet *u, int n) {
    if (u->father[n] == n) return n;
    return u->father[n] = find(u, u->father[n]);
}

//合并并查集
int merge(UnionSet *u, int a, int b) {
    int fa = find(u, a), fb = find(u, b);
    if (fa == fb) return 0;
    if (u->size[fa] > u->u->size[fb]) {
        u->father[fb] = fa;
        u->size[fa] += u->size[fb];
        u->size[fb] = 1;
    } else {
        u->father[fa] = fb;
        u->size[fb] += u->size[fa];
        u->size[fa] = 1;
    }
    return 1;
}

//释放空间
void clear(UnionSet *u) {
    if (u == NULL) return ;
    free(u->father);
    free(u->size);
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
    
}
