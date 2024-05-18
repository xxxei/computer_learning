/*************************************************************************
	> File Name: 3.my_errno.c
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Thu 16 May 2024 02:06:06 PM CST
 ************************************************************************/

#include <stdio.h>
#include "2.my_errno.h"

int errnum;

int open_heart(const char *name) {
    if (name == NULL) {
        errnum = MY_HEART_LOCKED;
        return -1;
    } else if (name[0] == '/') {
        errnum = MY_NO_ACCESS;
        return -1;
    } else {
        errnum = MY_SUCCESS;
        return 0;
    }
}

const char *my_strerror(int errnum) {
    switch (errnum) {
        case MY_SUCCESS: return "Heart Opened successfully";
        case MY_NO_ACCESS: return "no access to her heart";
        case MY_HEART_LOCKED: return "Heart is locked";
        default: return "Unknown feeling";
    }
}

void my_perror(const char *prefix) {
    if (prefix != NULL) {
        fprintf(stderr, "%s : %s\n", prefix, my_strerror(errnum));
    } else {
        fprintf(stderr, "%s\n", my_strerror(errnum));
    }
}
