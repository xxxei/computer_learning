/*************************************************************************
	> File Name: struct.c
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Wed 24 Apr 2024 02:55:34 PM CST
 ************************************************************************/

#include<stdio.h>

typedef struct person {
    char name[20];
    int age;
    char gender;
    float height;
} person;

void output(person *p) {  // 间接访问结构体
    printf("(%s, %d, %c, %f)\n",
        p->name,
        p->age,
        p->gender,
        p->height
    );
    return ;
}

void set_buff(char *buff, void *head, void *begin, void *end, char ch) {
    while(begin != end) {
        buff[begin - head] = ch;
        begin += 1;
    }
    return ;
}

void output_person() {
    int n = sizeof(person), len = 0;
    char buff[n];
    for (int i = 0; i < n; i++) buff[i] = '.';
    for (int i = 0; i < n; i++) {
        len += printf("%3d", i);
    }
    printf("\n");
    for (int i = 0; i < len; i++) printf("-");
    printf("\n");
    person hug;
    set_buff(buff, hug.name, hug.name, 20 + (void *)hug.name, 'n');
    set_buff(buff, hug.name, &hug.age, 4 + (void *)&hug.age, 'a');
    set_buff(buff, hug.name, &hug.gender, 1 + (void *)&hug.gender, 'g');
    set_buff(buff, hug.name, &hug.height, 4 + (void *)&hug.height, 'h');
    for (int i = 0; i < n; i ++) {
        printf("%3c", buff[i]);
    }
    printf("\n");
}
int main() {
    person a = {"twei", 22, 'M', 1.16};
    printf("(%s, %d, %c, %f)\n", // 直接访问结构体
        a.name,
        a.age,
        a.gender,
        a.height
    );
    output(&a);
    output_person();
    return 0;
}
