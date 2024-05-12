/*************************************************************************
	> File Name: 1.types.c
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Fri 12 Apr 2024 04:48:41 PM CST
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>

int main(){
    int a = 123, b = 97, c, d;
    c = 100063;
    d = 9651;
    printf("%d %d %d %d\n", a, b, c, d);
    //a = 2147483647 + 1;
    //printf("%d\n", a);
    printf("INT32_MIN = %d\n",INT32_MIN);
    printf("INT32_MAX = %d\n",INT32_MAX);
    long long e;
    e = 2147483647LL + 1;
    printf("%lld\n",e);
    float f = e + 0.1;
    double ff = e + 0.123456;
    printf("float = %.9f\n",f);//有效数字7位，默认输出6位
    printf("double = %.9lf\n",ff);//有效数字15位，默认输出6位
    char g = 'a';
    printf("%c\n",g);
    printf("%d\n",g);
    printf("sizeof(int) = %lu\n",sizeof(int));
    printf("sizeof(float) = %lu\n",sizeof(float));
    printf("sizeof(double) = %lu\n",sizeof(double));
    printf("sizeof(char) = %lu\n",sizeof(char));//%lu表示输出无符号长整型整数 (long unsigned)
    return 0;
}
