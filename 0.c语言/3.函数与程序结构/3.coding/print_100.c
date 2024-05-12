/*************************************************************************
	> File Name: print_100.c
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Thu 18 Apr 2024 10:56:29 AM CST
 ************************************************************************/

#include<stdio.h>
int cnt = 100;
int main() {
    int n = cnt;
    cnt -= 1;
    if(n == 1) {
        printf("%d\n", n);
        return 0;
    }
    main();
    printf("%d\n", n);
    return 0;
}
