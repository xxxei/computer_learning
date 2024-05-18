/*************************************************************************
	> File Name: my_scanf_printf.c
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Mon 29 Apr 2024 02:21:13 PM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdarg.h>
#define BUFFER_SIZE 1024

void my_scanf(const char *format, ...) {
    char buffer[BUFFER_SIZE];
    va_list args;
    va_start(args, format);
    ssize_t len = read(STDIN_FILENO, buffer, BUFFER_SIZE); // ssize_t 表示有符号的自定义类型，从标准输入读BUFFER_SIZE个字符到buffer字符串中，返回值为长度
    vsscanf(buffer, format, args);
    va_end(args);
}

void my_printf(const char *format, ...) {
    char buffer[BUFFER_SIZE];
    va_list args;
    va_start(args, format);
    ssize_t len = vsnprintf(buffer, BUFFER_SIZE, format, args);
    va_end(args);
    write(STDOUT_FILENO, buffer, len);
}

int main() {
    int num;
    char str[10];
    my_printf("Please input a number :\n");
    my_scanf("%d", &num);
    my_printf("The number is : %d\n", num);
    my_printf("Please input a string :\n");
    my_scanf("%s", str);
    my_printf("The string is : %s\n", str);
}
