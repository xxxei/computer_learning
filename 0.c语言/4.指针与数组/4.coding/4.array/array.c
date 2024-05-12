/*************************************************************************
	> File Name: array.c
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Thu 18 Apr 2024 03:06:43 PM CST
 ************************************************************************/

#include<stdio.h>

void test1() {
    int a[] = {1, 2, 3, 4, 5, 6, 7};
    size_t size = sizeof(a) / sizeof(int); //无符号整型size_t
    printf("sizeof(a) / sizeof(int) = %lu\n", sizeof(a) / sizeof(int));
    printf("a = %p\n", a);
    printf("&a[0] = %p\n", &a[0]);
    for (int i = 0; i < size; i++) {
        printf("&a[%d] = %p\n", i, &a[i]);
    }
    return ;
}

int main() {
    test1();

    return 0;
}
