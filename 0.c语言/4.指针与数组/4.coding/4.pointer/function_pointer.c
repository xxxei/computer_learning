/*************************************************************************
	> File Name: function_pointer.c
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Sun 21 Apr 2024 09:29:49 AM CST
 ************************************************************************/

#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void test1() {
    printf("function test1\n");
    return ;
}
void test2() {
    printf("function test2\n");
    return ;
}
void test3() {
    printf("function test3\n");
    return ;
}
void (*p)(); //一个指针指向所有返回值为void类型的函数

int main() {
    srand(time(0));
    p = test1;
    p();
    p = test2;
    p();
    p =test3;
    p();
    void (*arr[3])() = {test1, test2, test3};
    for (int i = 0; i < 10; i++) {
        arr[rand() % 3]();
    }
    return 0;
}
