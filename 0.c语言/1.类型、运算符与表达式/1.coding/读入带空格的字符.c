/*************************************************************************
	> File Name: 读入带空格的字符.c
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Fri 12 Apr 2024 07:18:32 PM CST
 ************************************************************************/

#include<stdio.h>
int main() {
    char s[100];
    int n;
    scanf("%[^\n]",s);
    n = printf("%s\n",s);
    printf("字符数 : %d\n",n);
    return 0;
}
