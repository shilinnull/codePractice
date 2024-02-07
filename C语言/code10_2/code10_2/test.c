#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//int main()
//{
//	// 1.开辟空间
//	//int* p = (int*)malloc(10*sizeof(int));
//	int* p = (int*)calloc(10,sizeof(int));
//
//	// 2.异常判断
//	if (NULL == p)
//	{
//		perror("malloc	");
//		return 1;
//		//exit(-1);
//	}
//
//	//3.初始化空间
//	for (int i = 0; i < 10; ++i)
//	{
//		*(p + i) = i + 1;
//	}
//
//	// 4.打印观察
//	//for (int i = 0; i < 10; ++i)
//	//{
//	//	printf("%d ", *(p + i));
//	//}
//
//	int* tmp = (int*)realloc(p, sizeof(int) * 10);
//	if (tmp == NULL)
//	{
//		perror("fail realloc");
//		return 1;
//	}
//	p = tmp;
//	tmp = NULL;
//
//	//free(p);
//	//p = NULL;
//	return 0;
//}

//int main()
//{
//	int* p = (int*)malloc(100 * sizeof(int));
//	if (NULL == p)
//	{
//		perror("malloc");
//		return 1;
//	}
//
//	int i = 0;
//	for (int i = 0; i <= 10; i++)
//	{
//		p[i] = 0;	// 当i == 10时便会越界
//	}
//	free(p);
//	p = NULL;
//	return 0;
//}

//void test()
//{
//	int a = 10;
//	int* p = &a;
//	free(p);	//ok?
//}
//void test()
//{
//    int* p = (int*)malloc(100);
//    if (NULL == p)
//    {
//        perror("malloc fail");
//        return 1;
//    }
//    for (int i = 0; i < 10; i++)
//    {
//        p++;
//    }
//    free(p);    //p不再指向动态内存的起始位置
//}


//void test()
//{
//    int* p = (int*)malloc(100);
//    //使用...
//    free(p);
//
//    //...
//     free(p);	//重复释放
//}
//
//void test()
//{
//    int* p = (int*)malloc(100);
//    使用...
//    free(p);
//    p = NULL;   // 将不使用的指针置为NULL
//    ...
//    free(p);	//重复释放
//}
//
//void test()
//{
//	int* p = (int*)malloc(100);
//	if (NULL != p)
//	{
//		*p = 20;
//	}
//}
//int main()
//{
//	test();
//	return 0;
// }
//
//void GetMemory(char* p)
//{
//	p = (char*)malloc(100);
//}
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(str);
//	strcpy(str, "hello world");
//	printf(str);
//}

//char* GetMemory(void)
//{
//	char p[] = "hello world";
//	return p;
//}
//void Test(void)
//{
//	char* str = NULL;
//	str = GetMemory();
//	printf(str);
//}
//int main()
//{
//	Test();
//	return 0;
//}
#include<assert.h>

//char* my_strncpy(char* dest, const char* src, size_t num)
//{
//	assert(dest && src);
//	char* start = dest;
//	while (num && (* dest++ = *src++))
//	{
//		num--;
//	}
//	if (num)
//	{
//		while (--num)
//		{
//			*dest++ = '\0';
//		}
//	}
//	return start;
//}
//
//int main()
//{
//	char arr1[10] = { 0 };
//	char arr2[] = "hello world";
//	my_strncpy(arr1, arr2, 5);
//	printf("%s\n", arr1);
//	return 0;
//}
//char* my_strncat(char* dest, const char* src, size_t num)
//{
//	assert(dest && src);
//	char* start = dest;
//
//	//1.首先让dest先移动到\0的位置
//	while (*dest != '\0')
//	{
//		dest++;
//	}
//	//2.从\0开始拷贝src中的num个字符
//	while (num--)
//	{
//		if ((*dest++ = *src++) == '\0')
//			return start;		//碰到\0直接返回，不再补充\0
//	}
//	*dest = '\0';		//最后在目标字符串的末尾处添上\0
//	return start;
//}
//
//
//int main()
//{
//	char arr1[20] = "hello ";
//	char arr2[] = "word !";
//	my_strncat(arr1, arr2, 5);
//	printf("%s\n", arr1);
//	return 0;
//}
//
//void FindTwoNum(int arr[], int n, int* pnum1, int* pnum2)
//{
//	int i = 0;
//	int sum = 0;
//
//	for (i = 0; i < n; i++)
//	{
//		sum ^= arr[i];
//	}
//
//	int pos = 0;
//	for (i = 0; i < 32; i++)
//	{
//		if ((sum >> i) & 1)
//		{
//			pos = i;
//			break;
//		}
//	}
//
//	for (i = 0; i < n; i++)
//	{
//		if ((arr[i] >> pos) & 1)
//		{
//			*pnum1 ^= arr[i]; 
//		}
//		else
//		{
//			*pnum2 ^= arr[i]; 
//		}
//	}
//}
//
//int main()
//{
//	int arr[] = { 1,1,4,4,5,7,77,7,5,8,88,8 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int num1 = 0;
//	int num2 = 0;
//	FindTwoNum(arr, sz, &num1, &num2);
//
//	printf("%d  %d\n", num1, num2);
//
//	return 0;
//}

#include<stdio.h>
#include<assert.h>
#include<ctype.h>
#include<stdlib.h>
enum State
{
	VAILD,
	INVAILD
}Sta = INVAILD;//创造变量默认为非法



//
//int my_atoi(const char* str)
//{
//	assert(str);
//	if (*str == '\0')
//	{
//		return 0;
//	}
//	while (isspace(*str))
//	{
//		str++;
//	}
//	int flag = 1;
//	if (*str == '+')
//	{
//		flag = 1;
//		str++;
//	}
//	else if (*str == '-')
//	{
//		flag = -1;
//		str++;
//	}
//	long long ret = 0;
//	while (*str != '\0')
//	{
//		if (isdigit(*str))
//		{
//			ret = ret * 10 + flag * (*str - '0');//减去字符0，才是数字0
//			if (ret > INT_MAX || ret < INT_MIN)
//			{
//				return 0;
//			}
//		}
//		else
//		{
//			return (int)ret;//强制类型转化为int（函数的返回值是int）
//		}
//		str++;
//	}
//	if (*str == '\0')
//	{
//		Sta = VAILD; //正常转换完了，到末尾的 \0
//	}
//	return (int)ret;
//
//
//
//
//}
//int main()
//{
//	char arr[20] = "1234";
//	int ret = my_atoi(arr);
//	if (Sta == VAILD)
//	{
//		printf("合法转换:%d\n", ret);
//	}
//	else if (Sta == INVAILD)
//	{
//		printf("非法转换:%d\n", ret);
//	}
//	return 0;
//}
//
#include<string.h>
#include<stdlib.h>
#include<stdio.h>

//void GetMemory(char** p)
//{
//	*p = (char*)malloc(100);
//}
//
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(&str);
//	strcpy(str, "hello world\n");
//	printf(str);
//
//	// 释放
//	free(str);
//	str = NULL;
//}
//char* GetMemory(void)
//{
//	static char p[] = "hello world";
//	return p;
//}
//
//void Test(void)
//{
//	char* str = NULL;
//	str = GetMemory();
//	printf(str);
//}
//int main()
//{
//	Test();
//	return 0;
//}

//int* Test()
//{
//	int a = 10;
//	return &a;	// 返回局部变量的地址
//}
//
//int main(void)
//{
//	int* pa = Test();
//	printf("%d\n", *pa);
//	printf("haha\n");		// 先打印haha的话就看不到10了，printf()函数的栈帧覆盖了原来的pa
//	return 0;
//}

//void GetMemory(char** p, int num)
//{
//	*p = (char*)malloc(num);
//}
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(&str, 100);
//	strcpy(str, "hello");
//	printf(str);
//}
//void Test(void)
//{
//	char* str = (char*)malloc(100);
//	strcpy(str, "hello");
//	free(str);
//
//	if (str != NULL)
//	{
//		strcpy(str, "world");
//		printf(str);
//	}
//}
//int main(void)
//{
//	Test();  
//	return 0;
//}
//
//int globalVar = 1;
//static int staticGlobalVar = 2;
//
//void test()
//{
//	static int staticVar = 3;
//
//	int localVar = 4;
//	int num1[5] = { 1,2,3,4,5 };
//	char str[] = "abcd";
//	char* ps = "abcd";
//
//	int* ptr1 = (int*)malloc(sizeof(int) * 4);
//	int* ptr2 = (int*)calloc(4, sizeof(int));
//	int* ptr3 = (int*)realloc(ptr2, sizeof(int) * 8);
//
//	free(ptr1);
//	free(ptr3);
//}
////
//struct S
//{
//	char c;
//	int i;
//	int arr[];	//柔性数组成员
//};
//int main()
//{
//	struct S* ps = (struct S*)malloc(sizeof(struct S)+20);
//	if (ps == NULL)
//	{
//		perror("malloc");
//		exit(-1);
//	}
//	ps->c = 'c';
//	ps->i = 100;
//	int i = 0;
//	for (i = 0; i < 5; i++)
//	{
//		ps->arr[i] = i;
//	}
//	struct S* ptr = (struct S*)realloc(ps,sizeof(struct S)+40);
//	if (ptr == NULL)
//	{
//		perror("realloc");
//		exit(-1);
//	}
//	else 
//	{
//		ps = ptr;
//	}
//	free(ps);
//	ps = NULL;
//
//
//	return 0;
//}

//typedef struct st_type
//{
//	int i;
//	int a[];	//柔性数组成员
//}type_a;
//int main()
//{
//	type_a s;
//	printf("%d", sizeof(s));
//	return 0;
//}
//struct st_type
//{
//	int i;
//	int a[0];	//柔性数组成员
//};
//int main()
//{
//	// 1.开辟空间
//	struct st_type* ps = (struct st_type*)malloc(sizeof(struct st_type) + 10 * sizeof(int));//40
//	if (NULL == ps)
//	{
//		perror("fail malloc");
//		return 1;
//	}
//
//	// 2.初始化空间
//	ps->i = 1;
//	for (int i = 0; i < 10; i++)
//	{
//		ps->a[i] = i;
//	}
//
//	// 3.打印
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", ps->a[i]);
//	}
//
//	struct st_type* tmp = (struct st_type*)realloc(ps, sizeof(struct st_type) + 20 * sizeof(int));
//	if (NULL == tmp)
//	{
//		perror("fail realloc");
//		exit(-1);
//	}
//	else 
//	{
//		ps = tmp;
//	}
//
//	// 2.初始化空间
//	for (int i = 10; i < 20; i++)
//	{
//		ps->a[i] = 'W';
//	}
//
//	for (int i = 10; i < 20; i++)
//	{
//		printf("%c ", ps->a[i]);
//	}
//
//
//	// 4.释放
//	free(ps);
//	ps = NULL;
//
//	return 0;
//}
#include <stdio.h>
#include <stdlib.h>

struct st_type
{
    int i;
    int* a;    //柔性数组成员
};

int main()
{
    // 1.开辟空间
    struct st_type* s = (struct st_type*)malloc(sizeof(struct st_type)); // 分配结构体空间
    if (NULL == s)
    {
        perror("fail malloc");
        return 1;
    }

    s->a = (int*)malloc(sizeof(int) * 10); // 为柔性数组成员分配内存空间
    if (NULL == s->a)
    {
        perror("fail malloc");
        free(s);
        return 1;
    }

    s->i = 100;
    for (int i = 0; i < 10; i++)
    {
        s->a[i] = i;
    }

    // 3.打印
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", s->a[i]);
    }

    // 4.增加
    int* tmp = (int*)realloc(s->a, sizeof(int) * 20); // 使用原指针进行扩展内存空间
    if (NULL == tmp)
    {
        perror("fail malloc");
        free(s->a);
        free(s);
        return 1;
    }
    else
    {
        s->a = tmp;
    }

    free(s->a);
    free(s);
    return 0;
}