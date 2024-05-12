/*************************************************************************
	> File Name: 5.random_data.c
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Thu 02 May 2024 08:33:20 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    printf("26\n");
    for (int i = 0; i < 26; i++) {
        printf("%c %d\n", 'a' + i, rand() % 100000);
    }
    return 0;
}
