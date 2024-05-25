/*************************************************************************
	> File Name: 3.hash_table.cpp
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Fri 24 May 2024 01:59:56 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
using namespace std;

typedef struct Node {
    char *s;
    struct Node *next;
} Node;

typedef struct HashTable {
    Node *data;
    int cnt, size;
} HashTable;

Node *getNewNode(const char *s) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->s = strdup(s);
    p->next = NULL;
    return p;
}

HashTable *getNewHashTable(int n) {
    HashTable *h = (HashTable *)malloc(sizeof(HashTable));
    h->data = (Node *)malloc(sizeof(Node) * n);
    h->size = n;
    h->cnt = 0;
    return h;
}

int hash_func(const char *s) {
    int seed = 131, h = 0;
    for (int i = 0; s[i]; i++) {
        h = h * seed + s[i];
    }
    return h & 0x7fffffff;
}

bool find(HashTable *h, const char *s) {
    int hcode = hash_func(s), ind = hcode % h->size;
    Node *p = h->data[ind].next;
    while (p) {
        if (strcmp(p->s, s) == 0) return true;
        p = p->next;
    }
    return false;
}

void swapHashTable(HashTable *h1, HashTable *h2) {
    swap(h1->data, h2->data);
    swap(h1->cnt, h2->cnt);
    swap(h1->size, h2->size);
    return ;
}

void clearHashTable(HashTable *h);
void expand(HashTable *h);

bool insert(HashTable *h, const char *s) {
    // 扩容处理
    if (h->cnt >= h->size * 2) {
        expand(h);
    }
    int hcode = hash_func(s), ind = hcode % h->size;
    // 冲突处理
    Node *p = getNewNode(s);
    p->next = h->data[ind].next; // 头部插入法 (虚拟头)
    h->data[ind].next = p;
    h->cnt += 1;
    return true;
}

void clearNode(Node *p) {
    if (p == NULL) return;
    if (p->s) free(p->s);
    free(p);
    return ;
}

void expand(HashTable *h) {
    HashTable *new_h = getNewHashTable(h->size * 2);
    for (int i = 0; i < h->size; i++) {
        Node *p = h->data[i].next;
        while (p) {
            insert(new_h, p->s);
            p = p->next;
        }
    }
    swapHashTable(h, new_h);
    clearHashTable(new_h);
    return ;
}

void clearHashTable(HashTable *h) {
    if (h == NULL) return ;
    for (int i = 0; i < h->size; i++) {
        Node *p = h->data[i].next, *q;
        while (p) {
            q = p->next;
            clearNode(p);
            p = q;
        }
    }
    free(h->data);
    free(h);
    return ;
}

void output(HashTable *h) {
    printf("\n\nHash Table(%d / %d) : \n", h->cnt, h->size);
    for (int i = 0; i < h->size; i++) {
        cout << i << " : ";
        Node *p = h->data[i].next;
        while (p) {
            printf("%s -> ", p->s);
            p = p->next;
        }
        cout << endl;
    }
    return ;
}

int main() {
    srand(time(0));
    char s[100];
    #define MAX_N 2
    HashTable *h = getNewHashTable(MAX_N);
    while (~scanf("%s", s)) {
        if (strcmp(s, "end") == 0) break;
        insert(h, s);
    }
    output(h);
    printf("now find one baby : \n");
    while (~scanf("%s", s)) {
        printf("find(%s) = %d\n", s, find(h, s));
    }
    return 0;
}
