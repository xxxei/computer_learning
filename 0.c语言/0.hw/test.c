/*************************************************************************
	> File Name: test.c
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Tue 16 Apr 2024 01:08:39 PM CST
 ************************************************************************/

#include<stdio.h>

int main() {
    char s[10];
    scanf("%s", s);
    double m, n;
    scanf("%lf%lf", &m, &n);
    printf("%.2lf\n", s[0] == 'r' ? m * n : m * n * 0.5);
    return 0;
}
