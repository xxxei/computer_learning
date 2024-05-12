/*************************************************************************
	> File Name: 2.duanluyuanze.c
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Mon 15 Apr 2024 07:35:43 PM CST
 ************************************************************************/

#include<stdio.h>

int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    a += (a == b);//不使用ifelse语句实现a++
    (a < b) && printf("YES!\n");//不用ifelse实现printf(printf函数返回值为int类型)
    !(a < b) && printf("NO!\n");
    return 0;
}
