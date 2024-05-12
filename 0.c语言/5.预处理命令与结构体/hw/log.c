/*************************************************************************
	> File Name: log.c
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Wed 24 Apr 2024 01:05:56 PM CST
 ************************************************************************/

#include<stdio.h>

#define DEBUG 1
#define ERROR 2
#define FATEL 3
#define NO_LOG 4
#define LOG(level) \
if (level >= LOG_LEVEL) \
printf("[%s : %d]", __FILE__, __LINE__);\
printf

int main() {
    int a = 123;
    printf("hello world\n");
    printf("a = %d\n", a);
    LOG(DEBUG)("hello world, DEBUG\n");
    LOG(ERROR)("hello world, ERROR\n");
    LOG(FATEL)("hello world, FATEL\n");
    LOG(DEBUG)("a = %d, DEBUG\n", a);
    LOG(ERROR)("a = %d, ERROR\n", a);
    LOG(FATEL)("a = %d, FATEL\n", a);
    return 0;
}
