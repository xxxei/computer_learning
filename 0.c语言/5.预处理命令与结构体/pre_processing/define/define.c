/*************************************************************************
	> File Name: define.c
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Tue 23 Apr 2024 07:58:15 PM CST
 ************************************************************************/

#include<stdio.h>

#define PI 3.1415926
#define S(a, b) a * b
#define P(a) {\
    printf("define P : %d\n", a);\
    printf("%p\n", &a);\
}// \是续行符

int main() {
    printf("PI = %lf\n", PI);
    printf("S(3, 4) = %d\n", S(3, 4));
    printf("S(3 + 7, 4) = %d\n", S(3 + 7, 4));
    S(int, p);//定义了一个指针  ---> int * p
    int n = 123;
    p = &n;
    P(*p);
    return 0;
}
