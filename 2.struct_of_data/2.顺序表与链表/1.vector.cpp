/*************************************************************************
	> File Name: 1.vector.cpp
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Thu 23 May 2024 10:02:46 AM CST
 ************************************************************************/

#include <iostream>
#include <ctime>
#include <cstdio>
#include <cstdlib>

using namespace std;

typedef struct Vector {
    int size, count;
    int *data;
} Vector;

Vector *getNewVector(int n) {
    Vector *p = (Vector *)malloc(sizeof(Vector));
    p->size = n;
    p->count = 0;
    p->data = (int *)malloc(sizeof(int) * n);
    return p;
}

int expand(Vector *v) {
    if (v == NULL) return 0;
    cout << "expand v from " << v->size << " to " << 2 * v->size << endl; 
    int *p = (int *)realloc(v->data, sizeof(int) * 2 * v->size); // realloc函数表示重新分配内存的意思
    if (p == NULL) return 0; // realloc函数的三种情况 （原内存空间后开辟、新地址区开辟、直接返回NULL）
    v->data = p;
    v->size *= 2;
    return 1;
}

int insert(Vector *v, int pos, int val) {
    if (pos < 0 || pos > v->count) return 0;
    if (v->size == v->count && !expand(v)) return 0; // 如果扩容不成功
    for (int i = v->count - 1; i >= pos; i--) { // 逆序遍历 防止数据被覆盖
        v->data[i + 1] = v->data[i]; 
    }
    v->data[pos] = val;
    v->count += 1;
    return 1;
}

int erase(Vector *v, int pos) {
    if (pos < 0 || pos >= v->count) return 0;
    for (int i = pos + 1; i < v->count; i++) {
        v->data[i - 1] = v->data[i];
    }
    v->count -= 1;
    return 1;
}

void output_vector(Vector *v) {
    int len = 0;
    for (int i = 0; i < v->size; i++) len += printf("%3d", i);
    cout << endl;
    for (int i = 0; i < len; i++) cout << "-";
    cout << endl;
    for (int i = 0; i < v->count; i++) printf("%3d", v->data[i]);
    cout << endl << endl;
    return ;
}

void clear(Vector *v) {
    if (v == NULL) return ;
    free(v->data);
    free(v);
    return ;
}

int main() {
    srand(time(0));
    #define MAX_OP 20
    Vector *v = getNewVector(2);
    for (int i = 0; i < MAX_OP; i++) {
        int pos, val, ret, op = rand() % 4;
        switch (op) {
            case 0:
            case 1:
            case 2:
                pos = rand() % (v->count + 2);
                val = rand() % 100;
                ret = insert(v, pos, val);
                cout << "insert " << val << " at " << pos << " to vector = " << ret << endl;
                break;
            case 3:
                pos = rand() %(v->count + 2);
                ret = erase(v, pos);
                cout << "erase item at " << pos << " in vector = " << ret << endl;
                break;
        }
        output_vector(v);
    }
    clear(v);
    return 0;
}
