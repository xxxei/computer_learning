/*************************************************************************
	> File Name: 1.printf.c
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Fri 12 Apr 2024 05:21:31 PM CST
 ************************************************************************/

#include<stdio.h>
int main()
{
    int n1, n2;
    n1 = printf("hello world\n");
    printf("%d\n",'\n');
    int a = 123;
    n2 = printf("hello world : %d\n", a);
    printf("n1 = %d, n2 = %d\n", n1, n2);

    return 0;
}
