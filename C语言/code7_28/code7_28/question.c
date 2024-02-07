#define _CRT_SECURE_NO_WARNINGS 1

/*
��������Ŀ����
��ʵ������������������ĺ�����
  1. ��ʵ��GetMaxValOfArray�������ú�������һ���������飬
  ��Ԫ�ظ�����������������Ԫ�����ֵ������
  2. ��ʵ��GetMinValOfArray�������ú�������һ���������飬
  ��Ԫ�ظ�����������������Ԫ����Сֵ������
  3. ��ʵ�ֺ���PrintArray����ӡ����������Ԫ��
*/




#include <stdio.h>
// ��ȡ�����е����ֵ
int getmaxvalofarray(int arr[], int n) {
    if (n <= 0) {
        printf("����Ԫ�ظ����������0\n");
        return -1; // ����ͨ���������ʾ�쳣���
    }
    int max_val = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }
    return max_val;
}
// ��ȡ�����е���Сֵ
int getminvalofarray(int arr[], int n) {
    if (n <= 0) {
        printf("����Ԫ�ظ����������0\n");
        return -1; // ����ͨ���������ʾ�쳣���
    }
    int min_val = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min_val) {
            min_val = arr[i];
        }
    }

    return min_val;
}
// ��ӡ�����е�����Ԫ��
void printarray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main() {
    int arr[] = { 3, 7, 1, 9, 4, 2, 6, 8, 5 };
    int num_elements = sizeof(arr) / sizeof(arr[0]);
    // ��ȡ�����е����ֵ����ӡ
    int max_val = getmaxvalofarray(arr, num_elements);
    printf("�����е����ֵΪ: %d\n", max_val);
    // ��ȡ�����е���Сֵ����ӡ
    int min_val = getminvalofarray(arr, num_elements);
    printf("�����е���СֵΪ: %d\n", min_val);
    // ��ӡ�����е�����Ԫ��
    printf("�����е�����Ԫ��: ");
    printarray(arr, num_elements);
    return 0;
}
