/*************************************************************************
	> File Name: 5.string.cpp
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Tue 07 May 2024 12:44:40 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    cout << s1 << endl;
    if (s1 < s2) cout << s1 << " < " << s2 << endl;
    if (s1 == s2) cout << s1 << " = " << s2 << endl;
    if (s1 > s2) cout << s1 << " > " << s2 << endl;
    cout << "s1.length() = " << s1.length() << endl;
    cout << "s2.size() = " << s2.size() << endl;
    for (int i = 0; i < s1.length(); i++) {
        cout << "s1[" << i << "] = " << s1[i] << endl;
    }
    for (int i = 0; s2[i]; i++) { // 当s2[i]不为零时循环
        cout << "s2[" << i << "] = " << s2[i] << endl;
    }
    cout << s1 + s2 << endl; // 拼接两个字符串
    cout << s1 + "hello world" << endl;
    cout << s1.substr(1, 2) << endl; // 取集合中的子集 下标从零开始
    return 0;
}
