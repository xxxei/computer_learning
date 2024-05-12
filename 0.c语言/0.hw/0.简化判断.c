/*************************************************************************
	> File Name: test.c
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Tue 16 Apr 2024 09:29:09 AM CST
 ************************************************************************/

#include<stdio.h>

int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    if(a % b) printf("NO\n");
    else printf("YES\n");
    
    printf("%s\n", a % b == 0 ? "YES" : "NO");

    return 0;
}
