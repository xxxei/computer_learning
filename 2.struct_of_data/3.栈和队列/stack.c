/*************************************************************************
	> File Name: stack.c
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Thu 02 May 2024 10:31:42 AM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Stack {
    int *data;
    int size, top;
} Stack;

Stack *initStack(int n) {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->data = (int *)malloc(sizeof(int) * n);
    s->size = n;
    s->top = -1;
    return s;
}

int empty(Stack *s) {
    return s->top == -1;
}

int top(Stack *s) {
    if (empty(s)) return 0;
    return s->data[s->top];
}

int push(Stack *s, int val) {
    if (s->top + 1 == s->size) return 0;
    s->top += 1;
    s->data[s->top] = val;
    return 1;
}

int pop(Stack *s) {
    if (empty(s)) return 0;
    s->top -= 1;
    return 1;
}

void clearStack(Stack *s) {
    if (s == NULL) return ;
    free(s->data);
    free(s);
    return ;
}

void outputStack(Stack *s) {
    printf("Stack : ");
    for (int i = s->top; i >= 0; --i ) {
        printf("%4d ", s->data[i]);
    }
    printf("\n");
    return ; 
}

int main() {
    srand(time(0));
    #define MAX_OP 10
    Stack *s = initStack(5);
    for (int i = 0; i < MAX_OP; i++) {
        int op = rand() % 3, val = rand() % 100;
        switch (op) {
            case 0:
                printf("pop stack, item = %d\n", top(s));
                pop(s);
                break;
            case 1:
            case 2:
                printf("push stack, item = %d\n", val);
                push(s, val);
                break;
        }
        outputStack(s);
    }
    return 0;
}
