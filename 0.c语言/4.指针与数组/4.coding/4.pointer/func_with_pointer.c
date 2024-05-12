/*************************************************************************
	> File Name: func_with_pointer.c
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Sat 20 Apr 2024 11:35:03 AM CST
 ************************************************************************/

#include<stdio.h>

void add_once(int *p) {
    *p += 1;
    return ;
}//函数中修改实参值

void f(int n, int *sum_r) {
    *sum_r = (1 + n) * n / 2;
    return;
}//涉及到多个传出参数时

void output(int *p, int n) {
    for (int i = 0; i < n; i++) {
        printf("p[%d] = %d\n", i, *(p++)); //*(p++) == p[i++] 指针地址加等于1指的是地址加上一个sizeof（type）的长度
    }//p[i] == *(p + i)
    return ;
}//接收数组

int main() {
    int a = 123;
    printf("%d\n", a);
    add_once(&a);
    printf("%d\n", a);
    int n = 10, sum;
    f(n, &sum);
    printf("%d\n", sum);
    int arr[10] = {9, 8, 5, 3, 6, 2, 1, 0, 4, 7};
    output(arr, sizeof(arr) / sizeof(int));

    int (*p4)[10] = 0x0;//一个指针指向的是一个存储十个整型变量的数组的地址
    int arr2[30][10];
    p4 = arr2;
    printf("p4 + 0 = %p\n", p4 + 0);
    printf("p4 + 1 = %p\n", p4 + 1);
    printf("p4 + 2 = %p\n", p4 + 2);
    int *p5[10];//一个数组，每个存储空间中存储一个整型变量的地址
    int *(*p6[10])[20];//十个数组，每个数组中存储着一个指向二十个整型指针变量的数组的地址


    return 0;
}
