/*************************************************************************
	> File Name: math.c
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Fri 12 Apr 2024 09:10:17 PM CST
 ************************************************************************/

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main() {
    printf("pow(2, 3) = %lf\n", pow(2, 3));//pow函数返回double类型值，传入两个double类型值
    printf("sqrt(16) = %lf\n", sqrt(16));//同理
    printf("ceil(4.01) = %lf\n", ceil(4.01));//向上取整 -> 5
    printf("floor(4.99) = %lf\n", floor(4.99));//向下取整 -> 4
    printf("abs(-4) = %d\n", abs(-4));//传入整数返回整数绝对值（在stdlib.h中）
    printf("fabs(-3.93) = %lf\n", fabs(-3.93));//浮点数取整（在math.h中）
    printf("acos(-1) = %lf\n", acos(-1));//传入角度的余弦值返回其对应的弧度值
    return 0;
}
