/*************************************************************************
	> File Name: bit.c
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Thu 25 Apr 2024 11:29:39 AM CST
 ************************************************************************/

#include<stdio.h>

#define p(a, format) { \
    printf("%s = " format "\n", #a, a); \
}

struct A {
    unsigned int a:1; // 表示a变量只使用二进制的一位
    unsigned int b:2;
    unsigned int c:3;
};

int main() {
    p(sizeof(struct A), "%lu");
    struct A obj;
    obj.a = 15;
    obj.b = 15;
    obj.c = 15; // 15 --> 1111
    p(obj.a, "%d"); // --> 1
    p(obj.b, "%d"); // --> 11 == 3
    p(obj.c, "%d"); // --> 111 == 7 // 前提是无符号整型类型 // 有符号的整型类型 --> -1  
    return 0;
}
