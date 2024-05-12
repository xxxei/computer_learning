/*************************************************************************
	> File Name: HZOJ-142.c
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Thu 18 Apr 2024 09:31:36 PM CST
 ************************************************************************/

#include<stdio.h>

int main() {
    int a, b, c = 0;
    scanf("%d%d", &a, &b);
    for (int i = a; i <= b; i++) {
        int flag = 1;
        for (int j = 2; j * j <= i; j++) {
            if (i % j) continue; 
            flag = 0;
        }
        if (flag == 1) {
            int x = i, y = 0;
            while (x) {
            y = y * 10 + x  % 10;
            x /= 10;
        }
        if (y != i) continue;
        if (c) printf(" ");
        if (y == i) c += printf("%d", i);
    }}
    printf("\n");


    return 0;
}
