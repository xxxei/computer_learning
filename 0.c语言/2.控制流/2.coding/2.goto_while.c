/*************************************************************************
	> File Name: 2.goto_while.c
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Tue 16 Apr 2024 08:59:55 AM CST
 ************************************************************************/

#include<stdio.h>

int main() {
    int n, i = 1;
    scanf("%d", &n);
juge:
    if(i <= n) goto stmt;
    else goto while_end;
stmt:
    printf("%d ", i++);
    goto juge;
while_end:
    printf("\n");
    return 0;
}
