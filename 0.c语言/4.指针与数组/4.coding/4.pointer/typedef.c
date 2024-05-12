/*************************************************************************
	> File Name: typedef.c
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Sun 21 Apr 2024 10:34:57 AM CST
 ************************************************************************/

#include<stdio.h>

typedef long long LL; // 将longlong这种变量名替换成LL自己定义的别名（方便使用）
typedef int (*Arr2Dim10)[10];
typedef void (*Func)(); //函数指针指向返回值为void传入参数为空的一类的函数

void test() {
    printf("hello function pointer\n");
    return;
}

int main() {
    LL a;
    printf("sizeof(a) = %lu\n", sizeof(a));
    int arr[5][10];
    Arr2Dim10 p = arr; //定义一个指针p指向arr这个二维数组
    Func p2 = test;
    p2();
    return 0;
}
