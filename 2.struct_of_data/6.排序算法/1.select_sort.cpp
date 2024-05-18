/*************************************************************************
	> File Name: 1.select_sort.cpp
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Fri 17 May 2024 11:05:38 AM CST
 ************************************************************************/

#include <iostream>
#include "0.sort_test.h"

using namespace std;

void selection_sort(int *arr, int l, int r) {
    for (int i = l, I = r - 1; i < I; i++) {
        int ind = i;
        for (int j = i + 1; j < r; j++) {
            if (arr[j] < arr[ind]) ind = j;
        }
        swap(arr[i], arr[ind]);
    }
    return ;
}

int main() {
    int *arr = getRandData(SMALL_DATA_N);
    TEST(selection_sort, arr, SMALL_DATA_N);
    free(arr);
    return 0;
}
