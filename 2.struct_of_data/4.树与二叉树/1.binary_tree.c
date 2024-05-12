/*************************************************************************
	> File Name: 1.binary_tree.c
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Thu 02 May 2024 02:39:46 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int key;
    struct Node *l, *r;
} Node;

Node *getNewNode(int key) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->l = p->r = NULL;
    return p;
}

Node *insert(Node *root, int key) {
    if (root == NULL) return getNewNode(key);
    if (rand() % 2) root->l = insert(root->l, key);
    else root->r = insert(root->r, key);
    return root;
}

#define MAX_NODE 10
Node *queue[MAX_NODE + 5];
int head, tail;

void bfs(Node *root) {
    head = tail = 0;
    queue[tail++] = root;
    while (head < tail) {
        Node *node = queue[head];
        printf("\nnode : %d\n", node->key);
        if (node->l) {
            queue[tail++] = node->l;
            printf("\t%d->%d (left)\n", node->key, node->l->key);
        }
        if (node->r) {
            queue[tail++] = node->r;
            printf("\t%d->%d (right)\n", node->key, node->r->key);
        }
        head++;
    }
    return ;
}

int tot = 0;
void dfs(Node *root) {
    if (root == NULL) return ;
    int start, end;
    tot += 1;
    start = tot;
    if (root->l) dfs(root->l);
    if (root->r) dfs(root->r);
    tot += 1;
    end = tot;
    printf("%d : [%d, %d]\n", root->key, start, end);
    return ;
}

int main() {
    srand(time(0));
    Node *root = NULL;
    for (int i = 0; i < MAX_NODE; i++) {
        root = insert(root, rand() % 100);
    }
    bfs(root); // 广度
    dfs(root); // 深度
    return 0;
}
