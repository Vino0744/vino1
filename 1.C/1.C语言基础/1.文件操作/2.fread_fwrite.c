/*************************************************************************
	> File Name: 2.fread_fwrite.c
	> Author: 
	> Mail: 
	> Created Time: Wed 28 Jun 2023 10:48:30 AM CST
 ************************************************************************/

#include <stdio.h>
#include <string.h>

#define MAX_N 100

int main() {
    char filename[256], w_file[256];
    scanf("%s", filename);
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("open error!");
        return 0;
    }
    scanf("%s", w_file);
    FILE *fout = fopen(w_file, "wb");
    char buff[MAX_N + 1]; //存100位的字符数组
    while (feof(fp) == 0) { //是否到文件末尾
        memset(buff, 0, MAX_N);
        int size = fread(buff, sizeof(char), MAX_N, fp); //返回值为读入多少字符
        fwrite(buff, sizeof(char), size, fout);
    }
    fclose(fp);
    fclose(fout);
    return 0;
}
