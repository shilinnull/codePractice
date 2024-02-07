#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define NUM 10 
//设置猜的数字次数多少

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
		printf("你还有%d次机会\n", count);
		printf("请猜数字:>\n");
		scanf("%d", &guess);
		if (guess > ret)
		{
			printf("猜大了！\n");
		}
		else if (guess < ret)
		{
			printf("猜小了！\n");
		}
		else
		{
			printf("恭喜你，猜对了！\n");
			break;
		}
		count--;
		if (count == 0)
		{
			printf("次数用完，正确的数字是%d\n", ret);
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
	srand((unsigned int)time(NULL));//生成随机数
	do
	{
		menu();
		printf("请选择：>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏！\n");
			break;
		default:
			printf("选择错误，请重新选择！\n");
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
//		printf("请猜数字:>\n");
//		scanf("%d", &guess);
//		if (guess > ret)
//		{
//			printf("猜大了！\n");
//		}
//		else if (guess < ret)
//		{
//			printf("猜小了！\n");
//		}
//		else
//		{
//			printf("恭喜你，猜对了！\n");
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
//	srand((unsigned int)time(NULL));//生成随机数
//	do
//	{
//		menu();
//		printf("请选择：>");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			game();
//			break;
//		case 0:
//			printf("退出游戏！\n");
//			break;
//		default:
//			printf("选择错误，请重新选择！\n");
//			break;
//		}
//
//	} while (input);
//
//	return 0;
//}
