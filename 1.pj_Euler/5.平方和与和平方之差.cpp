/*************************************************************************
	> File Name: 5.平方和与和平方之差.cpp
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Tue 07 May 2024 07:09:04 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_N 100
int main() {
    int sum1 = 0, sum2 = 0;
    for (int i = 1; i <= MAX_N; i++) {
        sum1 += i;
        sum2 += i * i;
    }
    cout << sum1 * sum1 - sum2 << endl;
    return 0;
}


sum1 = (1 + n) * n >> 1
sum2 = n * (n + 1) * (2 * n + 1) / 6 // 平方和公式
