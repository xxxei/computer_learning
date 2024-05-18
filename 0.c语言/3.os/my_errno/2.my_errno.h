/*************************************************************************
	> File Name: 2.my_errono.h
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Thu 16 May 2024 01:59:14 PM CST
 ************************************************************************/

#ifndef _2.MY_ERRONO_H
#define _2.MY_ERRONO_H

#define MY_SUCCESS 0
#define MY_NO_ACCESS 1
#define MY_HEART_LOCKED 2

extern int errnum;

const char *my_strerror(int errnum);
void my_perror(const char *prefix);
int open_heart(const char *name);
#endif
