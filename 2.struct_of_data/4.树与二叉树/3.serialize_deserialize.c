/*************************************************************************
	> File Name: serialize_deserialize.c
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Thu 02 May 2024 05:18:33 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define KEY(n) (n ? n->key : -1)
 // n 为NULL则返回 -1
#define MAX_NODE 10
 
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

Node *getRandomBinaryTree(int n) {
    Node *root = NULL;
    for (int i = 0; i < n; i++) {
        root = insert(root,rand() % 100);
    }
    return root;
}

void clear(Node *root) {
    if (root == NULL) return ;
    clear(root->l);
    clear(root->r);
    free(root);
    return ;
}

char buff[1000];
int len = 0;

void __serialize(Node *root) {
    if (root == NULL) return ;
    len += sprintf(buff + len, "%d", root->key);
    if (root->l == NULL && root->r == NULL) return;
    len += sprintf(buff + len, "(");
    __serialize(root->l);
    if (root->r) {
        len += sprintf(buff + len, ",");
        __serialize(root->r);
    }
    len += sprintf(buff + len, ")");
    return ;
}

void serialize(Node *root) {
    memset(buff, 0, sizeof(buff));
    len = 0;
    __serialize(root);
    return ;
}

void print(Node *node) {
    printf("%d(%d, %d)\n", KEY(node),
        KEY(node->l),
        KEY(node->r)
    );
    return ;
}

void output(Node *root) {
    if (root == NULL) return ;
    print(root);
    output(root->l);
    output(root->r);
    return ;
}

Node *deserialize(char *buff, int n) {
    Node **s = (Node **)malloc(sizeof(Node *) * MAX_NODE);
    int top = -1, flag = 0, scode = 0;
    Node *p = NULL, *root = NULL;
    for (int i = 0; buff[i]; i++) {
        switch (scode) {
            case 0: {
                if (buff[i] >= '0' && buff[i] <= '9') scode = 1;
                else if (buff[i] == '(') scode = 2;
                else if (buff[i] == ',') scode = 3;
                else scode = 4;
                i -= 1;
            } break;
            case 1: {
                int num = 0;
                while (buff[i] <= '9' && buff[i] >= '0') {
                    num = num * 10 + (buff[i] - '0');
                    i += 1;
                }
                p = getNewNode(num);
                if (top >= 0 && flag == 0) s[top]->l = p;
                if (top >= 0 && flag == 1) s[top]->r = p;
                i -= 1;
                scode = 0;
            } break;
            case 2: {
                s[++top] = p;
                flag = 0;
                scode = 0;
            } break;
            case 3: {flag = 1; scode = 0;} break;
            case 4: {
                root = s[top];
                top -= 1;
                scode = 0;
            } break;
        }
    }
    return root;
}

int main() {
    srand(time(0));
    Node *root = getRandomBinaryTree(MAX_NODE);
    serialize(root);
    output(root);
    printf("Buff : %s\n", buff);
    Node *new_root = deserialize(buff, len);
    output(new_root);
    return 0;
}
