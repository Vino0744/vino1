/*************************************************************************
	> File Name: 1.file.c
	> Author: 
	> Mail: 
	> Created Time: Fri 29 Nov 2024 04:23:29 PM CST
 ************************************************************************/

// Usage : cp file1 file2

#include "./common/head.h"

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage : %s file1 file2", argv[0]);
        exit(1);
    }
    int fd_in, fd_out;
    char buff[10] = {0};
    if ((fd_in = open(argv[1], O_RDONLY)) == -1) {
        perror("open");
        exit(1);
    }
    if ((fd_out = open(argv[2], O_WRONLY | O_CREAT | O_EXCL, 0644)) == -1) {
        perror("open");
        exit(1);
    }
    size_t buff_size = sizeof(buff);
    while(1) {
        int rsize = read(fd_in, buff, buff_size);
        if (rsize < 0) {
            perror("read");
            exit(1);
        } else if (rsize == 0) {
            break;
        }
        int wsize = write(fd_out, buff, rsize);
        if (wsize < -1) {
            perror("write to out file");
            exit(1);
        }
        memset(buff, 0, rsize);
    }
    close(fd_in);
    close(fd_out); 


    return 0;
}
