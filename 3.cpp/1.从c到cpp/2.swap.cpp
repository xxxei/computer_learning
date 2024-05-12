/*************************************************************************
	> File Name: 2.swap.cpp
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Tue 07 May 2024 09:07:36 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

void swap(int &pa, int &pb) { // pa pb 表示引用参数 代表实参
    int c = pa;
    pa = pb;
    pb = c;
    return ;
}

#define P(msg) { \
    printf("%s = %d\n", #msg, msg); \
}

void inc(int &x) {
    x += 1;
    return ;
}

int main() {
    int a = 3, b = 5;
    P(a); P(b);
    swap(a, b);
    P(a); P(b);
    inc(a); inc(b);
    P(a); P(b);
    return 0;
}
