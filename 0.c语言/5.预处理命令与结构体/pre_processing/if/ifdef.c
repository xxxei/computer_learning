/*************************************************************************
	> File Name: ifdef.c
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Wed 24 Apr 2024 12:53:08 PM CST
 ************************************************************************/

#include<stdio.h>

#ifndef DEBUG //如果debug没有被定义
#define DEBUG
#endif

#ifdef DEBUG // 如果debug被定义则
int a = 1;
#else 
int a = 2;
#endif

int main() {
    printf("a = %d\n", a);
    return 0;
}
