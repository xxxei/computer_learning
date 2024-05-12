/*************************************************************************
	> File Name: fprintf.c
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Sun 28 Apr 2024 09:31:06 AM CST
 ************************************************************************/

#include<stdio.h>

int main() {
    fprintf(stdout, "hello world\n");
    int n;
    fscanf(stdin, "%d", &n);
    fprintf(stderr, "n = %d\n");
    return 0;
}
