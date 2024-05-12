/*************************************************************************
	> File Name: args.c
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Wed 24 Apr 2024 02:21:24 PM CST
 ************************************************************************/

#include<stdio.h>
#define D_VAL(a, val) (#a[0]) ? a : val
#define test_func(a, b, c) \
__test_func(D_VAL(a, 43), D_VAL(b, 53), D_VAL(c, 12.3))

void __test_func(int a, int b, double c) {
    printf("a = %d, b = %d, c = %lf\n", a, b, c);
    return ;
}

int main() {
    test_func( , , );
    test_func(2, , );
    return 0;
}
