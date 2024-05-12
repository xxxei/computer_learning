/*************************************************************************
	> File Name: 2.goto_ifelse.c
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Tue 16 Apr 2024 08:37:58 AM CST
 ************************************************************************/

#include<stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    n % 2 == 0 && ({goto if_stmt; 1;}); //小括号将大括号变成一个有返回值的表达式，而大括号的返回值是最后一条语句的值
    !(n % 2 == 0) && ({goto else_stmt; 1;});
if_stmt:
    printf("n is even\n");
    goto if_end;
else_stmt:
    printf("n is odd\n");
if_end:
    return 0;
}
