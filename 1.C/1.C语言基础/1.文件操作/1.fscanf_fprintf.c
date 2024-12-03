/*************************************************************************
	> File Name: 1.fscanf_fprintf.c
	> Author: 
	> Mail: 
	> Created Time: Wed 28 Jun 2023 10:27:26 AM CST
 ************************************************************************/

#include<stdio.h>

void cat(const char *name) {
    FILE *fp = fopen(name, "r");
    if (fp == NULL) {
        printf("ERROR OPEN!\n");
        return ;
    }
    char buff;
    char n_file[256] = {0};
    scanf("%s", n_file);
    FILE *fout = fopen(n_file, "w");//覆盖写入
    while (fscanf(fp, "%c", &buff) != EOF) {
        fprintf(fout, "%c", buff);
    }
    fclose(fp);
    fclose(fout);
    return ;
}

int main() {
    char name[256] = {0};
    scanf("%s", name);
    cat(name);
    return 0;
}
