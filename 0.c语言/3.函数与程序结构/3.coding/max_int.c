/*************************************************************************
	> File Name: max_int.c
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Thu 18 Apr 2024 11:03:55 AM CST
 ************************************************************************/

#include <stdio.h>
#include <stdarg.h>
#include <inttypes.h>

int max_int(int n, ...) {
    va_list args;
    va_start(args, n);//表示n后面的变参列表的第一个元素
    int ans = INT32_MIN;
    for(int i = 0; i < n; i++) {
        int a = va_arg(args, int);
        if(a > ans) ans = a;
    }
    va_end(args);
    return ans;
}
