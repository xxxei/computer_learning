/*************************************************************************
	> File Name: 6.merge_sort.cpp
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Sat 18 May 2024 10:26:39 AM CST
 ************************************************************************/

#include <iostream>
#include "0.sort_test.h"

using namespace std;

void merge_sort(int *arr, int l, int r) {
    // partition
    if (r - l <= 1) return ;
    int mid = (l + r) / 2;
    merge_sort(arr, l, mid);
    merge_sort(arr, mid, r);
    // merge
    int p1 = l, p2 = mid, k = 0;
    int *temp = (int *)malloc(sizeof(int) * (r - l));
    while (p1 < mid || p2 < r) {
        if (p2 == r || (p1 < mid && arr[p1] <= arr[p2])) {
            temp[k++] = arr[p1++];
        } else {
            temp[k++] = arr[p2++];
        }
    }
    // copy
    for (int i = l; i < r; i++) arr[i] = temp[i - l];
    free(temp);
    return ;
}

int main() {
    int *arr = getRandData(BIG_DATA_N);
    TEST(merge_sort, arr, BIG_DATA_N);
    free(arr);
    return 0;
}
