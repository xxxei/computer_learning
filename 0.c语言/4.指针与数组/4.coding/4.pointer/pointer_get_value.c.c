/*************************************************************************
	> File Name: pointer_get_value.c.c
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Sat 20 Apr 2024 09:17:08 PM CST
 ************************************************************************/

#include<stdio.h>

int main() {
    int n = 0x61626364;
    char *p = (char *)&n;
    printf("*(p + 0) = %c\n", *(p + 0));
    printf("*(p + 1) = %c\n", *(p + 1));
    printf("*(p + 2) = %c\n", *(p + 2));
    printf("*(p + 3) = %c\n", *(p + 3));//指针取值的大小只与指针类型有关

    return 0;
}
