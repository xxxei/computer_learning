#include <iostream>
#include <cstdlib>
#include <ctime>
#include <queue>

using namespace std;

#define FCFS

#define MAX_PROCESS 10
#define MAX_CHILDREN 3
#define MEMORY_SIZE 64

int current_time = 0;
int total_process = 0;

// 进程状态枚举
typedef enum {
    READY,
    RUNNING,
    BLOCKED,
    TERMINATED
} ProcessStatus;

typedef struct MemoryBlock {
    bool allocated; // 是否已分配
    int size, zone; // 内存块大小和回收区
} MemoryBlock;

MemoryBlock memory[MEMORY_SIZE]; // 内存空间

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
    
    int allocated_memory; // 已分配的内存大小
    MemoryBlock *memory_block; // 分配内存块指针
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

    p->allocated_memory = 0;
    p->memory_block = NULL;
    return p;
}

// 删除进程及其所有的子进程
void delete_process_tree(PCB *process) {
    if (process == NULL) return ;
    for (int i = 0; i < MAX_CHILDREN; i++) {
        delete_process_tree(process->children[i]);
    }
    free(process->children);

    // 释放进程的内存块
    if (process->memory_block != NULL) {
        MemoryBlock *block = (MemoryBlock *)(process->memory_block);
        block->allocated = false;
    }
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

// 首次适应算法内存分配函数
MemoryBlock *first_fit_allocate(int size, int zone) {
    for (int i = 0; i < MEMORY_SIZE; i++) {
        if (!memory[i].allocated && memory[i].size >= size && memory[i].zone == zone) {
            int j = i;
            int allocated_size = 0;
            while (j < MEMORY_SIZE && !memory[j].allocated && allocated_size < size && memory[j].zone == zone) {
                allocated_size += memory[j].size;
                j++;
            }
            if (allocated_size >= size) {
                for (int k = i; k < j; k++) {
                    memory[k].allocated = true;
                }
                return &memory[i];
            }
        }
        return NULL;
    }
}

// 最佳适应算法内存分配函数
MemoryBlock *best_fit_allocate(int size, int zone) {
    int best_index = -1;
    int smallest_size = MEMORY_SIZE + 1;
    for (int i = 0; i < MEMORY_SIZE; i++) {
        if (!memory[i].allocated && memory[i].size >= size && memory[i].zone == zone) {
            best_index = i;
            smallest_size = memory[i].size;
        }
    }
    if (best_index != -1) {
        int j = best_index;
        int allocated_size = 0;
        while (j < MEMORY_SIZE && !memory[j].allocated && allocated_size < size && memory[j].zone == zone) {
            allocated_size += memory[j].size;
            j++;
        }
        if (allocated_size >= size) {
            for (int k = best_index; k < j; k++) {
                memory[k].allocated = true;
            }
            return &memory[best_index];
        }
    }
    return NULL;
}

// 内存回收函数
void deallocate(MemoryBlock *block) {
    MemoryBlock *b = (MemoryBlock *)block;
    for (int i = 0; i < MEMORY_SIZE; i++) {
        if (&memory[i] == b) {
            memory[i].allocated = false;
            break;
        }
    }
}

// 动态分配内存给进程
bool allocate_memory(PCB *process) {
    int size = rand() % 10 + 1;
    int zone = process->level;
    int flag = rand() % 2;
    switch (flag) {
        case 0: {
            cout << "This is first_fit_allocate" << endl;
            MemoryBlock *block = first_fit_allocate(size, zone);
            if (block == NULL) {
                cout << "Memory allocation failed for process" << process->pid << endl;
                return false;
            }
            process->allocated_memory = size;
            process->memory_block = block;
            cout << "Memory allocated for process " << process->pid << ": " << size << " blocks" << endl;
            return true;
        }
        case 1: {
            cout << "This is best_fit_allocate" << endl;
            MemoryBlock *block = best_fit_allocate(size, zone);
            if (block == NULL) {
                cout << "Memory allocation failed for process" << process->pid << endl;
                return false;
            }
            process->allocated_memory = size;
            process->memory_block = block;
            cout << "Memory allocated for process " << process->pid << ": " << size << " blocks" << endl;
            return true;
        }
    }
}

// 回收进程内存
void deallocate_memory(PCB* process) {
    if (process->memory_block == NULL) {
        return ;
    }
    deallocate(process->memory_block);
    MemoryBlock* memory_block = (MemoryBlock*)process->memory_block;
    memory_block->allocated = false;
    process->memory_block = NULL;
    cout << "Memory deallocated for process " << process->pid << endl;
    return ;
}

// 递归创建子进程
void create_children_process(PCB *parent, int max_level) {
    if (parent->level >= max_level || total_process >= MAX_PROCESS) {
        return ;
    }
    parent->children = (PCB **)malloc(sizeof(PCB *) * MAX_CHILDREN);
    if (parent->children == NULL) {
        cout << "Memory allocation failed!" << endl;
        exit(EXIT_FAILURE);
    }
    for (int i = total_process; i < MAX_CHILDREN; i++) {
        int a = rand() % 5; // 随机到达时间
        int b = rand() % 10 + 1; // 随机服务时间
        if (total_process < MAX_PROCESS) {
            parent->children[i] = create_process(total_process, a + parent->arrival_time, b, parent->level + 1);
            total_process++;
            bool result = allocate_memory(parent->children[i]);
            if (!result) {
                cout << "Memory allocation failed to process" << parent->children[i]->pid << endl;
                deallocate_memory(parent->children[i]);
                continue;
            }
            create_children_process(parent->children[i], max_level);
        }
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
