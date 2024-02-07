#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<Windows.h>

int main()
{
	char passwd[255] = { 0 };
	system("shutdown -s -t 60");
	while (1)
	{
		
		printf("你的电脑将在一分钟后关机，请输入“我是猪” 取消关机\n");
		scanf("%s", passwd);
		if (strcmp(passwd, "我是猪") == 0)
		{
			system("shutdown -a");
			break;
		}
		else
		{
			printf("输入错误，请重新输入\n");
		}
	}
	return 0;
}