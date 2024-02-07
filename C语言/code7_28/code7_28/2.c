#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义学生结构体
struct Student {
    int num;
    char name[20];
    char sex;
    int age;
    int score[3];
    int totalScore;
    float averageScore;
};

// 计算总分和平均分的函数
void count(struct Student* students, int n) {
    for (int i = 0; i < n; i++) {
        students[i].totalScore = 0;
        for (int j = 0; j < 3; j++) {
            students[i].totalScore += students[i].score[j];
        }
        students[i].averageScore = (float)students[i].totalScore / 3;
    }
}

int main() {
    int n;

    printf("请输入学生的数量: ");
    scanf("%d", &n);

    // 动态分配内存来存储学生数组
    struct Student* students = (struct Student*)malloc(n * sizeof(struct Student));

    // 输入学生数据
    for (int i = 0; i < n; i++) {
        printf("\n请输入第%d个学生的数据:\n", i + 1);
        printf("学号: ");
        scanf("%d", &students[i].num);

        printf("姓名: ");
        scanf("%s", students[i].name);

        printf("性别(M/F): ");
        getchar(); // 消耗掉输入缓冲区中的换行符
        scanf("%c", &students[i].sex);

        printf("年龄: ");
        scanf("%d", &students[i].age);

        printf("三门课成绩: ");
        for (int j = 0; j < 3; j++) {
            scanf("%d", &students[i].score[j]);
        }
    }

    // 调用计算函数
    count(students, n);

    // 输出所有学生数据
    printf("\n所有学生的数据:\n");
    for (int i = 0; i < n; i++) {
        printf("学号: %d, 姓名: %s, 性别: %c, 年龄: %d, 成绩: %d %d %d, 总分: %d, 平均分: %.2f\n",
            students[i].num, students[i].name, students[i].sex, students[i].age,
            students[i].score[0], students[i].score[1], students[i].score[2],
            students[i].totalScore, students[i].averageScore);
    }

    // 释放动态分配的内存
    free(students);

    return 0;
}
