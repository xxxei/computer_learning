/*************************************************************************
	> File Name: 一个月有多少天.c
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Thu 18 Apr 2024 08:10:00 PM CST
 ************************************************************************/

#include<stdio.h>

int main() {
    int y, m, a;
    scanf("%d%d", &y, &m);
    a = (y % 100 != 0 && y % 4 == 0) || y % 400 == 0;
    if (m == 1 || m == 3 || m == 5
        || m == 7 || m == 8 || m == 10 || m == 12) {
        printf("31\n");
    } else if (m == 4 || m == 6 || m == 9 || m == 11) {
        printf("30\n");
    } else {
        printf("%d\n", 28 + a);
    }
    return 0;
}
