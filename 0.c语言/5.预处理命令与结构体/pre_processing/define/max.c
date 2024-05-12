/*************************************************************************
	> File Name: max.c
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Tue 23 Apr 2024 09:07:52 PM CST
 ************************************************************************/

#include<stdio.h>

#define p(func) { \
    printf("%s = %d\n", #func, func); \
}

#define MAX(a, b) ({ \
    int __a = (a), __b = (b); \
    __a > __b ? __a : __b; \
})

int main() {
    p(MAX(2, 3));
    p(5 + MAX(2, 3)); //----> 5 + 2 > 3 ? 2 : 3
    p(MAX(2, MAX(3, 4)));
    p(MAX(2, 3 > 4 ? 3 : 4));
    int a = 7;
    p(MAX(a++, 6));
    printf("after a = %d\n", a);
    return 0;
}
