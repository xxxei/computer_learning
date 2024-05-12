/*************************************************************************
	> File Name: Largest_prime_factor.c
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Sun 28 Apr 2024 05:56:04 PM CST
 ************************************************************************/

#include<stdio.h>

typedef long long LL;

LL max_num() {
    LL num = 600851475143;
    LL max = 0;
    int flag = 1;
    for (LL i = 2; i < num; i++) {
        for (LL j = 2; j *j < i; j++) {
            if (i % j) continue;
            else {
                flag = 0;
                break;
            }
        }
        if (flag == 1) max = i;
    }
    return max;
}

int main() {
    printf("%lld\n", max_num());
    return 0;
}
