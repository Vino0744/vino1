/*************************************************************************
	> File Name: 6.test.c
	> Author: 
	> Mail: 
	> Created Time: Sat 08 Jul 2023 11:10:13 AM CST
 ************************************************************************/
#include <stdio.h>

__attribute__((constructor))
void test() {
    printf("this is test!\n");
    return ;
}

int main() {
    printf("this is main!\n");
    return 0;
}
