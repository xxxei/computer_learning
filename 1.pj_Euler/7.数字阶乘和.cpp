/*************************************************************************
	> File Name: 7.数字阶乘和.cpp
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Tue 07 May 2024 08:14:06 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

#define MAX_N 2540160 // 9! * 7

int jiec(int n) {
    if (n == 0) return 1;
    return jiec(n-1) * n;
}

int is_val(int n) {
    int temp = 0, x = n;
    while (x) {
        temp += jiec(x % 10);
        x /= 10;
    }
    return temp == n;
}

int main() {
    int sum = 0;
    for (int i = 3; i < MAX_N; i++) {
        if (!is_val(i)) continue;
        sum += i;
    }
    cout << sum << endl;
    return 0;
}
