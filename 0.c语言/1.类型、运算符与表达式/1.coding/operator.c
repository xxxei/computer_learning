/*************************************************************************
	> File Name: operator.c
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Fri 12 Apr 2024 07:57:50 PM CST
 ************************************************************************/

#include<stdio.h>

void print_digit(int x) {
    for (int i = 31; i >= 0; i--) {
        printf("%c", (x & (1 << i)) ? '1' : '0');
    }
    printf("\n");
    return ;
}
int main() {
    int a = 5, b = 3;
    printf("a = "); print_digit(a);
    printf("b = "); print_digit(b);
    printf("a & b = "); print_digit(a & b);//二进制按位与
    printf("a | b = "); print_digit(a | b);//二进制按位或
    printf("a ^ b = "); print_digit(a ^ b);//二进制按位或
    a ^= b; b ^= a; a ^= b;
    printf("a = "); print_digit(a);
    printf("b = "); print_digit(b);
    printf("~b = "); print_digit(~b);
    printf("(~a + 1) = %d\n", ~a + 1);//补码 源码取反再加一（求负数）
    int x;
    scanf("%d", &x);
    printf("x = "); print_digit(x);
    printf("(-x & x) = "); print_digit((~x+1) & x);
    int c = 1279813123, d = -c;
    printf("c = "); print_digit(c);
    printf("d = "); print_digit(d);
    printf("c << 1 = "); print_digit(c << 1);
    printf("d << 1 = "); print_digit(d << 1);
    printf("c >> 1 = "); print_digit(c >> 1);//左移*2，右移/2
    printf("d >> 1 = "); print_digit(d >> 1);//除法向零取整，右移向下取整
    return 0;
}
