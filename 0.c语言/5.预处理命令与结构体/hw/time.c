/*************************************************************************
	> File Name: time.c
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Wed 24 Apr 2024 01:54:33 PM CST
 ************************************************************************/

#include<stdio.h>
#include <time.h>

#define TIME(func) { \
    long long b = clock(); \
    func; \
    long long a = clock(); \
    printf("%s run %lldms\n", #func, 1000 * (a - b) / CLOCKS_PER_SEC); \
}  // clock（）是时间戳 CLOCKS_PER_SEC指的是一秒有多少时间戳

void test(int n) {
    long long sum = 0;
    for (int i = 1; i <= n; i++) sum += i;
    printf("sum = %lld\n", sum);
    return ;
}

int main() {
    TIME(test(100000));
    TIME(test(100000000));
    TIME(test(1000000000));
    return 0;
}
