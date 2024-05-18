/*************************************************************************
	> File Name: 1.my_errno_test.c
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Thu 16 May 2024 02:17:34 PM CST
 ************************************************************************/

#include <stdio.h>
#include "2.my_errno.h"

int main() {
    if (open_heart(NULL) < 0) {
        my_perror("open_heart NULL");
    }
    if (open_heart("/xxxy") < 0) {
        fprintf(stderr, "open_heart /xxxy : %s\n", my_strerror(errnum));
    }
    if (open_heart("Lucy") < 0) {
        my_perror("open_heart Lucy");
    }

    return 0;
}
