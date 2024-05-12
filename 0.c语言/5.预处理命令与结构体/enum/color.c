/*************************************************************************
	> File Name: color.c
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Thu 25 Apr 2024 10:57:08 AM CST
 ************************************************************************/

#include<stdio.h>

#ifdef PLAN_A

#define COLOR(msg, code) "\033[1;" #code "m" msg "\033[0m"
#define RED(msg)    COLOR(msg, 31)
#define GREEN(msg)  COLOR(msg, 32)
#define YELLOW(msg) COLOR(msg, 33)
#define BLUE(msg)   COLOR(msg, 34)

int main() {
    printf("\033[1;32;43mhello world\n\033[0m"); // \033[m
    printf(RED("hello color\n"));
    printf(GREEN("hello color\n"));
    printf(YELLOW("hello color\n"));
    printf(BLUE("hello color\n"));
    return 0;
}

#else 

enum COLOR_code {
    red = 31,
    green,
    yellow,
    blue
};
#define COLOR_set "\033[1;%dm"
#define COLOR_end "\033[0m"

int main() {
    printf(COLOR_set "hello color plan b\n" COLOR_end, red);
    printf(COLOR_set "hello color plan b\n" COLOR_end, green);
    printf(COLOR_set "hello color plan b\n" COLOR_end, yellow);
    printf(COLOR_set "hello color plan b\n" COLOR_end, blue);
    return 0;
}
#endif
