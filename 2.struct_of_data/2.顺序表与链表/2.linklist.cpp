/*************************************************************************
	> File Name: 2.linklist.cpp
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Thu 23 May 2024 10:59:41 AM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *getNewNode(int val) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = val;
    p->next = NULL;
    return p;
}

Node *insert(Node *head, int pos, int val) {
    Node new_node, *p = &new_node, *node = getNewNode(val);
    new_node.next = head; // 虚拟头节点
    for (int i = 0; i < pos; i++) p = p->next;
    node->next = p->next;
    p->next = node;
    return new_node.next;
}

void clear(Node *head) {
    if (head == NULL) return ;
    for (Node *p = head, *q; p; p = q) {
        q = p->next;
        free(p);
    }
    return ;
}

void output_linklist(Node *head) {
    int n = 0;
    for (Node *p = head; p; p = p->next) n += 1;
    for (int i = 0; i < n; i++) {
        printf("%3d", i);
        printf("  ");
    }
    cout << endl;
    for (Node *p = head; p; p = p->next) {
        printf("%3d", p->data);
        printf("->");
    }
    cout << endl << endl << endl;
    return ;
}

void find(Node *head, int val) {
    Node *p = head;
    while (p) {
        if (p->data == val) return 1;
        p = p->next;
    }
    return 0;
}

int main() {
    srand(time(0));
    #define MAX_OP 20
    Node *head = NULL;
    for (int i = 0; i < MAX_OP; i++) {
        int pos = rand() % (i + 1), val = rand() % 100;
        cout << "insert " << val << " at " << pos << " to linklist" << endl;
        head = insert(head, pos, val);
        output_linklist(head);
    }
    clear(head);
    return 0;
}
