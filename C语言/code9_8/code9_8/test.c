#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
//
//max(int x, int y)
//{
//	return (x > y ? x : y);
//}
//int main()
//{
//	int num1 = 0;
//	int num2 = 0;
//	scanf("%d %d", &num1, &num2);
//	int ret = max(num1, num2);
//	printf("%d\n", ret);
//	return 0;
//}

//int main()
//{
//
//	int ch = 0;
//	while ((ch = getchar()) != EOF)
//	{
//		putchar(ch);
//	}
//	return 0;
//}
//
//#include <stdio.h> 
//int main() 
//{ 
//	int i = 0; int k = 0; 
//	for(i =0,k=0; k=0; i++,k++) 
//		k++; 
//	return 0; 
//}
//

//
//int main()
//{
//	int n = 0;
//	//scanf("%d", &n);
//	int i = 0;
//	int ret = 0;
//	int sum = 0;
//	for (n = 1; n <= 3; n++)
//	{
//		ret = 1;
//		for (i = 1; i <= n; i++)
//		{
//			ret *= i;
//		}
//		sum += ret;
//	}
//	printf("%d\n", sum);
//	return 0;
//}
//
//int main()
//{
//	int n = 0;
//	int sum = 1;
//	int ret = 0;
//
//	for (n = 1; n <= 3; n++)
//	{
//		sum *= n;
//		ret += sum;
//	}
//	printf("%d\n", ret);
//	return 0;
//}


//���ֲ���
//
//int Find(int arr[], int k, int left, int right)
//{
//	while (left <= right)
//	{
//		int mid = left + (right - left) / 2;
//		if (arr[mid] < k)
//		{
//			left = mid + 1;
//		}
//		else if (arr[mid] > k)
//		{
//			right = mid - 1;
//		}
//		else
//		{
//			return mid;
//			break;
//		}
//		return -1;
//	}
//}
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int k = 7;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int ret = Find(arr, k, 0, sz - 1);
//	printf("%d\n", ret);
//	return 0;
//}
//
//#include<string.h>
//#include<windows.h>
//int main()
//{
//	char arr1[] = "hello word!!!!";
//	char arr2[] = "**************";
//	int left = 0;
//	int right = strlen(arr2) - 1;
//	while (left <= right)
//	{
//		arr2[left] = arr1[left];
//		arr2[right] = arr1[right];
//		printf("%s\n", arr2);
//		Sleep(1000);
//		system("cls");
//		left++;
//		right--;
//	}
//	printf("%s\n", arr2);
//	return 0;
//}

//��д����ʵ�֣�ģ���û���¼�龰������ֻ�ܵ�¼���Ρ�
//��ֻ���������������룬���������ȷ�� ��ʾ��¼�ɣ�������ξ�����������˳�����
/*

#include<string.h>
int main()
{
	char password[256] = { 0 };
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		printf("����������:>\n");
		scanf("%s", &password);
		if (strcmp(password, "123456") == 0)
		{
			printf("��¼�ɹ�\n");
			break;
		}
		else
		{
			printf("��¼ʧ��\n");
		}
	}
	if (i == 3)
	{
		printf("��������������ƣ�\n");
	}
	return 0;
}

*/


//#include <stdio.h>
//
//int main()
//{
//	int arr[10] = { 0 };
//	for (int i = 0; i < 10; i++)
//	{
//		scanf("%d", arr[i]);
//	}
//	for (int i = 9; i >= 0; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}
//
//#include <stdio.h>
//
////���ع���������   �������  ƽ���ó�������
//int main() {
//	double kg = 0;
//	double cm = 0;
//	scanf("%lf %lf", &kg, &cm);
//	double s = (cm / 100) * 2;
//	printf("%.2lf", kg / s);
//
//	return 0;
////}
//#include <stdio.h>
//int sum(int a)
//{
//	int c = 0;
//	static int b = 3;
//	c += 1; // c = 1
//	b += 2; // b = 5
//	return (a + b + c);
//	//a = 2,
//}
//int main()
//{
//	int i;
//	int a = 2;
//	for (i = 0; i < 5; i++)
//	{
//		printf("%d,", sum(a));
//	}
//}
//#include <stdio.h>
//
//int main() {
//	char a, ch;
//	while (scanf("%c", &ch) != EOF)
//	{
//		if (ch >= 'A' && ch <= 'Z')
//		{
//			printf("%c\n", ch + 32);
//		}
//
//		else if (ch >= 'a' && ch <= 'z')
//		{
//			printf("%c\n", ch - 32);
//
//		}
//	}
//	return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		if (i = 5)
//			printf("%d ", i);
//	}
//	return 0;
//}
//int func(int a)
//{
//	int b;
//	switch (a)
//	{
//	case 1: b = 30;
//	case 2: b = 20;
//	case 3: b = 16;
//	default: b = 0;
//	}
//	return b;
//}

//
//#include <stdio.h>
//int main() {
//	int x = 3;
//	int y = 3;
//	switch (x % 2) {
//	case 1:
//		switch (y)
//		{
//		case 0:
//			printf("first");
//		case 1:
//			printf("second");
//			break;
//		default: printf("hello");
//		}
//	case 2:
//		printf("third");
//	}
//	return 0;
//}

//дһ�������ӡ1 - 100֮��
// ����3�ı���������

//int main()
//{
//	int i = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		if(i%3 == 0)
//			printf("%d ", i);
//	}
//	return 0;
//}
//
//int main()
//{
//	int a, b, c;
//	scanf("%d %d %d", &a, &b, &c);
//	if (a < b)
//	{
//		int tmp = a;
//		a = b;
//		b = tmp;
//	}
//	if (a < c)
//	{
//		int tmp = c;
//		c = a;
//		a = tmp;
//	}
//	if (b < c)
//	{
//		int tmp = b;
//		b = c;
//		c = tmp;
//	}
//	printf("a=%d b=%d c=%d\n", a, b, c);
//	return 0;
//}
//

//#include <stdio.h>
//int main()
//{
//	int a = 0, b = 0;
//	for (a = 1, b = 1; a <= 100; a++)
//	{
//		if (b >= 20) break;
//		if (b % 3 == 1)
//		{
//			b = b + 3;
//			continue;
//		}
//		b = b - 5;
//	}
//	printf("%d\n", a);
//	return 0;
//}

//дһ�����룺��ӡ100~200֮�������
//#include<stdio.h>
//int main()
//{
//	int i = 100, j, count = 0;//count ��Ϊ�����������ж��ٸ�����
//	for (i; i <= 200; i++)
//	{
//		int flag = 1;//�ȼ���i��Ϊ����
//		for (j = 2; j < i; j++)
//		{
//			if (i % j == 0)//�ж��Ƿ���0��0����һλ��������Ҳ����д��if(i%j)��
//			{
//				flag = 0;
//				break;
//			}
//		}
//		if (flag == 1)//���������� ˵������Ϊ��������Ҳ����д��if(flag)��
//		{
//			count++;//����������1
//			printf("%d ", i);//��ӡ������
//		}
//	}
//	printf("\n%d", count); //��ӡ100 - 200�������ĸ���
//}


//��ӡ1000�굽2000��֮�������

//int main()
//{
//	
//	for (int i = 1000; i <= 2000; i++)
//	{
//		if ((i % 4 == 0) && (i % 100 != 0) || (i % 400 == 0))
//		{
//			printf("%d ", i);
//		}
//	}
//
//	return 0;
//}

//int main()
//{
//	int a = 0;
//	int b = 0;
//	int tmp = 0;
//	scanf("%d %d", &a, &b);
//	while (b)
//	{
//		tmp = a % b;
//		a = b;
//		b = tmp;
//	}
//	printf("���Լ����%d\n", a);
//	return 0;
//}

//int main()
//{
//	for (int i = 1; i <= 9; i++)
//	{
//		for (int j = 1; j <= i; j++)
//		{
//			printf(" %d*%d=%2d ", j, i, i * j);
//		}
//		printf("\n");
//	}
//	return 0;
//}
//
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int max = arr[0];
//	for (int i = 0; i < 10; i++)
//	{
//		if (arr[i] > max)
//		{
//			max = arr[i];
//		}
//	}
//	printf("���ֵ��%d\n", max);
//	return 0;
//}

//����1/1-1/2+1/3-1/4+1/5 ���� + 1/99 - 1/100 ��ֵ����ӡ�����

//int main()
//{
//	double sum = 1.0;
//	int flag = 1;
//	for (int i = 1; i <= 100; i++)
//	{
//		sum += 1.0 / flag;
//		flag = -flag;
//	}
//	printf("%lf", sum);
//	return 0;
//}

//#include<stdio.h>
//
//int main()
//{
//	int count = 0;
//	for (int i = 9; i <= 100; i++)
//	{
//		if (i % 10 == 9)
//		{
//			count++;
//		}
//		else if (i / 10 == 9)
//		{
//			count++;
//		}
//	}
//	printf("%d", count);
//	return 0;
//}
//
//
//#include<stdio.h>
//int main()
//{
//	int i = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		//�ж�i�Ƿ�������
//		//����Ҳ��������ֻ�ܱ�1�ͺͱ�������
//		//2~i-1
//		int j = 0;
//		int flag = 1; //����������
//		for (j = 2; j < i; j++)
//		{
//			if (i % j == 0)
//			{
//				flag = 0;
//				break;
//			}
//		}
//		if (flag == 1)
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}

int main()
{
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			printf(" %d*%d=%-2d ", j, i, i * j);
		}
		printf("\n");
	}
	return 0;
}