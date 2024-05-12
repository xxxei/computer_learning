/*************************************************************************
	> File Name: queue_linklist.c
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Thu 02 May 2024 09:41:20 AM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h> 
#include <time.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct LinkList {
    Node head, *tail;
} LinkList;

Node *getNewNode(int val) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = val;
    p->next = NULL;
    return p;
}

LinkList *initLinkList() {
    LinkList *l = (LinkList *)malloc(sizeof(LinkList));
    l->head.next = NULL;
    l->tail = &(l->head);
    return l;
}

void clearLinkList(LinkList *l) {
    Node *p = l->head.next, *q;
    while (p) {
        q = p->next;
        free(p);
        p = q;
    }
    free(l);
    return ;
}

typedef struct Queue {
    LinkList *l;
    int count;
} Queue;

Queue *initQueue() {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->l = initLinkList();
    q->count = 0;
    return q;
}

int emptyList(LinkList *l) {
    return l->head.next == NULL;
}

int frontList(LinkList *l) {
    if (emptyList(l)) return 0;
    return l->head.next->data;
}

int insertTail(LinkList *l, int val) {
    Node *node = getNewNode(val);
    l->tail->next = node;
    l->tail = node;
    return 1;
}

int eraseHead(LinkList *l) {
    if (emptyList(l)) return 0;
    Node *p = l->head.next;
    l->head.next = l->head.next->next;
    if (p == l->tail) l->tail = &(l->head);
    free(p);
    return 1;
}

int empty(Queue *q) {
    return q->count == 0;
}

int front(Queue *q) {
    if (empty(q)) return 0;
    return frontList(q->l);
}

int push(Queue *q, int val) {
    insertTail(q->l, val);
    q->count += 1;
    return 1;
}

int pop(Queue *q) {
    eraseHead(q->l);
    q->count -= 1;
    return 1;
}

void outputQueue(Queue *q) {
    printf("queue : ");
    Node *p = q->l->head.next;
    for (int i = 0; i < q->count; i++, p = p->next) {
        printf("%4d", p->data);
    }
    printf("\n");
    return ;
}

void clearQueue(Queue *q) {
    if (q == NULL)return ;
    clearLinkList(q->l);
    free(q);
    return ;
}

int main() {
    srand(time(0));
    #define MAX_OP 10
    Queue *q = initQueue(5);
    for (int i = 0; i < MAX_OP; i++) {
        int op = rand() % 5, val = rand() % 100;
        switch (op) {
            case 0:
                printf("front of queue : %d\n", front(q));
                printf("pop one\n");
                pop(q);
                break;
            case 1:
            case 2:
            case 3:
            case 4:
                printf("push %d to queue\n", val);
                if (push(q, val)) break;
                else {
                    printf("queue is full!\n");
                    break;
            }
        }
        outputQueue(q);
    }
    clearQueue(q);
    return 0;
}
