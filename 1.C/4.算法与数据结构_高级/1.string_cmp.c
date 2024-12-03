/*************************************************************************
	> File Name: 1.string_cmp.c
	> Author: 
	> Mail: 
	> Created Time: Tue 08 Aug 2023 06:59:09 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 1000
#define DEFAULT_LEN 60
char s[MAX_N], t[MAX_N];

#define TEST(func) { \
    char temp[2 * MAX_N + 10]; \
    sprintf(temp, "%s: (\"%s, %s\") ---> %d\n", #func, s, t, func(s, t)); \
    int n = DEFAULT_LEN - strlen(temp); \
    while (n >= 0) n -= printf(" "); \
    printf("%s", temp); \
}

//单模匹配

int brute_force(const char *s, const char *t) {
    for (int i = 0; s[i]; i++) {
        int flag = 1;
        for (int j = 0; t[j]; j++) {
            if (i + j < strlen(s) && s[i + j] == t[j]) continue;
            flag = 0;
            break;
        }
        if (flag == 1) return i;
    }
    return -1;
}

int *getnext(const char *t, int n) {
    int *next = (int *)malloc(sizeof(int) * n);
    //next[i] = j 表示以i为结尾所匹配到的最长的前缀位置为j
    next[0] = -1;
    for (int i = 1, j = -1; t[i]; i++) {
        while (j != -1 && t[j + 1] != t[i]) j = next[j];
        if (t[j + 1] == t[i]) j += 1;
        next[i] = j;
    }
    return next;
}

int kmp(const char *s, const char *t) {
    int len = strlen(t);
    int *next = getnext(t, len);
    for (int i = 0, j = -1; s[i]; i++) {
        while (j != -1 && s[i] != t[j + 1]) j = next[j];
        if (s[i] == t[j + 1]) j += 1;
        if (t[j + 1] == '\0') {
            free(next);
            return i - len + 1;
        }
    }
    free(next);
    return -1;
}


int sunday(const char *s, const char *t) {
    int s_len = strlen(s), t_len = strlen(t);
    int jump[256] = {0};
    for (int i = 0; i < 256; i++) jump[i] = t_len + 1;
    for (int i = 0; t[i]; i++) jump[t[i]] = t_len - i;
    for (int i = 0; i + t_len <= s_len; ) {
        int flag = 1;
        for (int j = 0; j < t_len; j++) {
            if (s[i + j] == t[j]) continue;
            flag = 0;
            break;
        }
        if (flag) return i;
        i += jump[s[i + t_len]];
    }
   return -1;
}

//多模匹配

int shift_and(const char *s, const char *t) {
    int d[256] = {0};
    int n = strlen(t);
    for (int i = 0; i < n; i++) d[t[i]] |= (1 << i);
    int p = 0;
    for (int i = 0; s[i]; i++) {
        p = (p << 1 | 1) & d[s[i]];
        if (p & 1 << ((n - 1))) return i - n + 1;
    }
    return -1;
}

int main() {
    while (~scanf("%s%s", s, t)) {
        TEST(brute_force);
        TEST(kmp);
        TEST(sunday);
        TEST(shift_and);
    }
    return 0;
}
