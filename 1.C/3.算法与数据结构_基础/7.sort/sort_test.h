/*************************************************************************
	> File Name: sort_test.h
	> Author: 
	> Mail: 
	> Created Time: Tue 01 Aug 2023 10:38:52 AM CST
 ************************************************************************/

#ifndef _SORT_TEST_H
#define _SORT_TEST_H

#define SMALL_DATA_N 5000
#define BIG_DATA_N 1000000

__attribute__((constructor))
void __INIT__() {
    printf("init rand\n");
    srand(time(0));
}

#define swap(a, b) { \
    __typeof(a) __c = a; \
    a = b; \
    b = __c; \
}

int *getRandData(int);
int is_order(int *, int, int);
void test(void (*func)(int *, int, int), int *, int);

int *getRandData(int n) {
    int *arr = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) arr[i] = rand() % 10000;
    return arr;
}

int is_order(int *arr, int l, int r) {
    for (int i = l; i < r - 1; i++) {
        if (arr[i] > arr[i + 1]) return 0;
    }
    return 1;
}

#define test(func, arr, n) { \
    printf("TEST %s\n", #func); \
    int *temp = (int *)malloc(sizeof(int) * n); \
    memcpy(temp, arr, sizeof(int) * n); \
    long long b = clock(); \
    func(temp, 0, n); \
    long long e = clock(); \
    if(is_order(temp, 0, n)) printf("OK : "); \
    else printf("NO : "); \
    printf("%lld ms\n", 1000 * (e - b) / CLOCKS_PER_SEC); \
    free(temp); \
}
#endif
