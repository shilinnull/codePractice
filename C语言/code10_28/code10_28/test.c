#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>





//int main() 
//{
//	int a = 10;
//	int* p = &a;
//	int* ptr = NULL;
//	*ptr = 100;
//	return 0;
//}

//int main()
//{
//	int arr[10] = { 1,2,3,4,5,67,7,8,9,10 };
//	int* p = &arr[0];
//	for (int i = 0; i < 10; i++)
//	{
//		*(p++) = i;
//	}
//	//此时p已经越界了，可以把p置为NULL
//	p = NULL;
//	//下次使用的时候，判断p不为NULL的时候再使用
//	//...
//	p = &arr[0];//重新让p获得地址
//	if (p != NULL) //判断
//	{
//		//...
//	}
//	return 0;
//}

//int* test()
//{
//	//局部变量
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	//.....
//	return arr;
//}
//
//int main()
//{
//	int* p = test();//p就是野指针
//	return 0;
//}
//
//#define NDEBUG
//#include <assert.h>
//
//int main()
//{
//	int a = 10;
//	int* p = NULL;
//	assert(p != NULL);
//	return 0;
//}



//#include <stdio.h>
//void Swap1(int x, int y)
//{
//	int tmp = x;
//	x = y;
//	y = tmp;
//}
//
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	printf("交换前：a=%d b=%d\n", a, b);
//	Swap1(a, b);
//	printf("交换后：a=%d b=%d\n", a, b);
//	return 0;
//}

//#include <stdio.h>
//void Swap2(int* px, int* py)
//{
//	int tmp = 0;
//	tmp = *px;
//	*px = *py;
//	*py = tmp;
//}
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	printf("交换前：a=%d b=%d\n", a, b);
//	Swap2(&a, &b);
//	printf("交换后：a=%d b=%d\n", a, b);
//	return 0;
//}

//计数器方式
//size_t my_strlen(const char* str)
//{
//	size_t count = 0;
//	assert(str);
//	while (*str)
//	{
//		count++;
//		str++;
//	}
//	return count;
//}
//int main()
//{
//	char arr[] = "abcdef";
//	size_t len = my_strlen(arr);
//	printf("%d\n", len);
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	printf("&arr[0] = %p\n", &arr[0]);
//	printf("arr = %p\n", arr);
//	return 0;
//}
//


//#include <stdio.h>
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	printf("%d\n", sizeof(arr));
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	printf("&arr[0] = %p\n", &arr[0]);
//	printf("arr     = %p\n", arr);
//	printf("&arr    = %p\n", &arr);
//	return 0;
//}


//#include <stdio.h>
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	printf("&arr[0]   = %p\n", &arr[0]);
//	printf("&arr[0]+1 = %p\n", &arr[0] + 1);
//	printf("arr       = %p\n", arr);
//	printf("arr+1     = %p\n", arr + 1);
//	printf("&arr      = %p\n", &arr);
//	printf("&arr+1    = %p\n", &arr + 1);
//	return 0;
//}

//
//#include <stdio.h>
//int main()
//{
//	int arr[10] = { 0 };
//	//输入
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	//输入
//	int* p = arr;
//	for (i = 0; i < sz; i++)
//	{
//		scanf("%d", p + i);
//		//scanf("%d", arr+i);//也可以这样写
//	}
//	//输出
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//	return 0;
//}


//#include <stdio.h>
//int main()
//{
//	int arr[10] = { 0 };
//	//输入
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	//输入
//	int* p = arr;
//	for (i = 0; i < sz; i++)
//	{
//		scanf("%d", p + i);
//		//scanf("%d", arr+i);//也可以这样写
//	}
//	//输出
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", p[i]);
//	}
//	return 0;
//}

//int main() {
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int* p = arr;
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (i = 0; i < sz; i++) {
//		printf("%p ======== %p\n", p + i, &arr[i]);
//	}
//	return 0;
//}

//#include <stdio.h>
//void test(int arr[])
//{
//	int sz2 = sizeof(arr) / sizeof(arr[0]);
//	printf("sz2 = %d\n", sz2);
//}
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz1 = sizeof(arr) / sizeof(arr[0]);
//	printf("sz1 = %d\n", sz1);
//	test(arr);
//	return 0;
//}


//void test1(int arr[])//参数写成数组形式，本质上还是指针
//{
//	printf("%d\n", sizeof(arr));
//}
//void test2(int* arr)//参数写成指针形式
//{
//	printf("%d\n", sizeof(arr));//计算一个指针变量的大小
//}
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	test1(arr);
//	test2	(arr);
//	return 0;
//}


void sort(int arr[], int sz) {
	//确定冒泡排序的趟数~~
	int i = 0;
	for (i = 0; i < sz - 1; i++) {
		//一趟冒泡排序
		int j = 0;
		int flag = 1;//假设数组是有序的
		for (j = 0; j < sz - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				//交换
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				flag = 0;//不是有序
			}
		}
		if (flag = 1) {
			break;
		}
	}
}

void print(int arr[], int sz) {
	int i = 0;
	for (i = 0; i < sz; i++) {
		printf("%d ", arr[i]);
	}
}

int main() {
	//int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
	int arr[] = { 9,0,1,2,3,4,5,6,7,8 };
	//进行排序
	int sz = sizeof(arr) / sizeof(arr[0]);

	sort(arr,sz);
	print(arr, sz);
	return 0;
}