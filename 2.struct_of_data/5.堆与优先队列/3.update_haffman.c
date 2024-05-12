/*************************************************************************
	> File Name: 4.haffman.c
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Thu 02 May 2024 08:31:51 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define cmp <
#define FATHER(i) ((i) / 2)
#define LEFT(i) ((i) * 2)
#define RIGHT(i) ((i) * 2 + 1)

#define swapHeap(a, b) { \
    __typeof(a) __c = (a); \
    (a) = (b), (b) = __c; \
}

typedef struct Node {
    char ch;
    int freq;
    struct Node *l, *r;
} Node;

typedef struct Heap {
    Node **__data, **data;
    int n, size;
} Heap;

Heap *getNewHeap(int size) {
    Heap *h = (Heap *)malloc(sizeof(Heap));
    h->__data = (Node **)malloc(sizeof(Node *));
    h->data = h->__data - 1;
    h->n = 0;
    h->size = size;
    return h;
}

int fullHeap(Heap *h) {
    return h->n == h->size;
}

int emptyHeap(Heap *h) {
    return h->n == 0;
}

Node *top(Heap *h) {
    if (emptyHeap(h)) return NULL;
    return h->data[1];
}

void up_update(Heap *h, int i) {
    while (i > 1 && h->data[i]->freq cmp h->data[FATHER(i)]->freq) {
        swapHeap(h->data[i], h->data[FATHER(i)]);
        i = FATHER(i);
    }
    return ;
}

void down_update(Heap *h, int i, int n) {
    while (LEFT(i) <= n) {
        int ind = i, l = LEFT(i), r = RIGHT(i);
        if (h->data[l]->freq cmp h->data[ind]->freq) ind = l;
        if (r <= n && h->data[r]->freq cmp h->data[ind]->freq) ind = r;
        if (ind == i) break;
        swapHeap(h->data[i], h->data[ind]);
        i = ind;
    }
    return ;
}

int pushHeap(Heap *h, Node *n) {
    if (fullHeap(h)) return 0;
    h->n += 1;
    h->data[h->n] = n;
    up_update(h, h->n);
    return 1;
}

int popHeap(Heap *h) { // 获取堆顶元素
    if (emptyHeap(h)) return 0;
    h->data[1] = h->data[h->n];
    h->n -= 1;
    down_update(h, 1, h->n);
    return 1;
}

void clearHeap(Heap *h) {
    if (h == NULL) return ;
    free(h->__data);
    free(h);
    return ;
}

Node *getNewNode(int freq, char ch) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->ch = ch;
    p->freq = freq;
    p->l = p->r = NULL;
    return p;
}

void clear(Node *root) {
    if (root == NULL) return ;
    clear(root->l);
    clear(root->r);
    free(root);
    return ;
}

void swap_node(Node **node_arr, int i, int j) {
    Node *temp = node_arr[i];
    node_arr[i] = node_arr[j];
    node_arr[j] = temp;
    return ;
}

int find_min_node(Node **node_arr, int n) {
    int ind = 0;
    for (int j = 1; j < n; j++) {
        if (node_arr[ind]->freq > node_arr[j]->freq) ind = j;
    }
    return ind;
}

Node *buildHaffmanTree(Node **node_arr, int n) {
    Heap *h = getNewHeap(n);
    for (int i = 0; i < n; i++) pushHeap(h, node_arr[i]);
    for (int i = 1; i < n; i++) {
        Node *node1 = top(h);
        popHeap(h);
        Node *node2 = top(h);
        popHeap(h);
        Node *node3 = getNewNode(node1->freq + node2->freq, 0);
        node3->l = node1;
        node3->r = node2;
        pushHeap(h,node3);
    }
    Node *ret = top(h);
    clearHeap(h);
    return ret;
}

#define MAX_CHAR_NUM 128
char *char_code[128] = {0};

void extractHaffmanCode(Node *root, char *buff, int k) {
    buff[k] = 0;
    if (root->l == NULL && root->r == NULL) {
        char_code[root->ch] = strdup(buff);
        return ;
    }
    buff[k] = '0';
    extractHaffmanCode(root->l, buff, k + 1);
    buff[k] = '1';
    extractHaffmanCode(root->r, buff, k + 1);
    return ;
}

int main() {
    char s[10];
    int n, freq;
    scanf("%d", &n);
    Node **node_arr = (Node **)malloc(sizeof(Node *) * n);
    for (int i = 0; i < n; i++) {
        scanf("%s%d", s, &freq);
        node_arr[i] = getNewNode(freq, s[0]);
    }
    Node *root = buildHaffmanTree(node_arr, n);
    char buff[1000];
    extractHaffmanCode(root, buff, 0);
    for (int i = 0; i < MAX_CHAR_NUM; i++) {
        if (char_code[i] == NULL) continue;
        printf("%c : %s\n", i, char_code[i]);
    }
    clear(root);
    return 0;
}
