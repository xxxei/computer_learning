/*************************************************************************
	> File Name: fprintf.c
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Sun 28 Apr 2024 03:19:28 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp = fopen("data.txt", "w");
    if (fp == NULL) {
        printf("failed to open file\n");
        exit(1);
    }
    fprintf(fp, "hello world\n");
    int a = 123, b = 456;
    fprintf(fp, "a = %d, b = %d\n", a, b);
    fclose(fp); 
    return 0;
}
