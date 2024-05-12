/*************************************************************************
	> File Name: 1.string.c
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Fri 12 Apr 2024 06:58:52 PM CST
 ************************************************************************/

#include<stdio.h>
int main(){
    char s[100] = "hello wolrd";
    printf("%s\n",s);
    scanf("%s",s);//scanf以空格截断
    printf("scanf s: %s\n",s);
    getchar();//吞掉空格
    scanf("%[a-z ]",s);//允许读取a到z的字母以及空格
    printf("%%[a-z] : %s\n",s);
    return 0;
}
