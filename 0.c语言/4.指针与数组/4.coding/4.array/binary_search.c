/*************************************************************************
	> File Name: binary_search.c
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Thu 18 Apr 2024 03:54:23 PM CST
 ************************************************************************/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
    srand(time(0)); //设置随机种子
   // printf("rand() = %d\n", rand()); //随机生成数
    int arr[10] = {0};
    for (int i = 1; i < 10; i++) {
        arr[i] = arr[i - 1] + (rand() % 10);
    }
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    int x;
    while (scanf("%d", &x) != EOF) {
        int cnt1 = 0, cnt2 = 0, flag1 = 0, flag2 = 0;
        for (int i = 0; i < 10; i++) {
            cnt1 += 1;
            if (arr[i] != x) continue;
            flag1 = 1;
            break;
        }

        int l = 0, r = 9, mid;
        while (l <= r) {
            cnt2 += 1;
            mid = (l + r) >> 1;
            if (arr[mid] == x) {
                flag2 = 1;
                break;
            }
            if (arr[mid] > x) r = mid - 1;
            else l = mid + 1;
        }

        if (flag1 == 1 || flag2 == 1) {
            printf("OK, find count = %d %d\n", cnt1, cnt2);
        } else {
            printf("not found, find count = %d %d\n", cnt1, cnt2);
        }
    }
    return 0;
}
