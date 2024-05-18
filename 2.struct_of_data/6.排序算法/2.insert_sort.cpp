/*************************************************************************
	> File Name: 2.insert_sort.cpp
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Fri 17 May 2024 03:15:58 PM CST
 ************************************************************************/

#include <iostream>
#include "0.sort_test.h"

using namespace std;

void insert_sort(int *arr, int l, int r) {
    for (int i = l + 1; i < r; i++) {
        int j = i;
        while (j > l && arr[j] < arr[j - 1]) {
            swap(arr[j], arr[j - 1]);
            j -= 1;
        }
    }
    return ;
}

void unguarded_insert_sort(int *arr, int l, int r) {
    int ind = l;
    for (int i = l + 1; i < r; i++) {
        if (arr[i] < arr[ind]) ind = i;
    }
    while (ind > l) {
        swap(arr[ind], arr[ind - 1]); // 为了不破坏插入排序算法的稳定性 采取一位一位向前排序
        ind -= 1;
    }
    for (int i = l + 1; i < r; i++) {
        int j = i;
        while (arr[j] < arr[j - 1]) {
            swap(arr[j], arr[j - 1]);
            j -= 1;
        }
    }
    return ;
}

int main() {
    int *arr = getRandData(SMALL_DATA_N);
    TEST(insert_sort, arr, SMALL_DATA_N);
    TEST(unguarded_insert_sort, arr, SMALL_DATA_N);
    free(arr);
    return 0;
}
