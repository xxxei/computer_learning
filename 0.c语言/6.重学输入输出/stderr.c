/*************************************************************************
	> File Name: stderr.c
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Sun 28 Apr 2024 09:14:59 AM CST
 ************************************************************************/

#include<stdio.h>

int main () {
    printf("hello world\n"); // 标准输出流 stdout
    int n;
    scanf("%d", &n); // 标准输入流 stdin 
    perror("out of range\n");
    return 0;
}
