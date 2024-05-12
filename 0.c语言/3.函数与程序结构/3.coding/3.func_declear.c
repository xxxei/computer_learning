/*************************************************************************
	> File Name: 3.func_declear.c
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Tue 16 Apr 2024 09:49:48 PM CST
 ************************************************************************/

#include<stdio.h>

int a_func(int);
int b_func(int);

int main() {
    a_func(2);
    b_func(1);
    return 0;
}

int a_func(int x) {
    switch (x) {
        case 1: printf("%d\n", 3 * x); break;
        case 2: return b_func(x);
    }
    return 0;
}

int b_func(int x) {
    switch (x) {
        case 1: return a_func(x);
        case 2: printf("%d\n", 2 * x); break;
    }
}
