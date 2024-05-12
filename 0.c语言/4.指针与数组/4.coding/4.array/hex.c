/*************************************************************************
	> File Name: hex.c
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Thu 18 Apr 2024 02:01:02 PM CST
 ************************************************************************/

#include<stdio.h>

int main() {
    int a = 0x6a;
    printf("a(10) = %d\n", a);
    printf("a(16) = %x\n", a);
    printf("a(16) = %X\n", a);
    int b = 0x7fffffff;// = INT_MAX
    printf("max_int = %d\n", b);
    int c = 0x80000000;// = INT_MIN
    printf("min_int = %d\n", c);
    printf("input hex :");
    scanf("%x", &a);
    printf("a(10) = %d\n", a);
    printf("a(16) = %x\n", a);
    printf("a(16) = %X\n", a);
    
    return 0;
}
