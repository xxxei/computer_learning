/*************************************************************************
	> File Name: union.c
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Wed 24 Apr 2024 05:21:08 PM CST
 ************************************************************************/

#include<stdio.h>

union A {
    struct {
        unsigned char byte1;
        unsigned char byte2;
        unsigned char byte3;
        unsigned char byte4;
    } bytes;
    unsigned int number;
};

#define P(a, format) { \
    printf("%s = " format "\n", #a, a); \
}

int main() {
    union A a;
    a.number = 0x61626364;
    P(a.number, "%x");
    P(a.bytes.byte1, "%x");
    P(a.bytes.byte2, "%x");
    P(a.bytes.byte3, "%x");
    P(a.bytes.byte4, "%x");
    return 0;
}
