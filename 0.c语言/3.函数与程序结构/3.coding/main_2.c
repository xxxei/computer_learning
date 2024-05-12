/*************************************************************************
	> File Name: main_2.c
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Thu 18 Apr 2024 12:30:53 PM CST
 ************************************************************************/

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (strcmp(argv[0], "./bilibili") != 0) {
        printf("wrong call, please call : ./bilibili\n");
        return 0;
    }
    printf("right call");
    printf("argc = %d\n", argc);//指的是命令行参数个数
    for (int i = 0; i < argc; i++) {
        printf("argv[i] = %s\n", argv[i]);//指的是参数字符串
    }
    return 0;
}
