#define _CRT_SECURE_NO_WARNINGS 1
//ʵ�ֲ�������Ϸ

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define NUM 10 //���ò����ֵĴ���

void neum()
{
	printf("\n");
	printf("*******************\n");
	printf("******  1.play  ***\n");
	printf("******  0.exit  ***\n");
	printf("*******************\n");
}


void game()
{
	int rand_num = rand() % 100 + 1;
	int n = 0;
	int flag = NUM;
	while (1)
	{
		printf("����%d�λ���\n",flag);
		printf("������Ҫ�µ����֣�>");
		scanf("%d", &n);
		if (n < rand_num)
		{
			printf("��С�ˣ�\n");
			flag--;
		}
		else if (n > rand_num)
		{
			printf("�´��ˣ�\n");
			flag--;
		}
		else
		{
			printf("��ϲ��¶��ˣ�\n");
			break;
		}
		if (flag == 0)
		{
			printf("���������ˣ�������%d", rand_num);
			break;
		}
	}
}
int main()
{

	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		neum();
		printf("��ѡ��>");
		scanf("%d", &input);

		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}
	} while (input);

	return 0;
}
