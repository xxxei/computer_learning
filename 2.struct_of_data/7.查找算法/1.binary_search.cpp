/*************************************************************************
	> File Name: 1.binary_search.cpp
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Fri 24 May 2024 08:58:44 AM CST
 ************************************************************************/

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
using namespace std;

void output(int *arr, int n, int ind = -1) {
    int len = 0;
    for (int i = 0; i < n; i++) {
        len += printf("%4d", i);
    }
    cout << endl;
    for (int i = 0; i < len; i++) printf("-");
    cout << endl;
    for (int i = 0; i < n; i++) {
        if (i == ind) printf("\033[1;32m");
        printf("%4d", arr[i]);
        if (i == ind) printf("\033[0m");
    }
    cout << endl;
    return ;
}

int binary_search(int *arr, int n, int x) {
    int min = 0, max = n - 1, mid;
    while (min <= max) {
        mid = (min + max) / 2;
        if (arr[mid] == x) return mid;
        if (arr[mid] < x) min = mid + 1;
        else max = mid - 1;
    }
    return -1;
}

void test_binary_search(int n) {
    int *arr = (int *)malloc(sizeof(int) * n);
    arr[0] = rand() % 10;
    for (int i = 1; i < n; i++) arr[i] = arr[i - 1] + rand() % 10;
    output(arr, n);
    int x;
    while (~scanf("%d", &x)) {
        if (x == -1) break;
        int ind = binary_search(arr, n ,x);
        output(arr, n, ind);
    }
    return ;
}

int main() {
    srand(time(0));
    #define MAX_N 10
    test_binary_search(MAX_N);
    return 0;
}
