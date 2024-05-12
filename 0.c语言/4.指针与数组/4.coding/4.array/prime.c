/*************************************************************************
	> File Name: prime.c
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Thu 18 Apr 2024 03:19:02 PM CST
 ************************************************************************/

#include<stdio.h>

int prime[100] = {0};

void init_prime(int n) {
    prime[0] = prime[1] = 1;
    for (int i = 2; i * i <= n; i++) {
        if (prime[i]) continue;
        printf("isprime = %d\n", i);
        for (int j = i * i; j <= n; j += i) {
            prime[j] = 1;
            printf("isnotprime = %d\n", j);
        }
    }
    return ;
}

int main() {
    init_prime(100);
    int x;
    while (scanf("%d", &x) != EOF) {
        printf("prime[%d] = %d\n", x, prime[x]);
    }
    return 0;
}
