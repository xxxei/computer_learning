/*************************************************************************
	> File Name: 2.for.c
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Tue 16 Apr 2024 08:15:39 AM CST
 ************************************************************************/

#include<stdio.h>

int main() {
    int a = 1, b = 1, c;
    for(int i = 0; i < 20; i++) {
        printf("%d ", a);
        c = a + b;
        a = b;
        b = c;
    }
    printf("\n");

    for(int i = 0, f1 = 1, f2 = 1; i < 20; i++, f2 += f1, f1 = f2 - f1) {
        printf("%d ", f1);
    }
    printf("\n");
    return 0;
}
