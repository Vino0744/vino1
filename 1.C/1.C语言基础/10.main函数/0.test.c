/*************************************************************************
	> File Name: 4.my_copy.c
	> Author: 
	> Mail: 
	> Created Time: Sun 09 Jul 2023 09:24:52 PM CST
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 256

void get_filename(const char *str, char *file) {
    int cnt = strlen(str) - 1;
    for ( ; cnt >= 0; cnt--) {
        if (str[cnt] == '/') break;
    }
    sscanf(str + cnt, "%s", file);
    return ;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("You lack element,copy is fail!\n");
        exit(1);
    }
    FILE *fp1 = fopen(argv[1], "rb");
    if (fp1 == NULL) {
        printf("%s is not exist! please check the filename!\n", argv[1]);
        exit(1);
    }
    char file1name[MAX_N + 5] = {0};
    get_filename(argv[1], file1name);
    int i = strlen(argv[2]);
    if (argv[2][i - 1] == '/') {
        strcmp(argv[2] + i, file1name);
    }
    FILE *fp2 = fopen(argv[2], "wb");
    char buff[MAX_N + 5];
    while (feof(fp1) == 0) {
        memset(buff, sizeof(char), sizeof(buff));
        int size = fread(buff, sizeof(char), MAX_N, fp1);
        fwrite(buff, sizeof(char), size, fp2);
    }
    fclose(fp1);
    fclose(fp2);
    return 0;
}
