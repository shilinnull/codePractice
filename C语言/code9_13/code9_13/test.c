#define _CRT_SECURE_NO_WARNINGS 1

//qsort快速排序
//可以排序任意类型的数据
//
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//void print_arr(int arr[], int sz)
//{
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//
//int cmp_int(const void*e1,const void*e2)
//{
//	return *(int*)e1 - *(int*)e2;
//}
//
//test1()
//{
//	int arr[] = { 9,8,7,6,5,4,3,2,1 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	print_arr(arr, sz);
//	qsort(arr, sz, sizeof(arr[0]), cmp_int);
//	print_arr(arr, sz);
//}
//
//struct Stu
//{
//	char name[20];
//	int age;
//};
//
//int cmp_stu_by_age(const char* e1, const char* e2)
//{
//	return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
//}
//
//
//test2()
//{
//	struct Stu arr[] = { {"zhangsan",20},{"lisi",18},{"wangwu",25} };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	qsort(arr, sz, sizeof(arr[0]), cmp_stu_by_age);
//}
//
//
//int cmp_stu_by_name(const char* e1, const char* e2)
//{
//	return strcmp(((struct Stu*)e1)->name,((struct Stu*)e2)->name);
//}
//
//test3()
//{
//	struct Stu arr[] = { {"zhangsan",20},{"lisi",18},{"wangwu",25} };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	qsort(arr, sz, sizeof(arr[0]), cmp_stu_by_name);
//
//}
//int main()
//{
//	//test1();
//	//test2();
//	test3();
//	return 0;
//}





//冒泡排序算法

//
//void bubble_arr(int arr[], int sz)
//{
//	for (int i = 0; i < sz - 1; i++)
//	{
//		for (int j = 0; j < sz - 1 - i; j++)
//		{
//			if (arr[j] < arr[j + 1])//进行比较
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//			}
//		}
//	}
//}
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	bubble_arr(arr, sz);
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//模拟实现qsort函数
//模仿qsort的功能实现一个通用的冒泡排序
#include<stdio.h>
#include<string.h>


//void qsort(void* base, size_t num, size_t width, int(__cdecl* compare)(const void* elem1, const void* elem2));


void bubble_arr(int arr[],int sz)
{
	for (int i = 0; i < sz - 1; i++)
	{
		for (int j = 0; j < sz - 1 - i; j++)
		{
			if (arr[j] < arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}

print_arr(int arr[], int sz)
{
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
}
test1()
{
	int arr[] = { 9,8,7,6,5,4,3,2,1 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	bubble_arr(arr,sz);
	print_arr(arr,sz);

}

struct Stu
{
	int name[20];
	int age;
};

void Swap(char* buf1,char* buf2,size_t size)
{
	for (int i = 0; i < size; i++)
	{
		char tmp = *buf1;
		*buf1 = *buf2;
		*buf2 = tmp;
		buf1++;
		buf2++;
	}
}

void bubble_sort(int* base, size_t num, size_t size, int (*cmp)(const void* e1, const void* e2))
{
	for (int i = 0; i < num - 1; i++)
	{
		for (int j = 0; j < num - 1 - i; j++)
		{
			if (cmp((char*)base + j * size, (char*)base + (j + 1) * size) > 0)
			{
				Swap((char*)base + j * size, (char*)base + (j + 1) * size,size);
			}
		}
	}
}

void cmp_int(const void* e1, const void* e2)
{
	return *(int*)e1 - *(int*)e2;
}

test2()
{
	int arr[] = { 9,8,7,6,5,4,3,2,1 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	bubble_sort(arr, sz,sizeof(arr[0]),cmp_int);
	print_arr(arr, sz);
}

int cmp_stu_by_age(const char* e1,const char *e2)
{
	return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
}

void test3()
{
	struct Stu arr[] = { {"zhangsan",26},{"lisi",90},{"wangwu",50} };
	int sz = sizeof(arr) / sizeof(arr[0]);
	bubble_sort(arr, sz, sizeof(arr[0]), cmp_stu_by_age);

}

int cmp_stu_by_name(const char* e1, const char* e2)
{
	return (strcmp(((struct Stu*)e1)->name,((struct Stu*)e2)->name));
}


void test4()
{
	struct Stu arr[] = { {"zhangsan",26},{"lisi",90},{"wangwu",50} };
	int sz = sizeof(arr) / sizeof(arr[0]);
	bubble_sort(arr, sz, sizeof(arr[0]), cmp_stu_by_name);
}


int main()
{
	//test1();//排序整形

	//test2();//模拟实现排序整形

	//test3();//模拟实现排序结构体(用年龄排序)

	test4();//模拟实现排序结构体(用名字排序)

	return 0;

}
