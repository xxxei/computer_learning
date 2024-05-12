/*************************************************************************
	> File Name: student_system.c
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Sun 28 Apr 2024 04:19:49 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

const char *file_name = "student_data.txt";
#define output_format "%10s%4d%4d%7.2lf"

typedef struct student {
    long offset;
    char name[20];
    int age;
    int class;
    double height;
} student;

#define MAX_N 10000
student stu_arr[MAX_N + 5];
int stu_cnt;

int read_from_file(student *arr) {
    int i = 0;
    FILE *fp = fopen(file_name, "r");
    if (fp == NULL) return 0;
    while (1) {
        long offset = ftell(fp);
        if (fscanf(fp, "%s", arr[i].name) == EOF) break;
        fscanf(fp, "%d%d%lf",
              &arr[i].age,
              &arr[i].class,
              &arr[i].height
        );
        arr[i].offset = offset;
        fgetc(fp); // 吞掉换行符
        i += 1;
    }
    fclose(fp);
    return i;
}

long output_to_file(student *arr, int n) {
    FILE *fp = fopen(file_name, "a");
    fseek(fp, 0, SEEK_END);
    long offset = ftell(fp);
    for (int i = 0; i < n; i++) {
        fprintf(fp, output_format "\n",
            arr[i].name, arr[i].age,
            arr[i].class, arr[i].height
        );
    }
    fclose(fp);
    return offset;
}

void clear_file() {
    FILE *fp = fopen(file_name, "w");
    fclose(fp);
    return ;
}

void restor_data_to_file(student *arr, int n) {
    clear_file();
    output_to_file(arr, n);
    return ;
}

void list_students() {
    int len = printf("%4s|%10s|%4s|%6s|%7s|",
        "id", "name", "age", "class", "height"
    );
    printf("\n");
    for (int i = 0; i < len; i++) printf("=");
    printf("\n");
    for (int i = 0; i < stu_cnt; i++) {
        printf("%4d|%10s|%4d|%6d|%7.2lf|\n",
            i, stu_arr[i].name, stu_arr[i].age,
            stu_arr[i].class, stu_arr[i].height
        );
    }
    return ;
}

void add_students() {
    printf("add new item : (name, age, class, height)\n");
    printf("mysql > ");
    scanf("%s%d%d%lf",
        stu_arr[stu_cnt].name,
        &stu_arr[stu_cnt].age,
        &stu_arr[stu_cnt].class,
        &stu_arr[stu_cnt].height
    );
    stu_arr[stu_cnt].offset = output_to_file(stu_arr + stu_cnt, 1);
    stu_cnt += 1;
    printf("add a new student success!\n");
    return ;
}

void modify_data_to_file(student *stu) {
    FILE *fp = fopen(file_name, "r+");
    fseek(fp, stu->offset, SEEK_SET);
    fprintf(fp, output_format,
        stu->name, stu->age,
        stu->class, stu->height
    );
    fclose(fp);
    return ;
}

void modify_students() {
    list_students();
    int id;
    do {
        printf("modify id : ");
        scanf("%d", &id);
    } while (id < 0 || id >= stu_cnt);
    printf("modify a item : (name, age, class, height)\n");
    printf("mysql > ");
    scanf("%s%d%d%lf",
        stu_arr[id].name,
        &stu_arr[id].age,
        &stu_arr[id].class,
        &stu_arr[id].height
    );
    modify_data_to_file(stu_arr + id);
    printf("modify a item success!\n");
    return ;
}

void delete_students() {
    if (stu_cnt == 0) {
        printf("there is no student\n");
        return ;
    }
    list_students();
    int id;
    do {
        printf("delete id : ");
        scanf("%d", &id);
    } while (id < 0 || id >= stu_cnt);
    char s[100];
    printf("confirm (y / n) : ");
    getchar();
    scanf("%[^\n]", s);
    if (s[0] != 'y') return ;
    for (int i = id + 1; i < stu_cnt; i++) {
        long offset = stu_arr[i - 1].offset;
        stu_arr[i - 1] = stu_arr[i];
        stu_arr[i - 1].offset = offset; 
    }
    stu_cnt -= 1;
    restor_data_to_file(stu_arr, stu_cnt);
    printf("delete success!\n");
    return ;
}

enum NO_TYPE {
    LIST = 1,
    ADD,
    MODIFY,
    DELETE,
    QUIT
};

int usage() {
    int no;
    do {
        printf("%d : list students\n", LIST);
        printf("%d : add a new student\n", ADD);
        printf("%d : modify a student\n", MODIFY);
        printf("%d : delete a student\n", DELETE);
        printf("%d : quit\n", QUIT);
        printf("mysql > ");
        scanf("%d", &no);
    } while (no < LIST || no > QUIT); //只有当no值为1到5的时候才会返回no值
    return no;
}

int main() {
    stu_cnt = read_from_file(stu_arr);
    while (1) {
        int no = usage();
        switch (no) {
            case LIST: {
                list_students();
            } break;
            case ADD: {
                add_students();
            } break;
            case MODIFY: {
                modify_students();
            } break;
            case DELETE: {
                delete_students();
            } break;
            case QUIT: printf("quit\n"); exit(1);
        }
    }
    return 0;
}
