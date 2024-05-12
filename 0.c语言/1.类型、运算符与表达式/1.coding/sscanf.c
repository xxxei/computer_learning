/*************************************************************************
	> File Name: sscanf.c
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Fri 12 Apr 2024 07:24:00 PM CST
 ************************************************************************/

#include<stdio.h>
int main() {
    char s[100] = "123 456 789";
    int a, b, c;
    sscanf(s, "%d%d%d", &a, &b, &c);//读取已知字符串
    printf("a = %d, b = %d, c = %d\n", a, b, c);
    return 0;
}
