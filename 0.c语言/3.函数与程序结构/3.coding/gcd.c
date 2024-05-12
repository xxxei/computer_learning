/*************************************************************************
	> File Name: gcd.c
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Thu 18 Apr 2024 10:25:18 AM CST
 ************************************************************************/

#include<stdio.h>

int gcd(int a, int b);
int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d\n", gcd(a, b));
    return 0;
}

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b , a % b);
}
