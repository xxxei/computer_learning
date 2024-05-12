/*************************************************************************
	> File Name: file_operator.c
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Sun 28 Apr 2024 03:49:35 PM CST
 ************************************************************************/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

const char *file_name = "data3.txt";
#define MAX_N 10000
int arr[MAX_N + 5], n = 0; 

void output_arr(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return ;
}

void output_to_file(int *arr, int n) { // 向文件追加随机数组
    FILE *fp = fopen(file_name, "a");
    for (int i = 0; i < n; i++) {
        fprintf(fp, "%d ", arr[i]);
    }
    fclose(fp);
    return ;
}

int read_from_file(int *arr) {
    int i = 0;
    FILE *fp = fopen(file_name, "r");
    if (fp == NULL) return 0;
    while (fscanf(fp, "%d", arr + i) != EOF) {
        i += 1;
    }
    fclose(fp);
    return i;
}

void clear_file() {
    FILE *fp = fopen(file_name, "w");
    fclose(fp);
    return ;
}

// test case

int output_test() {
    srand(time(0));
    for (n = 0; n < 10; n++) {
        arr[n] = rand() % 100;
    }
    output_arr(arr, n);
    output_to_file(arr, n); // 封装函数：减少记忆负担
    return 0;
}

int read_test() {
    n = read_from_file(arr); // 返回读入数据数
    output_arr(arr, n);
    printf("total read %d numbers\n", n);
    return 0;
}

int main() {
    clear_file();
    return 0;
}
