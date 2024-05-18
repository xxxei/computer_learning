/*************************************************************************
	> File Name: 5.quick_sort.cpp
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Wed 15 May 2024 03:38:55 PM CST
 ************************************************************************/

#include <iostream>
#include "0.sort_test.h"
using namespace std;

void quick_sort(int *arr, int l, int r) {
    if (r - l <= 2) {
        if (r - l <= 1) return ;
        if (arr[l] > arr[l + 1]) swap(arr[l], arr[l + 1]);
        return ;
    }
    int x = l, y = r - 1, z = arr[l];
    while (x < y) {
        while (x < y && z <= arr[y]) --y;
        if (x < y) arr[x++] = arr[y];
        while (x < y && arr[x] <= z) ++x;
        if (x < y) arr[y--] = arr[x];
    }
    arr[x] = z;
    quick_sort(arr, l, x);
    quick_sort(arr, x + 1, r);
    return ;
}

void quick_sort_v1(int *arr, int l, int r) {
    if (r - l <= 2) {
        if (r - l <= 1) return ;
        if (arr[l] > arr[l + 1]) swap(arr[l], arr[l + 1]);
        return ;
    }
    int x = l, y = r - 1, z = arr[l];
    do {
        while (arr[x] < z) ++x;
        while (arr[y] > z) --y;
        if (x <= y) { // 这里的判断条件是x <= y 说明最后xy相等时还会交换一次并且++x, --y;
            swap(arr[x], arr[y]);
            ++x, --y;
        }
    } while (x <= y);
    quick_sort_v1(arr, l, x);
    quick_sort_v1(arr, x, r);
    return ;
}

int three_point_select(int a, int b, int c) {
    if (a > b) swap(a, b);
    if (a > c) swap(a, c);
    if (b > c) swap(b, c);
    return b; // 最后返回的值是中间值
}

void quick_sort_v2(int *arr, int l, int r) {
    if (r - l <= 2) {
        if (r - l <= 1) return ;
        if (arr[l] > arr[l + 1]) swap(arr[l], arr[l + 1]);
        return ;
    }
    int x = l, y = r - 1;
    int z = three_point_select(arr[l], arr[r - 1], arr[(l + r) / 2]);
    do {
        while (arr[x] < z) ++x;
        while (arr[y] > z) --y;
        if (x <= y) { // 这里的判断条件是x <= y 说明最后xy相等时还会交换一次并且++x, --y;
            swap(arr[x], arr[y]);
            ++x, --y;
        }
    } while (x <= y);
    quick_sort_v2(arr, l, x);
    quick_sort_v2(arr, x, r);
    return ;
}

void quick_sort_v3(int *arr, int l, int r) {
    if (r - l <= 2) {
        if (r - l <= 1) return ;
        if (arr[l] > arr[l + 1]) swap(arr[l], arr[l + 1]);
        return ;
    }
    while (l < r) {
        int x = l, y = r - 1;
        int z = three_point_select(arr[l], arr[r - 1], arr[(l + r) / 2]);
        do {
            while (arr[x] < z) ++x;
            while (arr[y] > z) --y;
            if (x <= y) { // 这里的判断条件是x <= y 说明最后xy相等时还会交换一次并且++x, --y;
                swap(arr[x], arr[y]);
                ++x, --y;
            }
        } while (x <= y);
        quick_sort_v3(arr, l, x); // 单边递归法
        l = x;
    }
    return ;
}

#define Threshold 16

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

void __quick_sort_v4(int *arr, int l, int r) {
    while (r - l > Threshold) {
        int x = l, y = r - 1;
        int z = three_point_select(arr[l], arr[r - 1], arr[(l + r) / 2]);
        do {
            while (arr[x] < z) ++x;
            while (arr[y] > z) --y;
            if (x <= y) { // 这里的判断条件是x <= y 说明最后xy相等时还会交换一次并且++x, --y;
                swap(arr[x], arr[y]);
                ++x, --y;
            }
        } while (x <= y);
        __quick_sort_v4(arr, l, x); // 单边递归法
        l = x;
    }
    return ;
}

void quick_sort_v4(int *arr, int l, int r) {
    __quick_sort_v4(arr, l, r);
    unguarded_insert_sort(arr, l, r);
    return ;
}

int main() {
    int *arr = getRandData(BIG_DATA_N);
    TEST(quick_sort, arr, BIG_DATA_N);
    TEST(quick_sort_v1, arr, BIG_DATA_N);
    TEST(quick_sort_v2, arr, BIG_DATA_N);
    TEST(quick_sort_v3, arr, BIG_DATA_N);
    TEST(quick_sort_v4, arr, BIG_DATA_N);
    return 0;
}
