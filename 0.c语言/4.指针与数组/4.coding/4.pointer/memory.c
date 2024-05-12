/*************************************************************************
	> File Name: memory.c
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Sun 21 Apr 2024 09:55:36 AM CST
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int *arr1 = (int *)malloc(sizeof(int) * 10);//申请十个整型变量的内存大小 ==> 40B;函数返回值是一个任意类型的指针（地址）
    for (int i = 0; i < 10; i++) {
        printf("arr1[%d] = %d\n", i, arr1[i]);
    }
    int *arr2 = (int *)calloc(10, sizeof(int));
    for (int i = 0; i < 10; i++) {
        printf("arr2[%d] = %d\n", i, arr2[i]);
    }
    free(arr1);
    free(arr2);

    char s1[100] = "hello world";
    char s2[100];
    char s3[100];
    memcpy(s2, s1, 12);
    memmove(s3, s1, 12);
    printf("%s\n", s2);
    printf("%s\n", s3);
    memcpy(s2 + 4, s2, 12);
    memmove(s3 + 4, s3, 12);
    printf("%s\n", s2);
    printf("%s\n", s3);
    return 0;
}
