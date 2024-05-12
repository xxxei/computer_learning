/*************************************************************************
	> File Name: priority_queue.c
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Mon 06 May 2024 08:29:03 AM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define cmp >
#define FATHER(i) ((i) / 2)
#define LEFT(i)   ((i) * 2) 
#define RIGHT(i)  ((i) * 2 + 1)
#define swap(a, b) { \
    __typeof(a) __c = (a); \
    (a) = (b); \
    (b) = __c; \
}

typedef struct PriorityQueue {
    int *__data, *data;
    int size, n;
} PriorityQueue;

PriorityQueue *initPQ(int size) {
    PriorityQueue *p = (PriorityQueue *)malloc(sizeof(PriorityQueue));
    p->__data = (int *)malloc(sizeof(int) * size);
    p->data = p->__data - 1; // data指针做了偏移
    p->size = size;
    p->n = 0;
    return p;
}

int empty(PriorityQueue *p) {
    return p->n == 0;
}

int full(PriorityQueue *p) {
    return p->n == p->size;
}

int top(PriorityQueue *p) {
    return p->data[1];
}

void up_update(int *data, int i) {
    while (i cmp 1 && data[i] > data[FATHER(i)]) {
        swap(data[i], data[FATHER(i)]);
        i = FATHER(i);
    }
    return ;
}

void down_update(int *data, int i, int n) {
    int ind, l, r;
    while (LEFT(i) <= n) {
        ind = i, l = LEFT(i), r = RIGHT(i);
        if (data[l] cmp data[ind]) ind = l;
        if (r <= n && data[r] cmp data[ind]) ind = r;
        if (ind == i) break;
        swap(data[i], data[ind]);
        i = ind;
    }
    return ;
}

int push(PriorityQueue *p, int x) {
    if (full(p)) return 0;
    p->n += 1;
    p->data[p->n] = x;
    up_update(p->data, p->n);
    return 1;
}

int pop(PriorityQueue *p) {
    if (empty(p)) return 0;
    p->data[1] = p->data[p->n];
    p->n -= 1;
    down_update(p->data, 1, p->n);
    return 1;
}

void clear(PriorityQueue *p) {
    if (p ==NULL) return ;
    free(p->__data);
    free(p);
    return ;
}

void output(PriorityQueue *p) {
    printf("PQ(%d) : ", p->n);
    for (int i = 1; i <= p->n; i++) {
        printf("%d ", p->data[i]);
    }
    printf("\n");
    return ;
}

int main() {
    int op, x;
    #define MAX_OP 100
    PriorityQueue *p = initPQ(MAX_OP);
    while (~scanf("%d", &op)) {
        if (op == 1) {
            scanf("%d", &x);
            printf("insert %d to priority_queue : \n", x);
            push(p, x);
            output(p);
        } else {
            printf("pop : %d\n", top(p));
            pop(p);
            output(p);
        }
    }
    clear(p);
    return 0;
}
