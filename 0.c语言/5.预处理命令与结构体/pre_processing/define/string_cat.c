/*************************************************************************
	> File Name: string_cat.c
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Tue 23 Apr 2024 08:54:00 PM CST
 ************************************************************************/

#include<stdio.h>

#define STR(n) #n  //#的功能是把n字符串化
#define RUN(func) {\
    func;\
    printf("%s run done\n", #func);\
}   //将函数名以字符串的形式输出

void test1() {
    printf("this is test1\n");
}

void test2(int a, int b) {
    printf("this is test2 : %d, %d\n", a, b);
    return ;
} 

#define CAT(a, b) a##b  //将a和b的内容连接
int main() {
    printf("%s\n", STR(hello));
    RUN(test1());
    RUN(test2(2, 3));
    int n10 = 123, n11 = 456;
    CAT(n, 10) = 789; // ---> n10 = 789
    printf("n10 = %d, n11 = %d\n", n10, n11);
    return 0;
}
