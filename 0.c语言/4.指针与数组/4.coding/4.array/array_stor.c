/*************************************************************************
	> File Name: array_stor.c
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Sat 20 Apr 2024 11:06:02 AM CST
 ************************************************************************/

#include<stdio.h>

int main() {
    int arr[10][10];
    printf("&arr[0][0] = %p\n", arr);
    printf("&arr[0][1] = %p\n", &arr[0][1]);
    printf("&arr[1][0] = %p\n", &arr[1][0]);
    return 0;
}
