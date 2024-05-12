/*************************************************************************
	> File Name: 3.cout.cpp
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Tue 07 May 2024 09:24:36 AM CST
 ************************************************************************/

#include <iostream> // input output stream
#include <iomanip>
using namespace std;

int main() {
    int a = 123;
    cout << "hello world" << endl;
    cout << a << endl;
    cout << "a = " << a << endl; // 连续输出功能

    double b = 12.345;
    cout << b << endl; // cout本质上和%g格式占位符相同 以尽可能简短的模式输出
    cout << setprecision(4) << b << endl; // 4位有效数字
    cout << fixed << setprecision(4) << b << endl; // 表示后续用定点格式设置输出 小数点后四位
    return 0;
}
