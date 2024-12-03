/*************************************************************************
	> File Name: 2.密码锁.c
	> Author: 
	> Mail: 
	> Created Time: Sun 09 Jul 2023 04:37:19 PM CST
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void func() {
    printf("%s\n", "我踏马吃吃吃吃吃");
    return ;
}

void error_print() {
    printf("You are not USER!");
    return ;
}

int main(int argc, char *argv[], char **env) {
    for (int i = 0; env[i]; i++) {
        if (strncmp(env[i], "USER=", 5)) continue;
        if (strcmp(env[i] + 5, "vino") == 0) break;
        else {
            error_print();
            exit(0);
        }
    }
    func();
    return 0;
}
