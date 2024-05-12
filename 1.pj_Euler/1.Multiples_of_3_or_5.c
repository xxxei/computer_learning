/*************************************************************************
	> File Name: Multiples_of_3_or_5.c
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Sun 28 Apr 2024 05:00:11 PM CST
 ************************************************************************/

#include<stdio.h>

#ifdef is_val
int is_val(int x) {
    return (x % 3 == 0 || x % 5 == 0);
}

int main() {
    int sum = 0;
    for (int i = 0; i < 1000; i++) {
        if (is_val(i)) sum += i;
    }
    printf("%d\n", sum);
    return 0;
}
#endif
// O(n)

int main() {
    int sum3 = (3 + 999) * (999 / 3) / 2;
    int sum5 = (5 + 995) * (999 / 5) / 2;
    int sum15 = (15 + 999 / 15 * 15) * (999 / 15) / 2;
    printf("%d\n", sum3 + sum5 - sum15);
}
// O(1)常数级
