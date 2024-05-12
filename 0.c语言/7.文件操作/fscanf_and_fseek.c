/*************************************************************************
	> File Name: fscanf_and_fseek.c
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Wed 01 May 2024 07:38:10 PM CST
 ************************************************************************/

#include<stdio.h>

int main() {
    FILE *fp = fopen("data5.txt", "r");
    int n;
    fseek(fp, 5, SEEK_SET); // feek控制文件指针位置影响输出 SEEK_SET是指从头开始往后数5个位置
    fscanf(fp, "%d", &n);
    printf("fscanf n = %d\n", n);
    return 0;
}
