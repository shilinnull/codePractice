#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
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

/*
���Լ���������������й���Լ��������ߡ�
���ķ�ʽ�Ƚ϶࣬������١�շת�������������𷨡�Stein�㷨�㷨
�˴���Ҫ���ܣ�շת�����


˼·��
���ӣ�18��24�����Լ��
��һ�Σ�a = 18  b = 24  c = a%b = 18%24 = 18
	  ѭ���У�a = 24   b=18
�ڶ��Σ�a = 24   b = 18  c = a%b = 24%18 = 6
	  ѭ���У�a = 18   b = 6


�����Σ�a = 18   b = 6   c=a%b = 18%6 = 0
  ѭ������

��ʱb�е����ݼ�Ϊ�������е����Լ����
*/

//
//int main()
//{
//	int a = 18;
//	int b = 24;
//	int c = 0;
//	while (c = a % b)
//	{
//		a = b;
//		b = c;
//	}
//	printf("%d", b);
//	return 0;
//}
//


/*
˼·��
1. ���������ʽ���Է�����
   a. �ñ��ʽ��Ҫ��100�������Ϊ����ż����Ϊ��
2. ����һ��ѭ����1~100���������ʽ�е�ÿһ�1.0/i, ע��˴�����ʹ��1��������ȫ��Ϊ0
	Ȼ��ʹ��flag��ǿ�����ż�������Ϊ����ż����Ϊ��
	Ȼ�����е�����Ӽ���
*/

//int main()
//{
//
//
//	int i = 0;
//	double sum = 0.0;
//	int flag = 1;
//	for (i = 1; i <= 100; i++) {
//		sum += flag * 1.0 / i;
//		flag = -flag;
//	}
//	printf("%lf", sum);
//
//	return 0;
//}


/*
˼·��
������������������1���Լ�֮�⣬��û��������Լ�����������Ϊ���������巽ʽ����
*/
//
//int main()
//{
//	int i = 0;
//	int j = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		int flag = 1;
//		for (j = 2; j < i; j++)
//		{
//			if (i % j == 0)
//			{
//				flag = 0;
//				break;
//			}
//		}
//
//		if (flag)
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}
//

//int main()
//{
//	int a = 18;
//	int b = 24;
//	int c = 0;
//	while (c = a % b)
//	{
//		a = b;
//		b = c;
//	}
//
//	printf("%d", b);
//	return 0;
//}
//����1/1-1/2+1/3-1/4+1/5 ���� + 1/99 - 1/100 ��ֵ����ӡ�����

//int main()
//{
//	double sum = 0.0;
//	int flag = 1;
//	for (int i = 1; i <= 100; i++)
//	{
//		sum += flag * 1.0 / i;
//		flag = -flag;
//	}
//	printf("%lf", sum);
//	return 0;
//}
//��д������һ�� 1�� 100 �����������г��ֶ��ٸ�����9
//int main()
//{
//	int i = 0;
//	int count = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		if (i % 10 == 9)
//		{
//			count++;
//		}else if (i / 10 == 9)
//		{
//			count++;
//		}
//		
//	}
//
//	printf("%d", count);
//	return 0;
//}
//

//��������Ϸ
//
//#include<stdlib.h>
//#include<math.h>
//#include<time.h>
//void enmu()
//{
//	printf("\n");
//	printf("********************\n");
//	printf("****  1. play  *****\n");
//	printf("****  0. exit  *****\n");
//	printf("********************\n");
//	printf("\n");
//}
//
//
//void game()
//{
//	int ret = rand() % 100 + 1;
//	int flag = 10;
//	while (1)
//	{
//		int n = 0;
//		printf("������%d\n", flag);
//
//		printf("�������:>");
//		scanf("%d", &n);
//		if (ret > n)
//		{
//			printf("��С��\n");
//			flag--;
//		}
//		else if (ret < n)
//		{
//			printf("�´���\n");
//			flag--;
//		}
//		else {
//			printf("�¶���,������%d\n", ret);
//			break;
//		}
//		if (flag == 0)
//		{
//			printf("����������������%d\n", ret);
//			break;
//		}
//	}
//}
//
//int main()
//{
//	int input = 0;
//	srand((unsigned int)time(NULL));
//
//	do
//	{
//		enmu();
//		printf("��ѡ��>\n");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			game();
//			break;
//		case 0:
//			printf("�˳���Ϸ\n");
//			break;
//		default:
//			printf("ѡ�����������ѡ��\n");
//		}
//	} while (input);
//
//
//
//	return 0;
//}

//���ֲ���
//
//void Find_key(int arr[], int left, int right, int k)
//{
//	int flag = 0;
//	while (left <= right) {
//		int mid = left + (right - left) / 2;
//		if (arr[mid] > k) {
//			right = mid - 1;
//		}
//		else if (arr[mid] < k) {
//			left = mid + 1;
//		}
//		else {
//			flag = 1;
//			printf("�ҵ����±���%d\n", mid);
//			break;
//		}
//	}
//	if(flag ==0)
//		printf("�Ҳ���\n");
//}
//
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int k = 7;
//	Find_key(arr, 0, sz - 1, k);
//	return 0;
//}
//void PrintMulTable(int k){
//	int i = 0;
//	int j = 0;
//	for (i = 1; i <= k; i++) {
//		for (j = 1; j <= i; j++) {
//			printf("%d*%d=%-2d ", j, i, i * j);
//		}
//		printf("\n");
//	}
//}
//
//int main() {
//	int n = 0;
//	while (scanf("%d", &n) != EOF) {
//		PrintMulTable(n);
//	}
//	return 0;
//}

//ʵ�ֺ����ж�year�ǲ������ꡣ

//void is_leap_year(int y) {
//	if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0) {
//		printf("%d ", y);
//	}
//}
//
//int main() {
//	for (int y = 1000; y < 2000; y++){
//		is_leap_year(y);
//	}
//	
//}

#include<math.h>
//int is_prime(int n) {
//	for (int j = 2; j <= sqrt(n); j++)
//	{
//		if (n % j == 0) {
//			return 0;
//		}
//	}
//	return 1;
//}
//
//int main() {
//	for (int i = 101; i < 200; i+=2) {
//		if (is_prime(i)) {
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}

//int Fun(int n)
//{
//	if (n == 5)
//		return 2;
//	else
//		return 2 * Fun(n + 1);
//}

//int Fib(int n) {
//	if (n <= 2)
//		return 1;
//	else
//		return Fib(n - 1) + Fib(n - 2);
//}
//
//
//int main(){
//	int n = 0;
//	scanf("%d", &n);
//	int ret = Fib(n);
//	printf("%d", ret);
//	return 0;
//}

//int main() {
//	int a = 1;
//	int b = 1;
//	int c = 1;
//	int n = 0;
//	scanf("%d", &n);
//	while (n >= 3) {
//		c = a + b;
//		a = b;
//		b = c;
//		n--;
//	}
//	printf("%d", c);
//
//}
#include<string.h>
void reveres_string(char* str, int len) {
	char* start = str;
	char* end = str+len - 1;
	while (start < end) {
		char tmp = *start;
		*start = *end;
		*end = tmp;
		start++;
		end--;
	}
}

int main() {
	char arr[] = "abcdef";
	int len = strlen(arr);
	reveres_string(arr,len);
	printf("%s", arr);
	return 0;
}


