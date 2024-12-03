/*************************************************************************
	> File Name: EP-042.c
	> Author: 
	> Mail: 
	> Created Time: Sat 15 Jul 2023 12:41:19 PM CST

Problem 42: Coded triangle numbers

The $n$th term of the sequence of triangle numbers is given by, $t_n=n (n+1)/2$; so the first ten triangle numbers are:

$$1, 3, 6, 10, 15, 21, 28, 36, 45, 55, \ldots$$

By converting each letter in a word to a number corresponding to its alphabetical position and adding these values we form a word value. For example, the word value for SKY is $19 + 11 + 25 = 55 = t_{10}$. If the word value is a triangle number then we shall call the word a triangle word.

Using words.txt(right click and ‘Save Link/Target As…’), a 16K text file containing nearly two-thousand common English words, how many are triangle words?

 ************************************************************************/

#include <stdio.h>
#include <math.h>
#include "042.h"

int judge(int n) {
    double x = sqrt(n * 2 + 0.25) - 0.5;
    x = (int)x;
    return x * (x + 1) / 2 == n;
}

int is_val(char *str) {
    int sum = 0;
    for (int i = 0; str[i]; i++) {
        sum += (str[i] - 'A' + 1);
    }
    return judge(sum);
}

int main() {
    int n = sizeof(name) / 100, cnt = 0;
    for (int i = 0; i < n; i++) {
        if (!is_val(name[i])) continue;
        cnt++;
    }
    printf("%d\n", cnt);
    return 0;
}
