/*************************************************************************
	> File Name: 176.c
	> Author: 
	> Mail: 
	> Created Time: Thu 12 Oct 2023 09:49:49 PM CST
 ************************************************************************/

#include <stdio.h>
#include <string.h>

int next[1000];

void initnext(const char *t) {
	next[0] = -1;
	for (int i = 1, j = -1; t[i]; i++) {
		while (j != -1 && t[i] != t[j + 1]) j = next[j];
		if (t[i] == t[j + 1]) j += 1;
		next[i] = j;
	}
	return ;
}

int kmp(const char *s, const char *t, int p) {
	int len = strlen(t);
	for (int i = p, j = -1; s[i]; i++) {
		while (j != -1 && s[i] != t[j + 1]) j = next[j];
		if (t[j + 1] == s[i]) j += 1;
        if (t[j + 1] == '\0') return i - len + 1;
	}
	return -1;
}

int main() {
	char s[1000], t[1000];
	scanf("%[^\n]", s);
    getchar(); 
    scanf("%s", t);
    initnext(t);
	int cnt = 0, i = kmp(s, t, 0), len = strlen(s);
	while (i >= 0) {
		cnt += 1;
		if (i + 1 >= len) break;
		i = kmp(s, t, i + 1);
	}
	printf("%d", cnt);
	return 0;
}
