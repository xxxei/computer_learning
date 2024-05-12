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

union INT_NUMBER {
    struct {
        unsigned char b1:4;
        unsigned char b2:4;
    } bytes[4];
    unsigned int number;
};

int main() {
    union INT_NUMBER n;
    n.number = 0x61626364;
    for (int i = 0; i < 4; i++) {
        printf("%u%u", n.bytes[i].b1, n.bytes[i].b2);
    }
    printf("\n");
    return 0;

