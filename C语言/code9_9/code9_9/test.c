#define _CRT_SECURE_NO_WARNINGS 1


#include<stdio.h>
//void ADD(int* p)
//{
//	*p = *p + 1;
//}
//
//int main()
//{
//	int num = 0;
//	ADD(&num);
//	printf("%d", num);
//	return 0;
//}
//
void ADD(int* p)
{
	(*p)++;
}

//int main()
//{
//	int num = 0;
//	for (int i = 0; i < 10; i++)
//	{
//		ADD(&num);
//	}
//	printf("%d", num);
//	return 0;
//}
//
/*
实现一个函数，打印乘法口诀表，口诀表的行数和列数自己指定

如：输入9，输出9*9口诀表，输出12，输出12*12的乘法口诀表。
*/
//
//void mt(int n)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 1; i <= n; i++)
//	{
//		for (j = 1; j <= i; j++)
//		{
//			printf("%d*%d=%-2d ", j, i, j * i);
//		}
//		printf("\n");
//	}
//}
//int main()
//{
//	int k = 0;
//	while (scanf("%d", &k) != EOF)
//	{
//		mt(k);
//	}
//	return 0;
//}

//实现一个函数来交换两个整数的内容。
//
//void Swap(int *x, int *y)
//{
//	int tmp = *x;
//	*x = *y;
//	*y = tmp;
//}
//
//int main()
//{
//	int n = 10;
//	int m = 20;
//	Swap(&n, &m);
//	printf("n = %d m = %d\n", n, m);
//	return 0;
//}

//现函数判断year是不是润年。
//
//int is_leap_year(int y)
//{
//	if ((y % 4 == 0) && (y % 100 != 0) || (y % 400 == 0))
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}
//int main()
//{
//	int y = 0;
//	int count = 0;//计数
//	for (int y = 1000; y <= 2000; y++)
//	{
//		if (is_leap_year(y))
//		{
//			printf("%d ", y);
//			count++;
//		}
//	}
//	printf("\ncount = %d\n", count);
//	return 0;
//}



/*
实现一个函数is_prime，判断一个数是不是素数。

利用上面实现的is_prime函数，打印100到200之间的素数。
*/
//#include<stdio.h>
//#include<math.h>
//#include<stdbool.h>
//bool is_prime(int n)
//{
//	int j = 0;
//	for (j = 2; j <= sqrt(n); j++)
//	{
//		if (n % j == 0)
//		{
//			return false;
//		}
//	}
//	return true;
//}
//
//int main()
//{
//	int i = 0;
//	int count = 0;//计数
//	for (i = 101; i <= 200; i+=2)
//	{
//		if (is_prime(i))
//		{
//			count++;
//			printf("%d ", i);
//		}
//	}
//	printf("\ncount = %d\n", count);
//	return 0;
//}
//
//
//void bubble_sort(int arr[],const int sz)
//{
//	for (int i = 0; i <= sz ; i++)
//	{
//		for (int j = 0; j <= sz - 1 - i; j++)
//		{
//			if (arr[j] < arr[j - 1])
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j - 1];
//				arr[j - 1] = tmp;
//			}
//		}
//	}
//}
//
//void print(int arr[], int sz)
//{
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}
//int main()
//{
//	int arr[] = { 10,9,8,7,6,5,4,3,2,1 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	bubble_sort(arr, sz);
//	print(arr, sz);
//	return 0;
//}

//
//int main()
//{
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[] = { 2,3,4,5,6 };
//	int arr3[] = { 3,4,5,6,7 };
//
//	int* p[] = { arr1,arr2,arr3 };
//
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 5; j++)
//		{
//			printf("%d ", p[i][j]);
//		}
//		printf("\n");
//	}
//
//	return 0;
//}

//struct Stu
//{
//	char name[20];
//	int age;
//	char sex[5];
//	char tele[12];
//}s3,s4;

//
//typedef struct B
//{
//	int n;
//	char wen;
//}B;
//
//
//typedef struct A
//{
//	char name[20];
//	int age;
//	char sex[5];
//	char tele[12];
//	struct B* p;
//	struct B pp;
//} A;

//
//int main()
//{
//	//struct Stu s1 = { "zhangsan","18","男",112212121211 };
//	//struct Stu s2 = { "lisi","25","女",343434343434 };
//	//Stu s4 = { "zhangsan","18","男","112212121211"};
//	//int b = 10;
//	//char d = 'v';
//
//	//struct A s1 = { "zhangsan",18,"男",111111111111,&b };
//	//struct A s2 = { .name = {1313} };
//
//
//
//	return 0;
//}
#include<string.h>
//struct S
//{
//	char nane[10];
//	int tele;
//};

//void set_s(struct S t)
//{
//	//t.nane = "张三";
//	strcpy(t.nane, "张三");
//	t.tele = 1212121212;
//}

//void set_s(struct S *ps)
//{
//	//t.nane = "张三";
//	strcpy((*ps).nane, "张三");
//	(*ps).tele = 1212121212;
//}
//
//void set_s(struct S *ps)
//{
//	//t.nane = "张三";
//	strcpy(ps->nane, "张三");
//	ps->tele = 1212121212;
//}
//
//void print_s(struct S t)
//{
//	printf("%s %d", t.nane, t.tele);
//}
//
//int main()
//{
//	struct S s = { 0 };
//	set_s(&s);
//	print_s(s);
//	return 0;
//}
//


//int main()
//{
//	char arr2[] = "hello word";
//	char arr1[] = "*************";
//	strcpy(arr1, arr2);
//	printf("%s", arr1);
//	return 0;
//}
//#include<assert.h>
//void my_strcpy(char* dest, char* src)
//{
//	assert(dest && src);
//	while (*dest++ = *src++);
//}
//
//int main()
//{
//	char arr2[] = "hello word";
//	char arr1[] = "***********";
//	my_strcpy(arr1, arr2);
//	printf("%s", arr1);
//	//strcpy(arr1, arr2);
//	return 0;
//}
//
//#include<assert.h>
//char* my_strcpy(char* dest, char* src)
//{
//	char* ret = dest;
//	assert(dest && src);
//	while (*dest++ = *src++);
//	return ret;
//}
//
//int main()
//{
//	char arr2[] = "hello word";
//	char arr1[] = "***********";
//	printf("%s", my_strcpy(arr1, arr2));
//	//strcpy(arr1, arr2);
//	return 0;
//}

//
//#include<assert.h>
//size_t my_strlen(const char* src){
//	assert(src);
//	size_t count = 0;
//	while (*src++){
//		count++;
//	}
//	return count;
//}
//
//int main(){
//	char arr[] = "abcdef";
//	size_t len = my_strlen(arr);
//	printf("%zd\n", len);
//	return 0;
//}

//int Fun(int n)
//{
//    if (n == 5)
//        return 2;
//    else
//        return 2 * Fun(n + 1);
//}


//计算斐波那契数
//
//long long Func(int n)
//{
//	if (n < 3)
//		return 1;
//	return Func(n - 1) + Func(n - 2);
//}
//
//int main()
//{
//	int n = 0;
//	while (scanf("%d", &n) != EOF)
//	{
//		long long ret = Func(n);
//		printf("第%d个斐波那契数是%lld\n", n , ret);
//	}
//	
//	return 0;
//}

#include<math.h>
#include<stdio.h>
Func(int n, int k)
{
	if (k == 0)
	{
		return 1;
	}
	else if (k >= 1)
	{
		return n * pow(n, k - 1);
	}
}
int main()
{
	int n = 0;
	int k = 0;
	while (scanf("%d %d", &n,&k) != EOF)
	{
		long long ret = Func(n,k);
		printf("%d的%d次方是%lld\n", n ,k , ret);
	}
	
	return 0;
}