/*************************************************************************
	> File Name: even_fibonacci.c
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Sun 28 Apr 2024 05:08:33 PM CST
 ************************************************************************/

#include<stdio.h>

#define MAX_N 4000000

//int fib[35] = {1, 1, 2};

/*  测试数组到底开多大的范围
int main() {
    fib[1] = 1, fib[2] = 2;
    int n = 2;
    for (int i = 3; ; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
        n += 1;
        if(fib[i] >= MAX_N) break;
    }
    return 0;
}
    普通版本
int main() {
    int n = 2, sum = 0;
    while (fib[n - 1] + fib[n - 2] < MAX_N) {
        fib[n] = fib[n - 1] + fib[n - 2];
        if (fib[n] % 2 == 0) sum += fib[n];
        n += 1;
    }
    printf("%d\n", sum);
    return 0;
}
*/

//优化版本(滑动数组)

int fib[3] = {0, 1, 2};

int main() {
    int n = 2, sum = 2;
    while (fib[n % 3] + fib[(n - 1) % 3] < MAX_N) {
        n += 1;
        fib[n % 3] = fib[(n - 1) % 3] + fib[(n - 2) % 3];
        if (!(fib[n % 3] & 1)) sum += fib[n % 3]; // & 1 == % 2
    }
    printf("%d\n", sum);
    return 0;  
}

//还有高手
int a = 1, b = 2, sum = 2;
while (a + b < MAX_N) {
    a = a + b;
    a ^= b;
    b ^= a;
    a ^= b;
    if (!(b & 1)) sum += b;
}



