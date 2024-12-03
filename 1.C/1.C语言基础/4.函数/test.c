/*************************************************************************
	> File Name: test.c
	> Author: 
	> Mail: 
	> Created Time: Wed 16 Aug 2023 10:04:59 PM CST
 ************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

int my_printf(const char *format, ...) {
    va_list arg;
    va_start(arg, format);
    int cnt = 0;
    for (int i = 0; format[i]; i++) {
        switch(format[i]) {
            case '%': {
                switch(format[++i]) {
                    case '%': {
                        putchar(format[i]);
                        cnt += 1;
                    } break;
                    case 'd': {
                        int num = va_arg(arg, int);    
                        if (num < 0) {
                            putchar('-');
                            num = -num;
                            cnt += 1;
                        }
                        int x = 0, digit = 0;
                        char s[15] = {0};
                        do {
                            x = x * 10 + num % 10;
                            digit += 1;
                            num /= 10;
                        } while (num);
                        for (int i = 0; i < digit; i++) {
                            s[i] = (x % 10) + '0';
                            x /= 10;
                        }
                        for (int i = 0; i < digit; i++) {
                            putchar(s[i]);
                            cnt += 1;
                        }
                    } break;
                    case 'c': {
                        int c = va_arg(arg, int);
                        putchar(c);
                        cnt += 1;
                    } break;
                    case 's': {
                        char *s = va_arg(arg, char *);
                        for (int i = 0; s[i]; i++) {
                            putchar(s[i]);
                            cnt += 1;
                        }
                    } break;
                }
            } break;
            default:
                putchar(format[i]);
                cnt += 1;
                break;
        }
    }
    return cnt;
}

int main() {
    int len1 = 0, len2 = 0;
    len1 += printf(   "%%OK : %d %d %d\n", 123, -50, 0);
    len2 += my_printf("%%OK : %d %d %d\n", 123, -50, 0);
    len1 += printf(   "%c\n", 'O');
    len2 += my_printf("%c\n", 'O'); 
    len1 += printf(   "%s\n", "hello world");
    len2 += my_printf("%s\n", "hello world"); 
    printf("%d : %d\n", len1, len2);
    return 0;
}
