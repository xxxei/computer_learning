/*************************************************************************
	> File Name: 0.sort_test.h
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Fri 17 May 2024 11:09:36 AM CST
 ************************************************************************/

#ifndef SORT_TEST_H
#define SORT_TEST_H

#include <cstring>
#include <cstdlib>
#include <ctime>

#define SMALL_DATA_N 5000
#define BIG_DATA_N 1000000

__attribute__((constructor))
void __init_Rand__() {
    srand(time(0));
}

bool check(int *arr, int l, int r) {
    for (int i = l + 1; i < r; i++) {
        if (arr[i] < arr[i - 1]) return false;
    }
    return true;
}

int *getRandData (int n) {
    int *arr = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) arr[i] = rand() % 10000;
    return arr;
}

#define swap(a, b) { \
    __typeof(a) __c = a; \
    a = b, b = __c; \
}

#define TEST(func, arr, n) { \
    cout << "Test " << #func << " : "; \
    int *temp = (int *)malloc(sizeof(int) * n); \
    memcpy(temp, arr, sizeof(int) * n); \
    long long b = clock(); \
    func(temp, 0, n); \
    long long e = clock(); \
    if (check(temp, 0, n)) { \
        cout << "OK "; \
    } else { \
        cout << "Failed "; \
    } \
    cout << n << "items "<< (e - b) * 1000 / CLOCKS_PER_SEC << " ms" << endl; \
    free(temp); \
}

#endif
