/*************************************************************************
	> File Name: text.c
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Fri 12 Apr 2024 09:29:50 PM CST
 ************************************************************************/

#include<stdio.h>
#include<math.h>

int main() {
    double x;
    scanf("%lf", &x);
    printf("%lf\n", (x / 180) * acos(-1));
    return 0;
}
