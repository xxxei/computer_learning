/*************************************************************************
	> File Name: 8.function.cpp
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Sat 18 May 2024 03:38:39 PM CST
 ************************************************************************/

#include <iostream>
#include <functional>
using namespace std;

void test() {
    cout << "hello test" << endl;
    return ;
}

int add(int a, int b) {
    return a + b;
}

int main() {
    function<void()> p1 = test; // function 可以指向函数对象和lambda表达式
    p1();
    function<int(int, int)> p2 = add;
    cout << p2(2, 5) << endl;
    return 0;
}
