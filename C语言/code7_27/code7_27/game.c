#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define NUM 10 
//���òµ����ִ�������

void menu()
{
	printf("**********************\n");
	printf("******  1.play *******\n");
	printf("******  0.exit *******\n");
	printf("**********************\n");
}

void game()
{
	int guess = 0;
	int ret = rand() % 100 + 1;
	//printf("%d", ret);
	int count = NUM;
	while (1)
	{
		printf("�㻹��%d�λ���\n", count);
		printf("�������:>\n");
		scanf("%d", &guess);
		if (guess > ret)
		{
			printf("�´��ˣ�\n");
		}
		else if (guess < ret)
		{
			printf("��С�ˣ�\n");
		}
		else
		{
			printf("��ϲ�㣬�¶��ˣ�\n");
			break;
		}
		count--;
		if (count == 0)
		{
			printf("�������꣬��ȷ��������%d\n", ret);
			break;
		}
	}


}



int main()
{
	//RAND_MAX
	//srand() 0~32767
	//srand((unsigned int)time(NULL));
	//printf("%d ",rand());
	//printf("%d ", rand() % 100 + 1);
	int input = 0;
	srand((unsigned int)time(NULL));//���������
	do
	{
		menu();
		printf("��ѡ��>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ��\n");
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}

	} while (input);

	return 0;
}



//
//void menu()
//{
//	printf("**********************\n");
//	printf("****** 1. play *******\n");
//	printf("******  0.exit *******\n");
//	printf("**********************\n");
//}
//
//void game()
//{
//	int guess = 0;
//	int ret = rand() % 100 + 1;
//	//printf("%d", ret);
//	while (1)
//	{
//		printf("�������:>\n");
//		scanf("%d", &guess);
//		if (guess > ret)
//		{
//			printf("�´��ˣ�\n");
//		}
//		else if (guess < ret)
//		{
//			printf("��С�ˣ�\n");
//		}
//		else
//		{
//			printf("��ϲ�㣬�¶��ˣ�\n");
//			break;
//		}
//
//	}
//	
//
//}
//
//
//
//int main()
//{
//	//RAND_MAX
//	//srand() 0~32767
//	//srand((unsigned int)time(NULL));
//	//printf("%d ",rand());
//	//printf("%d ", rand() % 100 + 1);
//	int input = 0;
//	srand((unsigned int)time(NULL));//���������
//	do
//	{
//		menu();
//		printf("��ѡ��>");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			game();
//			break;
//		case 0:
//			printf("�˳���Ϸ��\n");
//			break;
//		default:
//			printf("ѡ�����������ѡ��\n");
//			break;
//		}
//
//	} while (input);
//
//	return 0;
//}
