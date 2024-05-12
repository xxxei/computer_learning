/*************************************************************************
	> File Name: my_scanf_printf.c
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Mon 29 Apr 2024 02:21:13 PM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#define BUFFER_SIZE 1024

void my_scanf(const char *format, ...) {
    char buffer[BUFFER_SIZE];
    va_list args;
    va_start(args, format);
    read(STDIN_FILENO, buffer, BUFFER_SIZE);
}
