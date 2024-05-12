/*************************************************************************
	> File Name: string.c
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Sat 20 Apr 2024 10:22:28 AM CST
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    char str1[10] = "abc";
    printf("str1 = %s\n", str1);
//  str1 = "def";错误赋值
    strcpy(str1, "def");
    printf("str1 = %s\n", str1);
    char str2[] = "hello\0world";
    printf("strlen(str2) = %lu\n", strlen(str2));//strlen统计字符时统计到\0字符结束但不包括\0本身 ---> 5
    printf("sizeof(str2) = %lu\n", sizeof(str2));//存储字符串信息时把所有看得见看不见的字符全部存储 ---> 13
    printf("str2 = %s\n", str2); //---> hello
    str2[5] = ' ';
    printf("str2 = %s\n", str2);
    char str3[] = "abcdef", str4[] = "abc";
    printf("strcmp(str3, str4) = %d\n", strcmp(str3, str4)); //字典序比较（一个一个字符的比较）---> d - \0 = 100

    int arr[10];
    for (int i = 0; i < 10; i++) {
        arr[i] = rand() % 100;
    }
    for (int i = 0; i < 10; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
    memset(arr, 0, sizeof(arr));//40, sizeof(int) * 10;  数组所占字节数
    for (int i = 0; i < 10; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
    return 0;
}
