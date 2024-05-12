/*************************************************************************
	> File Name: sprintf.c
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Fri 12 Apr 2024 07:29:05 PM CST
 ************************************************************************/

#include<stdio.h>

int main() {
    char str[100] = "192.168.1.245";
    int a, b, c, d;
    sscanf(str, "%d.%d.%d.%d", &a, &b, &c, &d);
    sprintf(str, "%d:%d:%d:%d", a, b, c, d);//把已知数据读入str字符串
    printf("str = %s\n",str);
    return 0;
}
