/*************************************************************************
	> File Name: main_2.c
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Thu 18 Apr 2024 12:30:53 PM CST
 ************************************************************************/

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[], char **env) {
    int flag =0 ;
    for (char **p = env; p[0]; p += 1) {
        if (strcmp(p[0], "LOGNAME=xxx1") == 0) {
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        printf("error log name, please use xxx\n");
        return 0;
    }
    printf("argc = %d\n", argc);//指的是命令行参数个数
    for (int i = 0; i < argc; i++) {
        printf("argv[%d] = %s\n", i, argv[i]);//指的是参数字符串
    }
    return 0;
}
