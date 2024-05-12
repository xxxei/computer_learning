/*************************************************************************
	> File Name: 2.thread_binary_tree.c
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Thu 02 May 2024 03:39:30 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int key, ltag, rtag; // 1 : thread, 0 : edge 
    struct Node *l, *r;
} Node;

Node *getNewNode(int key) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->ltag = p->rtag = 0;
    p->l = p->r = NULL;
    return p;
}

Node *insert(Node *root, int key) {
    if (root == NULL) return getNewNode(key);
    if (rand() % 2) root->l = insert(root->l, key);
    else root->r = insert(root->r, key);
    return root;
}

void clear(Node *root) {
    if (root == NULL) return ;
    if (root->ltag == 0) clear(root->l);
    if (root->rtag == 0) clear(root->r);
    free(root);
    return ;
}

#define MAX_NODE 10

void pre_order(Node *root) {
    if (root == NULL) return ;
    printf("%d ", root->key);
    if (root->ltag == 0) pre_order(root->l);
    if (root->rtag == 0) pre_order(root->r);
    return ;
}

void in_order(Node *root) {
    if (root == NULL) return ;
    if (root->ltag == 0) in_order(root->l);
    printf("%d ", root->key);
    if (root->rtag == 0) in_order(root->r);
    return ;
}

void post_order(Node *root) {
    if (root == NULL) return ;
    if (root->ltag == 0) post_order(root->l);
    if (root->rtag == 0) post_order(root->r);
    printf("%d ", root->key);
    return ;
}

Node *pre_node = NULL;
Node *inorder_root = NULL;
void __build_inorder_thread(Node *root) {
    if (root == NULL) return ;
    if (root->ltag == 0) __build_inorder_thread(root->l);
    if (inorder_root == NULL) inorder_root = root;
    if (root->l == NULL) {
        root->l = pre_node;
        root->ltag = 1;
    }
    if (pre_node && pre_node->r == NULL) {
        pre_node->r = root;
        pre_node->rtag = 1;
    }
    pre_node = root;
    if (root->rtag == 0) __build_inorder_thread(root->r);
    return ;
}

void build_inorder_thread(Node *root) {
    __build_inorder_thread(root);
    pre_node->r = NULL;
    pre_node->rtag = 1;
    return ;
}

Node *getNext(Node *root) {
    if (root->rtag == 1) return root->r;  
    root = root->r;
    while (root->ltag == 0 && root->l) {
        root = root->l;
    }
    return root;
}

int main() {
    srand(time(0));
    Node *root = NULL;
    for (int i = 0; i < MAX_NODE; i++) {
        root = insert(root, rand() % 100);
    }
    pre_node = inorder_root = NULL;
    build_inorder_thread(root);
    pre_order(root); printf("\n");
    in_order(root); printf("\n");
    post_order(root); printf("\n");

    // like linklist
    Node *node = inorder_root;
    while (node) {
        printf("%d ", node->key);
        node = getNext(node);
    }
    printf("\n");
    clear(root);
    return 0;
}
