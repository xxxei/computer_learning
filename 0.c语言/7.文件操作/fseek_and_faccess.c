/*************************************************************************
	> File Name: fseek_and_faccess.c
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Wed 01 May 2024 08:16:45 PM CST
 ************************************************************************/

#include<stdio.h>

// 01abc56789
void r_plus_access() {
    FILE *fp = fopen("data5.txt", "r+");
    fseek(fp, 5, SEEK_SET);
    int n;
    fscanf(fp, "%d", &n);
    printf("r+ : n = %d\n", n); // 56789
    fseek(fp, 6, SEEK_SET);
    fprintf(fp, "876");
    fclose(fp);
    return ;
}

void w_plus_access() {
    FILE *fp = fopen("data8.txt", "w+");
    fprintf(fp, "hello world123456abc7890");
    fseek(fp, -4, SEEK_END);
    int n;
    fscanf(fp, "%d", &n);
    printf("w+ : n = %d\n", n); // 7890
    fseek(fp, 12, SEEK_SET);
    fprintf(fp, "xyz");
    fclose(fp);
    return ;
}

void a_plus_access(){ //  在追加扩展模式下没办法去影响写入的行为(都是向文件末尾写入)， 但是依然可以通过控制文件指针位置影响读入行为
    FILE *fp = fopen("data7.txt", "a+");
    fprintf(fp, "1234567890");
    fseek(fp, 0, SEEK_SET);
    fprintf(fp, "0987654321");
    fclose(fp);
    return ;
}

int main() {
    r_plus_access();
    w_plus_access();
    a_plus_access();
    return 0;
}
