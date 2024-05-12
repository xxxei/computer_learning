/*************************************************************************
	> File Name: mult_array.c
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Sat 20 Apr 2024 10:04:12 AM CST
 ************************************************************************/

#include<stdio.h>

int main() {
    int b[3][4], cnt = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            b[i][j] = (cnt++);
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%3d ", b[i][j]);
        }
        printf("\n");
    }
    return 0;
}
