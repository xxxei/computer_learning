/*************************************************************************
	> File Name: 漂亮框框.c
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Fri 12 Apr 2024 07:34:57 PM CST
 ************************************************************************/

#include<stdio.h>

int main() {
    char s[100], t[100];
    scanf("%[^\n]", s);
    int n = 0;
    n = sprintf(t, "| %s |", s);
    for(int i = 0; i < n; i++) printf("-");
    printf("\n");
    printf("%s\n", t);
    for(int i = 0; i < n; i++) printf("-");
    printf("\n");
    return 0;
}
