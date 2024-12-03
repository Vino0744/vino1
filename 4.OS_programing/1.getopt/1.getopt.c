/*************************************************************************
	> File Name: 1.getopt.c
	> Author: 
	> Mail: 
	> Created Time: Thu 28 Nov 2024 02:20:48 PM CST
 ************************************************************************/

#include "./common/head.h"

int main(int argc, char **argv) {
    char input[20] = {0};
    char output[20] = {0};
    if (argc < 2) {
        fprintf(stderr, "Usage : %s -o file\n", argv[0]);
        exit(1);
    }

    int opt;
    while ((opt = getopt(argc, argv, "o:")) != -1) {
        switch(opt) {
            case 'o':
                strcpy(output, optarg);
                break;
            default:
                fprintf(stderr, "Usage : %s -o file", argv[0]);
                exit(1);
        }
    }
    printf("input = %s\n", argv[optind]);
    printf("output = %s\n", output);

    return 0;
}
