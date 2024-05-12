/*************************************************************************
	> File Name: test1.c
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Sat 20 Apr 2024 09:30:43 PM CST
 ************************************************************************/

#include<stdio.h>

int main() {
    int a, b, c, d;
    scanf("%d.%d.%d.%d", &a, &b, &c, &d);
    unsigned int n;
    char *p = (char *)&n;
    p[3] = a;
    p[2] = b;
    p[1] = c;
    p[0] = d;
    printf("%u\n", n);
    return 0;
}
