/*************************************************************************
	> File Name: 4.cin.cpp
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Tue 07 May 2024 09:37:06 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int main() {
    int a;
    cin >> a;
    cout << "a = " << a << endl;
    double b;
    char c[100];
    cin >> a >> b >> c;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;
    while (cin >> a) { // 
        cout << "a = " << a << endl;
    }
    return 0;
}
