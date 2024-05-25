/*************************************************************************
	> File Name: 6.HZOJ_166_字符串操作.cpp
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Sat 18 May 2024 01:26:21 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

int main() {
    string a, b;
    int x;
    cin >> a >> x >> b;
    cout << min((int)a.size(), 100) << endl;
    cout << a.insert(x - 1, b) << endl;
    cout << a.size() - a.rfind('x') << endl; // 输出最后一次出现字符x的位置(是以顺数下标位给出)  find则是与之相反查找第一次出现的位置
    return 0;
}
