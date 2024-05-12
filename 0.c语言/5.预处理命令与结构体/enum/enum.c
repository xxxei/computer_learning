/*************************************************************************
	> File Name: enum.c
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Thu 25 Apr 2024 10:14:18 AM CST
 ************************************************************************/

#include<stdio.h>

#define p(a, format) { \
    printf("%s = " format "\n", #a, a); \
}

enum Number {
    zero,
    one,
    two = 10,  //依次往下加一
    three,
    four
};

enum func_data {
#ifdef test1
    func_test1,
#endif 
#ifdef test2
    func_test2,
#endif 
#ifdef test3
    func_test3,
#endif 
#ifdef test4
    func_test4,
#endif
    func_max
};

#define define_func(nam) \
void nam() { \
    printf("this is function : %s\n", #nam); \
}

define_func(test1)
define_func(test2)
define_func(test3)
define_func(test4)

void (*func_arr[func_max])() = {
#ifdef test1
    test1,
#endif 
#ifdef test2
    test2,
#endif 
#ifdef test3
    test3,
#endif 
#ifdef test4
    test4,
#endif 
};
int main() {
    for (int i = 0; i < func_max; i++) {
        func_arr[i]();
    }
    enum Number A;
    A = one;
    p(A, "%d");
    A = two;
    p(A, "%d");
    A = three;
    p(A, "%d");
    A = four;
    p(A, "%d");
    return 0;
}
