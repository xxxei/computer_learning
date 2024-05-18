#include <iostream>
#include <cstdlib>
#include <ctime>
#include <queue>

using namespace std;

#define FCFS

#define MAX_PROCESS 10

int current_time = 0;
int total_process = 0;

// 进程状态枚举
typedef enum {
    READY,
    RUNNING,
    BLOCKED,
    TERMINATED
} ProcessStatus;

// 进程控制块结构体PCB
typedef struct PCB {
    int pid; // id
    int arrival_time; // 到达时间
    int service_time; // 服务时间
    int start_time; // 开始执行时间
    int end_time; // 结束时间
    ProcessStatus status; // 进程状态 
    int level; // 进程层级
    struct PCB **children; // 指向子进程的指针数组
} PCB;

// 创建进程
PCB *create_process(int pid, int arrival_time, int service_time, int l) {
    PCB *p = (PCB *)malloc(sizeof(PCB));
    if (p == NULL) {
        cout << "Memory allocation failed!" << endl;
        exit(EXIT_FAILURE);
    }
    p->pid = pid;
    p->arrival_time = arrival_time;
    p->service_time = service_time;
    p->start_time = p->end_time = 0;
    p->status = READY;
    p->level = l;
    p->children = NULL;
    return p;
}

// 删除进程及其所有的子进程
void delete_process_tree(PCB *process) {
    if (process == NULL) return ;
    for (int i = 0; i < MAX_PROCESS; i++) {
        delete_process_tree(process->children[i]);
    }
    free(process->children);
    free(process);
    cout << "delete all process success!" <<endl;
    return ;
}

// 进程调度
void schedule(PCB **p) {
#ifdef FCFS
    cout << "This is FCFS : " << endl;
    queue<PCB*> ready_queue;
    int count = 0;
    for (int i = 0; i < MAX_PROCESS && count < total_process; i++) {
        if (p[i] != NULL && p[i]->status == READY) {
            ready_queue.push(p[i]);
            count++;
        }
    }
    while (!ready_queue.empty()) {
        PCB *current_process = ready_queue.front();
        ready_queue.pop();
        current_process->status = RUNNING;
        current_process->start_time = current_time;
        current_process->end_time = current_time + current_process->service_time;
        cout << "Process " << current_process->pid << " is running from " << current_process->start_time << " to " << current_process->end_time << endl;
        current_time = current_process->end_time;
        current_process->status = TERMINATED;
    }
    return ;
#endif
}

// 递归创建子进程
void create_children_process(PCB *parent, int max_level) {
    if (parent->level >= max_level || total_process >= MAX_PROCESS) {
        return ;
    }
    if (parent->children == NULL) {
        return ;
    }
    parent->children = (PCB **)malloc(sizeof(PCB *) * MAX_PROCESS);
    for (int i = total_process; i < MAX_PROCESS; i++) {
        int a = rand() % 5; // 随机到达时间
        int b = rand() % 10 + 1; // 随机服务时间
        parent->children[i] = create_process(total_process, a + parent->arrival_time, b, parent->level + 1);
        total_process++;
        create_children_process(parent->children[i], max_level);
    }
    return ;
}

int main() {
    srand(time(0));
    PCB **process = (PCB **)malloc(sizeof(PCB *) * MAX_PROCESS);
    if (process == NULL) {
        cout << "Memory allocation failed!" << endl;
        return 0;
    }

    // 创建进程树
    for (int i = 0; i < MAX_PROCESS; i++) {
        int a = rand() % 5; // 随机到达时间
        int b = rand() % 10 + 1; // 随机服务时间
        process[i] = create_process(i, a, b, 0);
        total_process++;
        create_children_process(process[i], 4); // 创建4层进程树
    }

    // 进行进程调度
    schedule(process);

    // 删除进程树
    delete_process_tree(process[0]);
    free(process);

    return 0;
}
