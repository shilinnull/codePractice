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
//		printf("%d是素数\n", n);
//	}
//	else
//	{
//		printf("%d不是素数", n);
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
//	printf("输入一个数");
//	scanf("%d", &j);
//	if (aaa(j))
//	{
//		printf("%d是素数", j);
//	}
//	else
//	{
//		printf("%d不是素数", j);
//	}
//	return 0;
//}


#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//自定义函数：
//返回值类型 函数名（参数列表）{
//	功能代码
//}
//定义选号功能
int yourNum1 = -1;
int zhongjiang = 88;
void xuanhao(yourNum1) {
	printf("您选择的是序号1：");
	printf("请输入你的号码：");
	int num = 0;
	scanf("%d", &num);
	if (yourNum1 > 9 && yourNum1 < 100)
	{
		printf("选号完成，请选择：");
		yourNum1 = num;
	}
	else
	{
		printf("请重新输入：");
	}
}
//定义开奖功能
void kaijiang1(zhongjiang, yourNum1) {

	if (zhongjiang == yourNum1)
	{
		printf("恭喜你中奖了");
	}
	else
	{
		printf("很遗憾，未中奖");
	}
}
//定义一个菜单功能
void menue1() {
	printf("\t\t欢迎进入六合彩开奖系统\n");
	printf("请选择您的操作：\n\t\t1.开始选号\t2.现在开奖\t3.退出\n");
	printf("-----------------------------------\n");
}
//定义退出功能
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
			printf("退出");
			i = 0;
			break;
		default:
			break;
		}
	}
}