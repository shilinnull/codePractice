#define _CRT_SECURE_NO_WARNINGS 1
//实现猜数字游戏

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define NUM 10 //设置猜数字的次数

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
		printf("你有%d次机会\n",flag);
		printf("请输入要猜的数字：>");
		scanf("%d", &n);
		if (n < rand_num)
		{
			printf("猜小了！\n");
			flag--;
		}
		else if (n > rand_num)
		{
			printf("猜大了！\n");
			flag--;
		}
		else
		{
			printf("恭喜你猜对了！\n");
			break;
		}
		if (flag == 0)
		{
			printf("次数用完了，数字是%d", rand_num);
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
		printf("请选择：>");
		scanf("%d", &input);

		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，请重新选择！\n");
			break;
		}
	} while (input);

	return 0;
}
