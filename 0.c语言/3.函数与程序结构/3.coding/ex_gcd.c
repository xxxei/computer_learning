/*************************************************************************
	> File Name: ex_gcd.c
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Thu 18 Apr 2024 10:40:19 AM CST
 ************************************************************************/

#include<stdio.h>

int x, y, nx, ny;

int ex_gcd(int a, int b) {
    if(b == 0) {
        x = 1, y = 0;
        return a;
    }
    int c = ex_gcd(b, a % b);
    nx = y, ny = x - (a / b) * y;
    x = nx, y = ny;
    return c;
}
int main() {
    int a, b;
    while(scanf("%d%d", &a, &b) != EOF) {
        int c = ex_gcd(a, b);
        printf("%d * %d + %d * %d = %d\n", a, x, b, y, c);
    }
    return 0;
}
