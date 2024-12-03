/*************************************************************************
	> File Name: 3.my_cat.c
	> Author: 
	> Mail: 
	> Created Time: Sun 09 Jul 2023 08:19:08 PM CST
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_N 256

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("usage : %s file\n", argv[0]);
        exit(1);
    }
    FILE *fp = fopen(argv[1], "rb");
    if (fp == NULL) {
        printf("open %s is faild! please check the filename!\n", argv[1]);
        exit(0);
    }
    char buff[MAX_N + 5];
    while (feof(fp) == 0) {
        memset(buff, 0, sizeof(buff));
        fread(buff, sizeof(char), MAX_N, fp);
        printf("%s", buff);
    }
    fclose(fp);
    return 0;
}
