#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <assert.h>
/*
��ӡ�������
*/


//
//int main() {
//    int n = 0;
//    //scanf("%d", &n);
//    int arr[10][10] = { 0 };
//    for (int i = 0; i < 10; i++) {
//        for (int j = 0; j <= i; j++) {
//            if (j == 0 || i == j) {
//                arr[i][j] = 1;
//            }
//            if (i >= 2 && j >= 1) {
//                arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
//            }
//        }
//    }
//    for (int i = 0; i < 10; i++) {
//        for (int j = 0; j <= i; j++) {
//            printf("%5d", arr[i][j]);
//        }
//        printf("\n");
//    }
//    return 0;
//}
//
//int main()
//{
//	//��һ�����������в��Ҿ����ĳ������n
//	//1 2 3 4 5 6 7 8 9 10
//	
//	//���ֲ��ҷ�
//	int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(a) / sizeof(a[0]);
//	int key = 7;//Ҫ���ҵ�����k
//	int left = 0;
//	int right = sz - 1;
//
//	while (left <= right)
//	{
//		int mid = (left + right) / 2;//�м�Ԫ���±�һ����ѭ���ڲ������ϱ仯
//		if (key < a[mid])
//			right = mid - 1;
//		else if (key > a[mid])
//			left = mid + 1;
//		else
//		{
//			printf("�ҵ��ˣ��±���%d\n", mid);
//			break;		//�ҵ��˱�����ѭ��
//		}
//	}
//	if (left > right)
//		printf("û�ҵ���Ԫ��\n");
//	return 0;
//}
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//void menu()
//{
//	printf("\n");
//	printf("********************************\n");
//	printf("**********  1.play  ************\n");
//	printf("**********  0.exit  ************\n");
//	printf("********************************\n");
//	printf("\n");
//}
//void game()
//{
//	int random_num = rand() % 100 + 1;
//	int flag = 10;
//	int input = 0;
//	while (1)
//	{
//		printf("��������%d\n", flag);
//
//		printf("������µ�����>:");
//		scanf("%d", &input);
//		if (input > random_num)
//		{
//			printf("�´���\n");
//			flag--;
//		}
//		else if (input < random_num)
//		{
//			printf("��С��\n");
//			flag--;
//		}
//		else
//		{
//			printf("��ϲ�㣬�¶���\n");
//			break;
//		}
//		if (flag == 0) {
//			printf("���������ˣ�������%d", random_num);
//			break;
//		}
//	}
//}
//int main()
//{
//	int input = 0;
//	srand((unsigned int)time(NULL));
//	do
//	{
//		menu();
//		printf("��ѡ��>:");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			game();
//			break;
//		case 0:
//			break;
//		default:
//			printf("ѡ�����,����������!\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}
//
//int main() {
//	int x = 1;
//	if (x) {
//		printf("hehe");
//	}
//	else {
//		printf("haha");
//	}
//	return 0;
//}

//
//int main() {
//	int s = 0;
//	int i = 1;
//	while (s <= 10) {
//		s = s + i * i;
//		i++;
//	}
//	printf("%d\n", --i);
//	return 0;
//}
int main() {
	int a = 10;
	a = a | 1 << 2;
	printf("%d", a);
	return 0;
}