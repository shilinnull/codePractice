#define _CRT_SECURE_NO_WARNINGS 1

/*
���ӷ�ֳ���⣺�ٶ�һ�Դ�����ÿ������һ��С���ӣ�
��ÿ��������С���Ӿ���һ���¿��Գ���һ�Դ�����,
�߱���ֳ�����������������������ÿ�ξ�����һ��һ�ۣ�
��һ����ж��ٶ����ӣ�
*/

#include <stdio.h>

int rabbitPairs(int months) {
    if (months == 1 || months == 2) {
        return 1; // ��ʼʱֻ��һ������
    } else {
        // �ݹ����ǰ�����µ�����������Ȼ�������������������
        return rabbitPairs(months - 1) + rabbitPairs(months - 2);
    }
}

int main() {
    int months_per_year = 12;
    int total_rabbits = rabbitPairs(months_per_year);

    printf("һ����� %d ������\n", total_rabbits);

    return 0;
}
