#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//int global = 2019;//全局变量
//int main()
//{
//    int local = 2018;//局部变量
//    //下面定义的global会不会有问题？
//    int global = 2020;//局部变量
//    printf("global = %d\n", global);
//    return 0;
//}

//extern b;
//int main()
//{
//	{
//		int a = 10;
//		//printf("a = %d\n", a);
//		printf("b = %d\n", b);
//	}
//	//printf("a = %d", a);
//	printf("b = %d\n", b);
//	return 0;
//}


//int main()
//{
//	//char ch = 'a';
//	//printf("%c\n", ch);//打印单个字符串
//	//printf("%d\n", ch);//打印字符的ASCLL码值
//	//printf("%s\n", "ch");//打印字符串
//
//	//printf("len = %d\n", strlen("abc"));
//	char arr1[] = "abcdef";
//	char arr2[] = { 'a','b','c','d','e','f' };
//	
//	printf("arr1 = %s\n", arr1);
//	printf("arr2 = %s\n", arr2);
//
//	printf("arr1 = %d\n", strlen(arr1));
//	printf("arr2 = %d\n", strlen(arr2));	
//
//
//	return 0;
//}

//int main()
//{
//	//printf("abcndef");
//	//printf("abc\ndef");
//	//printf("c:\\test\\code\\test.c\n");
//	//printf("%c\n", '\'');
//	//printf("%s\n", "abc");
//	//printf("%s\n", "a");
//	//printf("%s\n", "\"");
//	printf("%c\n", '\130');
//	printf("%d\n", '\130');
//
//	printf("%c\n", '\x30');
//	printf("%d\n", '\x30');
//
//	printf("%c\n", '\x3a');
//	printf("%d\n", '\x3a');
//
//	return 0;
//}

//int main()
//{
//	int input = 0;
//	printf("你要好好学习吗(1/0)\n");
//	scanf("%d", &input);
//	if (input == 1) 
//	{
//		printf("拿一个好offer\n");
//	}
//	else 
//	{
//		printf("回家种田\n");
//	}
//	return 0;
//}

//int main()
//{
//	int line = 0;
//	printf("好好学习\n");
//	while (line < 20000)
//	{
//		printf("写代码：%d\n", line);
//		line++;
//	}
//	if (line == 20000)
//		printf("好offer\n");
//	return 0;
//}
//int main()
//{
//	int num1 = 0;
//	int num2 = 0;
//	int sum = 0;
//	printf("请输入两个操作数字:>");
//	scanf("%d %d", &num1, &num2);
//
//	sum = num1 + num2;
//	printf("sum = %d\n", sum);
//	return 0;
//}

//int Add(int m, int n)
//{
//	return (m + n);
//}
//int main()
//{
//	int sum1 = 0;
//	int sum2 = 0;
//	int sum3 = 0;
//
//	sum1 = Add(1, 2);
//	sum2 = Add(3, 4);
//	sum3 = Add(5, 6);
//
//	printf("sum1 = %d\n", sum1);
//	printf("sum2 = %d\n", sum2);
//	printf("sum3 = %d\n", sum3);
//	return 0;
//}

//int main()
//{
//	int arr[10] = { 0 };
//	//0 ~ 9 - 输入10个值给数组
//	int i = 0;
//	while (i < 10) 
//	{
//		scanf("%d", &arr[i]);
//		i++;
//	}
//
//	i = 0;
//	while (i < 10) 
//	{
//		printf("%d ", arr[i]);
//		i++;
//	}
//	return 0;
//}


//   + - * / %
// 
//
//int main()
//{
//	int a = 7 / 2;
//	printf("%d\n", a);
//
//	float f = 7 / 2;
//	printf("%f\n", f);
//
//	float f1 = 7 / 2.0;
//	printf("%f\n", f);
//
//	return 0;
//}
/*
int main()
{
	//// % 取余操作符，关注的是除法后的余数
	//int a = 7 % 2;	//商3余1
	//printf("%d\n", a);

	//              >> <<

	//int c = 10;
	//int d = c++;	//先赋值后++
	//// d = c;
	//// c = c + 1

	//printf("%d %d\n", c, d);	//11 10

	//int a = 10;
	//int b = --a;	///先--在赋值

	//printf("%d %d\n", a, b);	//9 9

	//int c = 10;
	//int d = c--;	///先赋值后--

	//printf("%d %d\n", c, d);	//9 10

	//int a = 1;
	//int b = (++a) + (++a) + (++a);
	//printf("%d\n", b);


	//int a = 3.14;
	//printf("%d\n", a);

	//char arr1[] = "abcdef";
	//char arr2[] = "abcdef";
	//if (arr1 == arr2)
	//	printf("==\n");
	//else
	//	printf("!=\n");

	//char arr1[] = "abcdef";
	//char arr2[] = "abcdef";
	//if (strcmp(arr1, arr2) == 0)
	//	printf("==\n");
	//else
	//	printf("!=\n");

	//int a = 0;
	//int b = 0;
	//int c = a && b;
	//printf("c = %d\n", c);
	//if (a || b)
	//	printf("hehe\n");

	int a = 3;
	int b = 5;
	int c = 0;
	int d = (a += 2, b = b - c + a, c = a + b);
	//a = 5	 b = 10			c = 5 + 10 = 15
	printf("d = %d\n", d);
	printf("%d %d %d\n", a, b, c);

	return 0;
}
*/

//void test()
//{
//	static int a = 3;
//	a++;
//	printf("%d ", a);
//}
//int main()
//{
//	int i = 0;
//	while (i < 10)
//	{
//		test();
//		i++;
//	}
//	return 0;
//}

//extern int g_val;	//声明外部符号
//int main()
//{
//	/*printf("%d\n", g_val);*/
//
//	ADD(2, 3);
//	return 0;
//}

//#define MAX 100
//int main()
//{
//	printf("%d\n", MAX);
//	int a = MAX;
//	int arr[MAX] = { 0 };
//
//	printf("%d\n", a);
//	return 0;
//}

int main()
{

	//printf("%p", &a);
	//printf("&a = %d\n", &a);
	//printf("pa = %d\n", pa);
	//printf("*pa = %d\n", *pa);

	//int a = 4;
	//int* pa = &a;
	//printf("%d\n", sizeof(pa));
	//printf("%d\n", sizeof(int*));

	printf("%zu\n", sizeof(short*));
	printf("%zu\n", sizeof(long*));
	printf("%zu\n", sizeof(long long*));
	printf("%zu\n", sizeof(float*));
	printf("%zu\n", sizeof(double*));

	return 0;
}
