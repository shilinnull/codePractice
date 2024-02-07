#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
/*

【7月25日上机打卡&每日一题】
大家可以上机并完成每日一题打卡啦~
【今日题目】：
请输出所有的"水仙花数"。
所谓"水仙花数"是指一个3位数,其各位数字立方和等于该数本身。
例如,153是水仙花数,因为153=1^3+5^3+3^3"

*/
int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	int sum = 0;
	printf("请输入三位数来判断是否为水仙花数：>\n");
	while (scanf("%d", &sum) != EOF)
	{
		a = sum % 10;
		b = sum / 10 % 10;
		c = sum / 100;
		if ((a * a * a) + (b * b * b) + (c * c * c) == sum) //水仙花数"是指一个3位数,其各位数字立方和等于该数本身
		{
			printf("是水仙花数\n");
		}
		else
		{
			printf("不是水仙花数\n");
		}
	}

	return 0;
}
