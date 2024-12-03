/*************************************************************************
	> File Name: test.c
	> Author: 
	> Mail: 
	> Created Time: Fri 18 Aug 2023 10:04:16 PM CST
 ************************************************************************/

#include <stdio.h>

#define MAX_N 10000
int arr[MAX_N + 5] = {0};

void init() {
    for (int i = 2; i <= MAX_N; i++) {
        if (!arr[i]) arr[++arr[0]] = i;
        for (int j = 1; j <= arr[0]; j++) {
            if (arr[j] * i > MAX_N) break;
            arr[arr[j] * i] = 1;
            if (i % arr[j] == 0) break;
        }
    }
    return ;
}

int main() {
    init();
    printf("%d\n", arr[0]);
    return 0;
}
