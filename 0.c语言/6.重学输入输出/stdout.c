/*************************************************************************
	> File Name: stdout.c
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Sun 28 Apr 2024 09:20:49 AM CST
 ************************************************************************/

#include<stdio.h>

int main() {
    printf("asdfgwgjs2344\n"); // 换行符可以直接将输出缓冲区的内容输出到终端缓冲区
    fflush(stdout); // “冲刷”stdout文件
    *((int *)(0)) = 5;
    return 0;
}
