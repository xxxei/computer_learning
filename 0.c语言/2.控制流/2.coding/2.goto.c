/*************************************************************************
	> File Name: 2.goto.c
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Tue 16 Apr 2024 08:27:01 AM CST
 ************************************************************************/

#include<stdio.h>

int main() {
    goto lab1;
    printf("sfsdfsdfsf");
lab1:
    printf("hello jj\n");
//------------------------------//
    goto lab2;
    int a = 0, b = 0;
    scanf("%d%d", &a, &b);
lab2:
    printf("%d\n", a * b);//a， b被定义了但是没有被初始化

    return 0;
}
