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
    int n;
} UnionSet;

UnionSet *init(int n) {
    UnionSet *u = (UnionSet *)malloc(sizeof(UnionSet));
    u->father = (int *)malloc(sizeof(int) * n);
    u->n = n;
    for (int i = 0; i < n; i++) u->father[i] = i;
    return u;
}

//查找节点颜色
int find(UnionSet *u, int n) {
    if (u->father[n] == n) return x;
    return find(u, u->father[n]);
}

//合并并查集
int merge(UnionSet *u, int a, int b) {
    if (find(u, a) == find(u, b)) return 0;
    u->father[find(u, a)] = find(u, b);
    return 1;
}

//释放空间
void clear(UnionSet *u) {
    if (u == NULL) return ;
    free(u->father);
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
