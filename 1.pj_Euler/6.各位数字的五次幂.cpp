/*************************************************************************
	> File Name: 6.各位数字的五次幂.cpp
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Tue 07 May 2024 07:39:52 PM CST
 ************************************************************************/

#include <iostream>
#include <cmath>
using namespace std;
#define MAX_N  2177280 
int is_right(int n) {
    int temp = 0, x = n;
    while (x) {
        temp += (int)pow(x % 10, 5);
        x /= 10;
    }
    return temp == n;
}

int main() {
    int sum = 0;
    for (int i = 2; i < MAX_N; i++) {
        if (!is_right(i)) continue;
        sum += i;
    }
    cout << sum <<endl;
    return 0;
}
