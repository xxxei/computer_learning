/*************************************************************************
	> File Name: queue_vector.c
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Thu 02 May 2024 08:57:39 AM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct vector {
    int *data;
    int size;
} vector;

vector *initvector(int n) {
    vector *v = (vector *)malloc(sizeof(vector));
    v->size = n;
    v->data = (int *)malloc(sizeof(int) * n);
    return v;
}

void clearvector(vector *v) {
    if (v == NULL) return;
    free(v->data);
    free(v);
    return ;
}

int vectorseek(vector *v, int pos) {
    if (pos < 0 || pos >= v->size) return -1;
    return v->data[pos];
}

int insertvector(vector *v, int pos, int val) {
    if (pos < 0 || pos >= v->size) return 0;
    v->data[pos] = val;
    return 1;
}

typedef struct queue {
    vector *data;
    int size, head, tail, count;
} queue;

queue *initqueue(int n) {
    queue *q = (queue *)malloc(sizeof(queue));
    q->data = initvector(n);
    q->size = n;
    q->head = q->tail = q->count = 0;
    return q;
}

int empty(queue *q) {
    return q->count == 0;
}

int front(queue *q) {
    return vectorseek(q->data, q->head);
}

int push(queue *q, int val) {
    if (q->count == q->size) return 0;
    insertvector(q->data, q->tail, val);
    q->tail = (q->tail + 1) % q->size;
    q->count += 1;
    return 1;
}

int pop(queue *q) {
    if (empty(q)) return 0;
    q->head = (q->head + 1) % q->size;
    q->count -= 1;
    return 1;
}

void outputqueue(queue *q) {
    printf("queue : ");
    for (int i = 0; i < q->count; i++) {
        printf("%4d", vectorseek(q->data, (q->head + i) % q->size));
    }
    printf("\n");
    return ;
}

void clearqueue(queue *q) {
    if (q == NULL) return ;
    clearvector(q->data);
    free(q);
    return ;
}


int main() {
    srand(time(0));
    #define MAX_OP 10
    queue *q = initqueue(5);
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
        outputqueue(q);
    }
    clearqueue(q);
    return 0;
}
