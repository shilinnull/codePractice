#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
//
////求1*1+2*2+3*3+...+50*50
//int main()
//{
//	int i = 1;
//	int sum = 1;
//	
//	for (i = 1; i <= 50; i++)
//	{
//		sum += i * i;
//	}
//
//	printf("%d", sum);
//	return 0;
//}

//int main()
//{
//	int x = 0;
//	int y = 0;
//	scanf("%d", &x);
//	if (x < 1){
//		printf("x = %d,y = x = %d", x,x);
//	}
//	else if (x >= 1 && x < 10) {
//		printf("x = %d,y = 2 * x - 1 = %d", x, 2 * x - 1);
//	}
//	else if (x >= 10) {
//		printf("x = %d,y = 3 * x - 11 = %d", x , 3 * x - 11);
//	}
//
//
//	return 0;
//}




#include <stdio.h>

//int main() {
//    int year;
//
//    printf("请输入一个年份：");
//    scanf("%d", &year);
//
//    if (year % 4 == 0 && year % 100 != 0) {
//        printf("%d年是闰年\n", year);
//    }
//    else if (year % 400 == 0) {
//        printf("%d年是闰年\n", year);
//    }
//    else {
//        printf("%d年不是闰年\n", year);
//    }
//
//    return 0;
//}

#include <stdio.h>

//int main() {
//    int score;
//    char grade;
//
//    printf("请输入成绩：");
//    scanf("%d", &score);
//
//    switch (score / 10) {
//    case 10:
//    case 9:
//        grade = 'A';
//        break;
//    case 8:
//        grade = 'B';
//        break;
//    case 7:
//        grade = 'C';
//        break;
//    case 6:
//        grade = 'D';
//        break;
//    default:
//        grade = 'E';
//        break;
//    }
//
//    printf("等级：%c\n", grade);
//
//    return 0;
//}   

//
//#include <stdio.h>
//
//int main() {
//    char ch;
//
//    scanf("%c", &ch);
//
//    if (ch >= 'A' && ch <= 'Z') {
//        ch = ch + 32; 
//        printf("%c\n", ch);
//    }
//    else {
//        printf("输入的字符不是大写字母，不进行转换。\n");
//    }
//    return 0;
//}


//int main()
//{
//	//char ch = 'w';
//	//char* pc = &ch;
//
//	const char* p = "abcdefghi";
//
//	printf("%c", *p);
//
//	*p = 'w';
//
//	return 0;
//}


//int main()
//{
//	const char* p = "abcdefghi";
//
//	printf("%s", p);
//
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	char str1[] = "hello bit.";
//	char str2[] = "hello bit.";
//	const char* str3 = "hello bit.";
//	const char* str4 = "hello bit.";
//	if (str1 == str2)
//		printf("str1 and str2 are same\n");
//	else
//		printf("str1 and str2 are not same\n");
//	if (str3 == str4)
//		printf("str3 and str4 are same\n");
//	else
//		printf("str3 and str4 are not same\n");
//	return 0;
//}

//
////求1*1+2*2+3*3+...+50*50
//int main()
//{
//	int i = 1;
//	int sum = 1;
//	
//	while (i<=50)
//	{
//		sum += i * i;
//		i++;
//	}
//
//
//	printf("%d", sum);
//	return 0;
//}



//int main()
//{
//	int arr[10] = { 0 };
//	int(*p)[10] = &arr;//得到的就是数组的地址
//
//	return 0;
//}

//int main()
//{
//	int arr[10] = { 0 };
//	arr; //数组首元素的地址 -- int*
//	&arr;//数组的地址      -- int(*)[10]
//
//	return 0;
//}

//#include <stdio.h>
//void test(int a[3][5], int r, int c)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < r; i++)
//	{
//		for (j = 0; j < c; j++)
//		{
//			printf("%d ", a[i][j]);
//		}
//		printf("\n");
//	}
//}
//int main()
//{
//	int arr[3][5] = { {1,2,3,4,5}, {2,3,4,5,6},{3,4,5,6,7} };
//	test(arr, 3, 5);
//	return 0;
//}


//#include <stdio.h>
//void test(int(*p)[5], int r, int c)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < r; i++)
//	{
//		for (j = 0; j < c; j++)
//		{
//			printf("%d ", *(*(p + i) + j));
//		}
//		printf("\n");
//	}
//}
//int main()
//{
//	int arr[3][5] = { {1,2,3,4,5}, {2,3,4,5,6},{3,4,5,6,7} };
//	test(arr, 3, 5);
//	return 0;
//}

//#include <stdio.h>
//void test()
//{
//	printf("hehe\n");
//}
//int main()
//{
//	printf("test:  %p\n", test);
//	printf("&test: %p\n", &test);
//	return 0;
//}

//void test()
//{
//	printf("hehe\n");
//}
//
//void (*pf1)() = &test;
//void (*pf2)() = test;

//int Add(int x, int y)
//{
//	return x + y;
//}
//int main()
//{
//	int (*pf)(int, int) = &Add;
//
//	int r = pf(3, 5);//调用函数指针
//
//	printf("r = %d\n", r);
//
//	return 0;
//}

//typedef unsigned int uint;
//typedef int* ptr_t;
//typedef int(*ptr)[5];
//



#include <stdio.h>

void menu()
{
	printf("*************************\n");
	printf(" 1:add 2:sub \n");
	printf(" 3:mul 4:div \n");
	printf(" 0:exit \n");
	printf("*************************\n");
}

int add(int a, int b)
{
	return a + b;
}
int sub(int a, int b)
{
	return a - b;
}
int mul(int a, int b)
{
	return a * b;
}
int div(int a, int b)
{
	return a / b;
}
int main()
{
	int x, y;
	int input = 1;
	int ret = 0;
	int(*pfArr[5])(int x, int y) = { 0, add, sub, mul, div }; //转移表
	do
	{
		menu();
		printf("请选择：");
		scanf("%d", &input);
		if ((input <= 4 && input >= 1))
		{
			printf("输入操作数：");
			scanf("%d %d", &x, &y);
			ret = (*pfArr[input])(x, y);
			printf("ret = %d\n", ret);
		}
		else if (input == 0)
		{
			printf("退出计算器\n");
		}
		else
		{
			printf("输入有误,请重新选择\n");
		}
	} while (input);
	return 0;
}

