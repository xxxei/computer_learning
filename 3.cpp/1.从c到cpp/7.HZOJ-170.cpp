/*************************************************************************
	> File Name: 7.HZOJ-170.cpp
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Sat 18 May 2024 02:58:47 PM CST
 ************************************************************************/

#include <iostream>
#include <string>

using namespace std;

int main() {
    string str[100];
    string olds = "Ban_smoking", news = "No_smoking";
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> str[i];        
    }
    for (int i = 0; i < n; i++) {
        int pos = str[i].find(olds);
        if (pos == -1) continue;
        str[i].replace(pos, olds.size(), news);
    }
    for (int i = 0; i < n; i++) {
        cout << str[i] << endl;
    }
    return 0;
}
