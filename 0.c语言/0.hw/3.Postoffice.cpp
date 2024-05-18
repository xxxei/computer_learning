/*************************************************************************
	> File Name: 3.Postoffice.cpp
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Mon 13 May 2024 08:27:04 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm> 
#include <cmath>

using namespace std;

int main() {
    int num;
    cin >> num;
    int x[100], y[100];
    for (int i = 0; i < num; i++) {
        cin >> x[i] >> y[i];
    }
    sort(x, x + num);
    sort(y, y + num);
    int X, Y, sum;
    X = x[num / 2];
    Y = y[num / 2];
    for (int i = 0; i < num; i++) {
        sum += abs(x[i] - X) + abs(y[i] - Y);
    }
    cout << sum << endl;
    return 0;
}
