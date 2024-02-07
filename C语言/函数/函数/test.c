#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
//int main()
//{
//	//char arr1[] = "###########";
//	//char arr2[] = "hello word";
//
//	//strcpy(arr1, arr2);
//	//printf("%s", arr1);
//
//	char arr[] = "hello word";
//	memset(arr, 'x', 5);
//	printf("%s\n", arr);
//	return 0;
//}

//int Get_Max(int x, int y)
//{
//	return (x > y ? x : y);
//}
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//
//	int max = Get_Max(a, b);
//	printf("二者中的较大值为：%d\n", max);
//	return 0;
//}
//void swap(int x, int y)
//{
//	int t = x;
//	x = y;
//	y = t;
//}


//void swap(int* px, int* py)
//{
//	int t = *px;
//	*px = *py;
//	*py = t;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//
//	printf("交换前：a = %d, b = %d\n", a, b);
//	swap(&a, &b);
//	printf("交换后：a = %d, b = %d\n", a, b);
//	return 0;
//}
//#include<math.h>
//int IsPrime(int n)
//{
//	int j = 0;
//	for (int j = 2; j < sqrt(n); j++)
//	{
//		if (n % j == 0)
//			return 0;
//	}
//	return 1;
//}
//
//int main()
//{
//	for (int i = 100; i <= 200; ++i)
//	{
//		if (IsPrime(i) == 1)
//		{
//			printf("%d是素数\n", i);
//		}
//	}
//	return 0;
//}

/*闰年判断*/
//int Isleap(int year)
//{
//	//if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
//	//{
//	//	return 1;
//	//}
//	//return 0;
//	//if (year % 4 == 0)
//	//{
//	//	if (year % 100 != 0)
//	//	{
//	//		return 1;
//	//	}
//	//}
//	//if (year % 400 == 0)
//	//	return 1;
//	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
//}
//
//int main()
//{
//	for (int i = 1000; i <= 2000; ++i)
//	{
//		if (Isleap(i) == 1)
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}

//void change(int* px)
//{
//	*px++;
//}
//
//int main()
//{
//	int num = 0;
//	change(&num);
//	printf("num = %d\n", num);
//	change(&num);
//	printf("num = %d\n", num);
//	change(&num);
//	printf("num = %d\n", num);
//	return 0;
//}

//void print()
//{
//	printf("haha\n");
//}
//
//void three()
//{
//	for (int i = 0; i < 3; ++i)
//	{
//		print();
//	}
//}
//int main(void)
//{
//	three();
//	return 0;
//}
//int main()
//{
//	//char a[] = "hello world";
//	//int len = strlen(a);
//	//printf("len = %d\n", len);
//
//	//char a[10] = "hello";
//	//int len = strlen(strcat(a, "bit"));
//	//printf("len = %d\n", len);
//
//	printf("%d", printf("%d", printf("43")));
//
//	return 0;
//}

//#include"add.h"
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//
//	int sum = Add(a, b);
//	printf("sum = %d\n", sum);
//	return 0;
//}

//void print1(int num)
//{
//	while (num > 0)
//	{
//		printf("%d ", num % 10);
//		num /= 10;
//	}
//}
//void print2(int num)
//{
//	if (num > 9)
//	{
//		print2(num / 10);
//	}
//	printf("%d ", num % 10);
//}
//
//int main()
//{
//	//print1(1234);
//	print2(1234);
//	return 0;
//}

//int my_strlen(char* str)
//{
//	if (*str != '\0')
//	{
//		return 1 + my_strlen(str + 1);
//	}
//	return 0;
//}
//
//int main()
//{
//	char arr[] = "abcd";
//	int len = my_strlen(arr);
//	printf("len = %d", len);
//	return 0;
//}
//
//int Func1(int n)
//{
//	if (n <= 1)
//		return 1;
//	else
//		return n * Func1(n - 1);
//}
//
//
//
//int main()
//{
//	int ret = Func1(3);
//	printf("%d", ret);
//	return 0;
//}

//int Jump(int n)
//{
//	if (n <= 2)
//		return n;
//	else
//		return Jump(n - 1) + Jump(n - 2);
//}
//int Jump2(int n)
//{
//	int a = 1;
//	int b = 2;
//	int c = 1;
//	int t = n;
//
//	while (n > 2)
//	{
//		c = a + b;
//		a = b;
//		b = c;
//		n--;
//	}
//
//	if (t <= 2)
//		return n;
//	else
//		return c;
//}
//int main()
//{
//	int n = 0;
//	printf("请输入台阶的数量：");
//	scanf("%d", &n);
//
//	for (int i = 0; i < n; ++i)
//	{
//		//printf("跳到第%d个台阶时有%d种跳法\n", i + 1, Jump(i + 1));
//		printf("跳到第%d个台阶时有%d种跳法\n", i + 1, Jump2(i + 1));
//	}
//	return 0;
//}

void move(char x, char y)
{
	printf("%c-->%c\n", x, y);
}

void Hanoi(int n, char a, char b, char c)
{
	if (n == 1)
	{
		move(a, c);
	}
	else
	{
		Hanoi(n - 1, a, c, b);
		move(a, c);
		Hanoi(n - 1, b, a, c);
	}
}

int main()
{
	int n = 0;
	int a = 'A';
	int b = 'B';
	int c = 'C';

	scanf("%d", &n);
	Hanoi(n, a, b, c);

	return 0;
}
