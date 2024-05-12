/*************************************************************************
	> File Name: 3.sumc.c
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Tue 16 Apr 2024 09:32:55 PM CST
 ************************************************************************/

#include<stdio.h>

int sum(int a1, int r, int d) {
    int n = (r - a1) / d + 1;
    int an = a1 + (n - 1) * d;
    return (a1 + an) * n / 2;
}
int main() {
    printf("%d %d %d\n",
        sum(1, 100, 1),
        sum(1, 100, 2),
        sum(26, 3677, 47)
    );
    return 0;
}
