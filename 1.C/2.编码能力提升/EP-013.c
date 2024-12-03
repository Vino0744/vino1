/*************************************************************************
	> File Name: EP-013.c
	> Author: 
	> Mail: 
	> Created Time: Sat 15 Jul 2023 03:49:59 PM CST

Problem 13: Large sum

Work out the first ten digits of the sum of the following one-hundred $50$-digit numbers.(input13)

 ************************************************************************/

#include<stdio.h>
#include <string.h>

char num[55] = {0};
int ans[55] = {0};

int main() {
    ans[0] = 50;
    for (int i = 0; i < 100; i++) {
        scanf("%s", num);
        int len = strlen(num);//倒着存有助于进位(0位空着)
        for (int j = 0; j < len; j++) {
            ans[len - j] += (num[j] - '0');
        }
        for (int k = 1; k <= ans[0]; k++) {
            if (ans[k] < 10) continue;
            ans[k + 1] += ans[k] / 10;
            ans[k] %= 10;
            ans[0] += (ans[ans[0] + 1] != 0);
        }
    }
    for (int i = ans[0]; i > ans[0] - 10; i--) {
        printf("%d", ans[i]);
    }
    printf("\n");
    return 0;
}
