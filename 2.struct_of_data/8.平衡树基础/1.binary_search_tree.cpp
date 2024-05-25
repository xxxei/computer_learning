/*************************************************************************
	> File Name: 1.binary_search_tree.cpp
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Fri 24 May 2024 03:19:00 PM CST
 ************************************************************************/

#include <iostream>
#include <ctime>
#include <cstdio>
#include <cstdlib>
using namespace std;

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
    if (key < root->key) root->l = insert(root->l, key);
    else root->r = insert(root->r, key);
    return root;
}

Node *erase(Node *root, int key) {
    if (root == NULL) return root;
    if (key < root->key) root->l = erase(root->l, key);
    else if (key > root->key) root->r = erase(root->r, key);
    else {
        if (root->l == NULL && root->r == NULL) {
            free(root);
            return NULL;
        } else if (root->l == NULL || root->r == NULL) {
            Node *temp = root->l:
        }
    }
}

void clear(Node *root) {
    if (root == NULL) return ;
    clear(root->l);
    clear(root->r);
    free(root);
    return ;
}

int main () {
    srand(time(0));
    return 0;
}
