/*************************************************************************
	> File Name: 6.my_printf.c
	> Author: 
	> Mail: 
	> Created Time: Wed 05 Jul 2023 10:41:36 PM CST
 ************************************************************************/

#include <stdarg.h>
#include <stdio.h>
#include <inttypes.h>

//putchar()实现

int my_printf(const char *format, ...) {
    va_list arg;
    va_start(arg, format);
    int cnt = 0;
    for (int i = 0; format[i]; i++) {
        switch (format[i]) {
            case '%': {
                switch (format[++i]) {
                    case '%': putchar(format[i]), cnt++; break;
                    case 'd': {
                        int temp = va_arg(arg, int), k = 0;
                        unsigned int x = 0;
                        char str[15] = {0}; 
                        if (temp < 0) {
                            x = -temp;
                            putchar('-');
                            cnt++;
                        } else {
                            x = temp;
                        }
                        do {
                            str[k++] = x % 10 + '0';
                            x /= 10;
                        } while(x);
                        for (int i = k - 1; i >= 0; i--) {
                            putchar(str[i]);
                            cnt++;
                        }
                    } break;
                    case 'c': {
                        char ch = va_arg(arg, int);
                        putchar(ch);
                        cnt++;
                    } break;
                    case 's': {
                        char *str = va_arg(arg, char *);
                        for (int i = 0; str[i]; i++) {
                            putchar(str[i]);
                            cnt++;
                        }
                    } break;
                    case 'f': break;
                }
            } break;
            default:
                putchar(format[i]);
                cnt++;
                break;
        }
    }
    va_end(arg);
    return cnt;
}

int main() {
    printf("     %d, %d, %d, %d, %d, %d, %d\n", 1,  0, -123, 1000, 1010, INT32_MAX, INT32_MIN);
    my_printf("MY : %d, %d, %d, %d, %d, %d, %d\n", 1, 0, -123, 1000, 1010, INT32_MAX, INT32_MIN);
    int ret1 = printf("     %c, %s\n", 'r', "cdc love csc");
    int ret2 = my_printf("MY : %c, %s\n", 'r', "cdc love csc");
    printf("%d : %d\n", ret1, ret2);
    return 0;
}
