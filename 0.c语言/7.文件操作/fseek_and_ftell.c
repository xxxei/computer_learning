/*************************************************************************
	> File Name: fseek_and_ftell.c
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Wed 01 May 2024 07:30:44 PM CST
 ************************************************************************/

// SEEK_SET 以文件开头位置为中心
// SEEK_CUR 以文件当前位置为中心
// SEEK_END 以文件结尾位置为中心


#include<stdio.h>

int main() {
    FILE *fp = fopen("data5.txt", "w");
    printf("ftell(fp) = %ld\n", ftell(fp)); // 0
    fprintf(fp, "0123456789");
    printf("after print 0123456789 ftell(fp) = %ld\n", ftell(fp)); // 10
    fseek(fp, 2, SEEK_SET);
    printf("afater fseek(2) ftell(fp) = %ld\n", ftell(fp)); // 2
    fprintf(fp, "abc");
    printf("after print abc ftell(fp) = %ld\n", ftell(fp)); // 5
    return 0;
}
