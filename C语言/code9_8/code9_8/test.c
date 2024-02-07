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


//二分查找
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

//编写代码实现，模拟用户登录情景，并且只能登录三次。
//（只允许输入三次密码，如果密码正确则 提示登录成，如果三次均输入错误，则退出程序
/*

#include<string.h>
int main()
{
	char password[256] = { 0 };
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		printf("请输入密码:>\n");
		scanf("%s", &password);
		if (strcmp(password, "123456") == 0)
		{
			printf("登录成功\n");
			break;
		}
		else
		{
			printf("登录失败\n");
		}
	}
	if (i == 3)
	{
		printf("输入次数超出限制！\n");
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
////体重公斤数除以   身高米数  平方得出的数字
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

//写一个代码打印1 - 100之间
// 所有3的倍数的数字

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

//写一个代码：打印100~200之间的素数
//#include<stdio.h>
//int main()
//{
//	int i = 100, j, count = 0;//count 作为计数器数出有多少个素数
//	for (i; i <= 200; i++)
//	{
//		int flag = 1;//先假设i就为素数
//		for (j = 2; j < i; j++)
//		{
//			if (i % j == 0)//判断是否余0余0则换下一位整数【这也可以写成if(i%j)】
//			{
//				flag = 0;
//				break;
//			}
//		}
//		if (flag == 1)//满足条件则 说明该数为素数【这也可以写成if(flag)】
//		{
//			count++;//素数个数加1
//			printf("%d ", i);//打印该素数
//		}
//	}
//	printf("\n%d", count); //打印100 - 200间素数的个数
//}


//打印1000年到2000年之间的闰年

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
//	printf("最大公约数是%d\n", a);
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
//	printf("最大值是%d\n", max);
//	return 0;
//}

//计算1/1-1/2+1/3-1/4+1/5 …… + 1/99 - 1/100 的值，打印出结果

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
//		//判断i是否是素数
//		//素数也叫质数，只能被1和和本身整除
//		//2~i-1
//		int j = 0;
//		int flag = 1; //假设是素数
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