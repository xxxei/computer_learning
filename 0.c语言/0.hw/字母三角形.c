/*************************************************************************
	> File Name: 字母三角形.c
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Thu 18 Apr 2024 08:21:06 PM CST
 ************************************************************************/

#include<stdio.h>

int main() {
    int n;
    char ch = 'A';
    scanf("%d", &n);
    for (int i = n; i >= 1; i--) {
        for (int j = 0; j < i; j++) {
            printf("%c", ch++);
        }
        printf("\n");
    }
    return 0;
}
