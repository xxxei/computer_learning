/*************************************************************************
	> File Name: 1.变位词.cpp
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Sun 12 May 2024 08:05:47 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore(); // 清除输入缓冲区中的换行符
    while (n--) {
        string str1, str2;
        getline(cin, str1, ' '); // 读取第一个单词
        getline(cin, str2); // 读取第二个单词

        // 将单词中的字符按字母顺序排序
        sort(str1.begin(), str1.end());
        sort(str2.begin(), str2.end());

        // 判断排序后的单词是否相等
        if (str1 == str2) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}
