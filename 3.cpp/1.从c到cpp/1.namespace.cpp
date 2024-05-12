/*************************************************************************
	> File Name: 1.namespace.cpp
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Tue 07 May 2024 08:44:26 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

namespace apple { // 使用namespace对apple命名空间进行分组管理

int cnt = 0;
void inc() {
    cnt += 1;
    return ;
}

}

int banana_cnt = 0;
void banana_inc() {
    banana_cnt += 1;
    return ;
}

#define P(msg) { \
    printf("%s = %d\n", #msg, msg); \
}

int main() {
    apple::cnt += 2; // ::表示域限定符 表示访问apple域中的cnt变量
    P(apple::cnt);
    return 0;
}
