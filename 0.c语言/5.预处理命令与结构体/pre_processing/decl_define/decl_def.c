/*************************************************************************
	> File Name: decl_def.c
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Tue 23 Apr 2024 07:22:41 PM CST
 ************************************************************************/

#include<stdio.h>

int add(int, int); //声明函数

extern int c, d; //声明变量

int main() {
    int a, b; //定义变量
    printf("a + b + c + d = %d\n", a + b + c + d);
    return 0;
}

int add(int a, int b) { //定义函数
    return a + b;
}
