/*************************************************************************
	> File Name: 0.注水问题.c
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Tue 16 Apr 2024 12:41:43 PM CST
 ************************************************************************/

#include<stdio.h>

int main() {
    double a, b, c, t;
    scanf("%lf%lf%lf%lf", &a, &b, &c, &t);
    double rest  = 1 - ((1.0 / a + 1.0 / b) * t);
    double t1 = (rest / (1.0 / a + 1.0 / b - 1.0 / c) + t);
    printf("%.2lf\n", t1);
    return 0;
}
