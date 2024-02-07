#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//代码1
//int main()
//{
//    int age = 0;
//    scanf("%d", &age);
//    if (age < 18)
//    {
//        printf("未成年\n");
//    }
//}
////代码2
//#include <stdio.h>
//int main()
//{
//    int age = 0;
//    scanf("%d", &age);
//    if (age < 18)
//    {
//        printf("未成年\n");
//    }
//    else
//    {
//        printf("成年\n");
//    }
//}
//代码3
//#include <stdio.h>
//int main()
//{
//    int age = 0;
//    scanf("%d", &age);
//    if (age < 18)
//    {
//        printf("少年\n");
//    }
//    else if (age >= 18 && age < 30)
//    {
//        printf("青年\n");
//    }
//    else if (age >= 30 && age < 50)
//    {
//        printf("中年\n");
//    }
//    else if (age >= 50 && age < 80)
//    {
//        printf("老年\n");
//    }
//    else
//    {
//        printf("老寿星\n");
//    }
//
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	if (n % 2 == 1)
//	{
//		printf("YES\n");
//	}
//	else
//	{
//		printf("NO\n");
//	}
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int i = 1;
//	while (i<= 100)//产生1~100的数字
//	{
//		if(i % 2 ==1)
//			printf("%d ", i);
//		i++;
//	}
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int i = 1;
//	while (i <= 100)//产生1~100的数字
//	{
//		printf("%d ", i);
//		//i+=2;
//		i = i + 2;//也可以这样写
//	}
//	return 0;
//}

//
//#include <stdio.h>
////switch代码演示
//int main()
//{
//    int day = 0;
//    switch (day)
//    {
//        case 1:
//        case 2:
//        case 3:
//        case 4:
//        case 5:
//            printf("weekday\n");
//            break;
//        case 6:
//        case 7:
//            printf("weekend\n");
//            break;
//    }
//    return 0;
//}

//#include <stdio.h>
//int main()
//{
//    int n = 1;
//    int m = 2;
//    switch (n)
//    {
//    case 1:
//        m++;
//    case 2:
//        n++;
//    case 3:
//        switch (n)
//        {//switch允许嵌套使用
//        case 1:
//            n++;
//        case 2:
//            m++;
//            n++;
//            break;
//        }
//    case 4:
//        m++;
//        break;
//    default:
//        break;
//    }
//    printf("m = %d, n = %d\n", m, n);
//    return 0;
//}
//#include <stdio.h>
//int main()
//{
//    int i = 1;
//    while (i <= 10)
//    {
//        if (i == 5)
//            break;
//        printf("%d ", i);
//        i = i + 1;
//    }
//    return 0;
//}
//
//#include <stdio.h>
//int main()
//{
//    int i = 1;
//    while (i <= 10)
//    {
//        if (i == 5)
//            continue;
//        printf("%d ", i);
//        i = i + 1;
//    }
//    return 0;
//}


#include <stdio.h>
//int main()
//{
//    int i = 1;
//    while (i <= 10)
//    {
//        if (i == 5)
//            break;
//        printf("%d ", i);
//        i = i + 1;
//    }
//    return 0;
//}
//#include <stdio.h>
//int main()
//{
//    int i = 1;
//    while (i <= 10)
//    {
//        i = i + 1; 
//        if (i == 5)
//            continue;
//        printf("%d ", i);
//    }
//    return 0;
//}

//#include <stdio.h>
//int main()
//{
//    int ch = 0;
//    while ((ch = getchar()) != EOF)
//        putchar(ch);
//    return 0;
//}
//这里的代码适当的修改是可以用来清理缓冲区的.
//代码2
//#include <stdio.h>
//int main()
//{
//    char ch = '\0';
//    while ((ch = getchar()) != EOF)
//    {
//        if (ch < '0' || ch > '9')
//            continue;
//        putchar(ch);
//    }
//    return 0;
//}
//这个代码的作用是：只打印数字字符，跳过其他字符的、
//
//#include <stdio.h>
//int main()
//{
//	int i = 0;
//	//for(i=1/*初始化*/; i<=10/*判断部分*/; i++/*调整部分*/)
//	for (i = 1; i <= 10; i++)
//	{
//		printf("%d ", i);
//	}
//	return 0;
//}
//
//int main()
//{
//	char password[20];
//	scanf("%s", password);
//	printf("请确认（Y/N）：");
//	int ch = getchar();
//	if ('Y' == ch)
//		printf("确认成功\n");
//	else
//		printf("确认失败\n");
//	return 0;
//}
//
//for (...)
//for (...)
//{
//    for (...)
//    {
//        if (disaster)
//            goto error;
//    }
//}
//…
//error :
//if (disaster)
//// 处理错误情况
//
//void menu()
//{
//	printf("********************************\n");
//	printf("**********  1.play  ************\n");
//	printf("**********  0.exit  ************\n");
//}
//int main(void)
//{
//	int input = 0;
//	do
//	{
//		menu();
//		printf("请输入你的选择：>");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			printf("猜数字\n");
//			break;
//		case 0:
//			printf("退出游戏\n");
//			break;
//		default:
//			printf("输入错误，重新输入\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//void menu()
//{
//	printf("**********************************\n");
//	printf("*********** 1.play     **********\n");
//	printf("*********** 0.exit     **********\n");
//	printf("**********************************\n");
//}
////RAND_MAX--rand函数能返回随机数的最大值。
//void game()
//{
//	int random_num = rand() % 100 + 1;
//	int input = 0;
//	while (1)
//	{
//		printf("请输入猜的数字>:");
//		scanf("%d", &input);
//		if (input > random_num)
//		{
//			printf("猜大了\n");
//		}
//		else if (input < random_num)
//		{
//			printf("猜小了\n");
//		}
//		else
//		{
//			printf("恭喜你，猜对了\n");
//			break;
//		}
//	}
//}
//int main()
//{
//	int input = 0;
//	srand((unsigned)time(NULL));
//	do
//	{
//		menu();
//		printf("请选择>:");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			game();
//			break;
//		case 0:
//			break;
//		default:
//			printf("选择错误,请重新输入!\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}

//int main(void)
//{
//	char arr1[] = "############";
//	char arr2[] = "hello bit";
//	strcpy(arr1, arr2);
//	printf("%s\n", arr1);
//	return 0;
//}
//int main()
//{
//
//	char arr[] = "hello bit";
//	memset(arr, 'x', 5);
//	printf("%s\n", arr);
//	return 0;
//}
//void swap(int x, int y)
//{
//	int t = x;
//	x = y;
//	y = t;
//}
//
//int main(void)
//{
//	int a = 10;
//	int b = 20;
//
//	printf("交换前：a = %d, b = %d\n", a, b);
//	swap(a, b);
//	printf("交换后：a = %d, b = %d\n", a, b);
//	return 0;
//}
//
//
//#include<stdio.h>
//#include<assert.h>
//
//size_t my_strlen(const char* src)
//{
//	assert(src);
//	size_t len = 0;
//	while (*src != '\0')
//	{
//		len++;
//		src++;
//	}
//	return len;
//}
//
//int main()
//{
//	char arr[] = "abcdef";
//	size_t ret = my_strlen(arr);
//	printf("%d", ret);
//	return 0;
//}


#include<stdio.h>
#include<assert.h>

char* my_strcpy(char* dest,const char* src)
{
	assert(src && dest);
	char* ret = dest;
	while (*dest++ = *src++);
	return ret;
}

int main()
{
	char arr1[20] = { 0 };
	char arr2[] = "abcdef";
	my_strcpy(arr1, arr2);
	printf("%s", arr1);
	return 0;
}