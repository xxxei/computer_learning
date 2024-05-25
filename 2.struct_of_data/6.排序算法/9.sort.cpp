/*************************************************************************
	> File Name: 8.sort.cpp
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Wed 22 May 2024 04:25:41 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
#include "0.sort_test.h"
using namespace std;

void output(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return ;
}

void output(vector<int> &arr) {
    cout << "arr[" << arr.size() << "] = ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return ;
}

void test1() {
    // sort array
    cout << "test array : " << endl;
    int *arr = getRandData(10);
    output(arr, 10);
    sort(arr, arr + 10); // [) 传入起始地址和结束地址
    output(arr, 10);
    sort(arr, arr + 10, greater<int>()); // 模板函数
    output(arr, 10);
    free(arr);
    return ;
}

void test2() {
    // sort vector 
    cout << "test vector : " << endl;
    vector<int> arr;
    for (int i = 0; i < 10; i++) arr.push_back(rand() % 10000);
    output(arr);
    sort(arr.begin(), arr.end());
    output(arr);
    return ;
}

int main() {
    test1();
    test2();
    return 0;
}
