#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
//int main()
//{
//	//int i = 0;
//	//int sum = 0;
//	//for (size_t i = 1; i <= 100; i++)
//	//{
//	//	sum += i;
//	//}
//	//printf("%d", sum); 
//	return 0;
//}

//#include<math.h>
//
//int IsPrime(int n)
//{
//	int j = 0;
//	for (int j = 2; j < sqrt(n); j+=2)
//	{
//		if (n % j == 0)
//			return 0;
//	}
//	return 1;
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//
//	if (IsPrime(n))
//	{
//		printf("%d������\n", n);
//	}
//	else
//	{
//		printf("%d��������", n);
//	}
//
//	return 0;
//}

#include<math.h>
//int aaa(int n)
//{
//	int i = 0;
//	for (i = 2; i < n; i += 2);
//	{
//		if (n % i == 0)
//		return 0;
//	}
//	return 1;
//}
//
//
//int main()
//{
//	int j = 0;
//	printf("����һ����");
//	scanf("%d", &j);
//	if (aaa(j))
//	{
//		printf("%d������", j);
//	}
//	else
//	{
//		printf("%d��������", j);
//	}
//	return 0;
//}


#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//�Զ��庯����
//����ֵ���� �������������б�{
//	���ܴ���
//}
//����ѡ�Ź���
int yourNum1 = -1;
int zhongjiang = 88;
void xuanhao(yourNum1) {
	printf("��ѡ��������1��");
	printf("��������ĺ��룺");
	int num = 0;
	scanf("%d", &num);
	if (yourNum1 > 9 && yourNum1 < 100)
	{
		printf("ѡ����ɣ���ѡ��");
		yourNum1 = num;
	}
	else
	{
		printf("���������룺");
	}
}
//���忪������
void kaijiang1(zhongjiang, yourNum1) {

	if (zhongjiang == yourNum1)
	{
		printf("��ϲ���н���");
	}
	else
	{
		printf("���ź���δ�н�");
	}
}
//����һ���˵�����
void menue1() {
	printf("\t\t��ӭ�������ϲʿ���ϵͳ\n");
	printf("��ѡ�����Ĳ�����\n\t\t1.��ʼѡ��\t2.���ڿ���\t3.�˳�\n");
	printf("-----------------------------------\n");
}
//�����˳�����
int main() {
	int i = 1;
	while (i)
	{
		int choose;
		menue1();
		scanf("%d", &choose);
		switch (choose)
		{
		case 1:
			xuanhao(yourNum1);
			break;
		case 2:
			kaijiang1(zhongjiang, yourNum1);
			break;
		case 3:
			printf("�˳�");
			i = 0;
			break;
		default:
			break;
		}
	}
}