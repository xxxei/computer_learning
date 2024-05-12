/*************************************************************************
	> File Name: 4.最大回文数乘积.cpp
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Tue 07 May 2024 06:41:04 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int is_reverse(int n, int base) { // 十进制优化
    int temp = 0, x = n;
    while (x) {
        temp = temp * base + x % base;
        x /= base;
    }
    return temp == n;
}

int main() {
    int ans = 1;
    for (int a = 999; a >= 100; a--) { // 倒序优化
        for (int b = a; b >= 100; b--) {
            if (a * b <= ans || !is_reverse(a * b, 10)) continue; // 1.先判断a * b大小再判断isreverse优化  2.对偶优化
            ans = a * b;
            cout << a << " * " << b << " = "<< ans << endl;
            
        }
    }
    cout << "ans = " << ans << endl;
    return 0;
}
