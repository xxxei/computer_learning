/*************************************************************************
	> File Name: 7.radix_sort.cpp
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Sat 18 May 2024 11:25:36 AM CST
 ************************************************************************/

#include <iostream>
#include "0.sort_test.h"

using namespace std;

void radix_sort(int *arr, int l, int r) {
    #define K 65536
    int *cnt = (int *)malloc(sizeof(int) * K);
    int *temp = (int *)malloc(sizeof(int) * (r - l));
    memset(cnt, 0, sizeof(int) * K);
    for (int i = l; i < r; i++) cnt[arr[i] % K] += 1;
    for (int i = 1; i < K; i++) cnt[i] += cnt[i - 1];
}

int main() {
    
    return 0;
}
