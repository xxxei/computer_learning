/*************************************************************************
	> File Name: funny_linklist1.c
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Thu 25 Apr 2024 03:12:19 PM CST
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>

#define start(addr, T, d) ((T *)(((void *)addr) - offset(T, d)))
#define offset(T, d) (size_t)(&(((T *)(0))->d))

enum Datatype {
    a_type,
    b_type,
    c_type,
    Max_type
};
typedef struct Link {
    enum Datatype type;
    struct Link *next;
} Link;

struct A {
    int x, y;
    Link l;
};

Link *getDataA() {
    struct A *a = (struct A *)malloc(sizeof(struct A));
    a->x = 3, a->y = 4;
    a->l.next = NULL;
    a->l.type = a_type;
    return &(a->l);
}

void output_a(Link *p) {
    struct A *a = start(p, struct A, l);
    printf("struct A : x = %d, y = %d\n", a->x, a->y);
    return ;
}

struct B {
    int a;
    Link l;
    double b;
};

Link *getDataB() {
    struct B *b = (struct B *)malloc(sizeof(struct B));
    b->a = 100, b->b = 45.3;
    b->l.next = NULL;
    b->l.type = b_type;
    return &(b->l);
}

void output_b(Link *p) {
    struct B *b = start(p, struct B, l);
    printf("struct B : a = %d, b = %f\n", b->a, b->b);
    return ;
}

struct C {
    char c;
    Link l;
    const char *s;
    int t;
};

Link *getDataC() {
    struct C *c = (struct C *)malloc(sizeof(struct C));
    c->c = 'G', c->s = "struct C", c->t = 99;
    c->l.next = NULL;
    c->l.type = c_type;
    return &(c->l);
}

void output_c(Link *p) {
    struct C *c = start(p, struct C, l);
    printf("struct C : c = %c, s = %s, t = %d\n", c->c, c->s, c->t);
    return ;
}

Link *(*getData[Max_type])() = {
    getDataA, getDataB, getDataC
};

void (*output[Max_type])(Link *) = {
    output_a, output_b, output_c
};

int main() {
    #define MAX_OP 10
    Link head, *p = &head;
    for (int i = 0; i < MAX_OP; i++) {
        p->next = getData[rand() % Max_type]();
        p = p->next;
    }
    for (p = head.next; p; p = p->next) {
        output[p->type](p);
    }
    return 0;
}
