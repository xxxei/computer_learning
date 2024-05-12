/*************************************************************************
	> File Name: 4.set.cpp
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Mon 06 May 2024 06:38:17 PM CST
 ************************************************************************/

#include <iostream>
#include <set>
using namespace std;

void test1() {  // 插入
    cout << "set base usage" << endl;
    set<int> s;
    s.insert(4);
    s.insert(5);
    cout << s.size() << endl;
    s.insert(6);
    cout << s.size() << endl;
    return ;
}

void test2() {  // 去重
    cout << "set item unique feature 1: " << endl;
    set<int> s;
    s.insert(3);
    s.insert(4);
    cout << s.size() <<endl;
    s.insert(4);
    cout << s.size() <<endl;
    return ;
}

void test3() {  // 不去重
    cout << "set item unique feature 2: " << endl;
    typedef pair<int, int> PII; // 将两个int打包成一个数据，第一个为int值，第二个int为顺序
    set<PII> s;
    int tot = 0;
    cout << s.size() << endl;
    s.insert(PII(3, tot++));
    s.insert(PII(4, tot++));
    cout << s.size() <<endl;
    s.insert(PII(4, tot++));
    cout << s.size() <<endl;
    return ;
}

void test4() {
    cout << "foreach set item : " << endl;
    typedef pair<int, int> PII; // 将两个int打包成一个数据，第一个为int值，第二个int为顺序
    set<PII> s;
    int tot = 0;
    s.insert(PII(3, tot++));
    s.insert(PII(4, tot++));
    s.insert(PII(4, tot++));
    for (auto x : s) {
        cout << "(" << x.first << ", " << x.second << ")" << endl;
    }
    return ;
}

void test5() {
    cout << "set replace heap : " << endl;
    typedef pair<int, int> PII;
    int tot = 0;
    set<PII> s;
    for (int i = 0; i < 10; i++) {
        s.insert(PII(rand() % 20, tot++)); // push
    }
    for (int i = 0; i < 4; i++) {
        cout << "s.begin() = " << s.begin()->first << endl;; // 访问集合中的第一个元素就是最小值
        s.erase(s.begin()); // pop
    }
    return ;
}

int main() {
    test1();
    test2();
    test3();
    test4();
    test5();
    return 0;
}

