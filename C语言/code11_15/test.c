#define _CRT_SECURE_NO_WARNINGS 1


#include<stdio.h>
//int main()
//{
//	int arr[10] = { 0 };//�����ݽ��г�ʼ��
//
//	printf("���������������Ԫ�ص�ֵ��\n");
//	for (int i = 0; i < 10; i++)//��������
//	{
//		scanf("%d", &arr[i]);//�Ӽ��������λ�ȡ���ݴ�������
//	}
//	printf("\n");//�������
//
//	printf("�����Ԫ���������֣�\n");
//	for (int i = 9; i >= 0; i--)//��������
//	{
//		printf("%d ", arr[i]);//����������д�ӡ
//	}
//	printf("\n");
//	printf("�������\n");
//	return 0;
//}

#include <stdio.h>  

//
//void bubbleSort(int arr[], int n) {
//    int i, j, temp;
//    for (i = 0; i < n - 1; i++) //����n-1��
//    {
//        for (j = 0; j < n - i - 1; j++) //����
//        {
//            if (arr[j] > arr[j + 1]) //���н���
//            {
//                // ���� arr[j] �� arr[j+1]  
//                temp = arr[j];
//                arr[j] = arr[j + 1];
//                arr[j + 1] = temp;
//            }
//        }
//    }
//}
//
//int main() {
//    int arr[10];
//    int n, i;
//    printf("������һ��������n(1<n��10): ");
//    scanf("%d", &n);
//    printf("������%d������: ", n);
//    for (i = 0; i < n; i++) 
//    {
//        scanf("%d", &arr[i]);//��������
//    }
//    bubbleSort(arr, n);//���ú���
//    //�������
//    printf("����������: ");
//    for (i = 0; i < n; i++) 
//    {
//        printf("%d ", arr[i]);//��ӡ��������������
//    }
//    printf("\n");
//    printf("�������\n");
//    return 0;
//}

//#include <stdio.h>  
//
////3.��10�������������Ҫ������ǰ���С�����˳�����С�
//int main() {
//    int areas[10] = { 23, 78, 34, 16, 95, 57, 43, 89, 61, 28 }; // ��������10�����������  
//    int i, j, temp;
//
//    // ʹ��ð�������㷨�������������  
//    for (i = 0; i < 9; i++) {
//        for (j = 0; j < 9 - i; j++) {
//            if (areas[j] > areas[j + 1]) {
//                temp = areas[j];
//                areas[j] = areas[j + 1];
//                areas[j + 1] = temp;
//            }
//        }
//    }
//    printf("�������\n");
//    // ��������Ľ��  
//    printf("�������С���������Ľ����\n");
//    for (i = 0; i < 10; i++) {
//        printf("%d ", areas[i]);
//    }
//    printf("\n");
//
//    return 0;
//}

#include <stdio.h>  

//int main() {
//    int scr[10]; // ����һ������Ϊ10���������洢�ɼ�  
//    int i;
//
//    // ѭ������ÿ������Ԫ�أ���ÿ��ͬѧ�ĳɼ�  
//    printf("������10��ͬѧ�ĳɼ���\n");
//    for (i = 0; i < 10; i++) {
//        scanf("%d", &scr[i]);
//    }
//    printf("�������\n");
//    // ѭ�����ÿ������Ԫ�أ���ÿ��ͬѧ�ĳɼ�  
//    printf("10��ͬѧ�ĳɼ�Ϊ��\n");
//    for (i = 0; i < 10; i++) {
//        printf("%d ", scr[i]);
//    }
//    printf("\n");
//
//    return 0;
//}


#include <stdio.h>  

int main() {
    int scr[10]; // ����һ������Ϊ10���������洢�ɼ�  
    int i, sum = 0, max, min;
    double avg;

    // ѭ������ÿ������Ԫ�أ���ÿ��ͬѧ�ĳɼ�  
    for (i = 0; i < 10; i++) {
        printf("�������%d��Ԫ�ص�ֵ:",i + 1);
        scanf("%d", &scr[i]);
        sum += scr[i]; // ����ȫ���ܳɼ�  
    }

    // �������ֵ����Сֵ  
    max = min = scr[0];
    for (i = 1; i < 10; i++) {
        if (scr[i] > max) {
            max = scr[i];
        }
        if (scr[i] < min) {
            min = scr[i];
        }
    }

    // ����ƽ����  
    avg = sum / 10.0;

    printf("�������\n");

    // ѭ�����ÿ������Ԫ�أ���ÿ��ͬѧ�ĳɼ�  
    for (i = 0; i < 10; i++) {
        printf("%d ", scr[i]);
    }
    printf("\n");

    // ���ȫ���ܳɼ���ƽ����  
    printf("���ǣ�%d\n", sum);
    printf("ƽ��ֵ�ǣ�%.2lf\n", avg);
    printf("���ֵ�ǣ�%d\n", max);
    printf("��Сֵ�ǣ�%d\n", min);

    return 0;
}