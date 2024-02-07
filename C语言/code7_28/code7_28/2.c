#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ����ѧ���ṹ��
struct Student {
    int num;
    char name[20];
    char sex;
    int age;
    int score[3];
    int totalScore;
    float averageScore;
};

// �����ֺܷ�ƽ���ֵĺ���
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

    printf("������ѧ��������: ");
    scanf("%d", &n);

    // ��̬�����ڴ����洢ѧ������
    struct Student* students = (struct Student*)malloc(n * sizeof(struct Student));

    // ����ѧ������
    for (int i = 0; i < n; i++) {
        printf("\n�������%d��ѧ��������:\n", i + 1);
        printf("ѧ��: ");
        scanf("%d", &students[i].num);

        printf("����: ");
        scanf("%s", students[i].name);

        printf("�Ա�(M/F): ");
        getchar(); // ���ĵ����뻺�����еĻ��з�
        scanf("%c", &students[i].sex);

        printf("����: ");
        scanf("%d", &students[i].age);

        printf("���ſγɼ�: ");
        for (int j = 0; j < 3; j++) {
            scanf("%d", &students[i].score[j]);
        }
    }

    // ���ü��㺯��
    count(students, n);

    // �������ѧ������
    printf("\n����ѧ��������:\n");
    for (int i = 0; i < n; i++) {
        printf("ѧ��: %d, ����: %s, �Ա�: %c, ����: %d, �ɼ�: %d %d %d, �ܷ�: %d, ƽ����: %.2f\n",
            students[i].num, students[i].name, students[i].sex, students[i].age,
            students[i].score[0], students[i].score[1], students[i].score[2],
            students[i].totalScore, students[i].averageScore);
    }

    // �ͷŶ�̬������ڴ�
    free(students);

    return 0;
}
