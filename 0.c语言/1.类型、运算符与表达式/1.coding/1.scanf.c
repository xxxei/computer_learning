/*************************************************************************
	> File Name: 1.scanf.c
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Fri 12 Apr 2024 05:31:45 PM CST
 ************************************************************************/

#include<stdio.h>
int main(){
    int a, b, n;
    printf("normal scanf, input a, b:");
    n = scanf("%d%d", &a, &b);
    printf("a = %d, b = %d\n", a, b);
    printf("n = %d\n", n);
    printf("format scanf, input %%dabc%%d:");
    n = scanf("%dabc%d", &a, &b);
    printf("a = %d, b = %d\n", a, b);
    printf("n = %d\n", n);
    return 0;
}
