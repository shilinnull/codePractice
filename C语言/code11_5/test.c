#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>


//void qsort(void* base,
//	size_t num,
//	size_t size,
//	int (*compar)(const void*, const void*));



//int cmp_int(const void* e1, const void* e2)
//{
//	return *(int*)e1 - *(int*)e2;
//}
//
//int main()
//{
//	int arr[] = { 3,2,5,6,8,7,9,1,4 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	qsort(arr, sz, sizeof(arr[0]), cmp_int);
//
//	for (size_t i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//
//	return 0;
//}


struct Stu
{
	char name[20];
	int age;
};


void print_arr(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
}

void Swap(void* p1, void* p2, int size)
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		char tmp = *((char*)p1 + i);
		*((char*)p1 + i) = *((char*)p2 + i);
		*((char*)p2 + i) = tmp;
	}
}

void bubble(void* base, int count, int size, int(*cmp)(void*, void*))
{
	int i = 0;
	int j = 0;
	for (i = 0; i < count - 1; i++)
	{
		for (j = 0; j < count - i - 1; j++)
		{
			if (cmp((char*)base + j * size, (char*)base + (j + 1) * size) > 0)
			{
				Swap((char*)base + j * size, (char*)base + (j + 1) * size, size);
			}
		}
	}
}


int cmp_int(const void* e1,const void* e2)
{
	return *(int*)e1 - *(int*)e2;
}

int cmp_stu_by_age(const void* e1, const void* e2)
{
	return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
}



void test1()
{
	int arr[] = { 3,2,5,6,8,7,9,1,4 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	bubble(arr, sizeof(arr) / sizeof(arr[0]), sizeof(int), cmp_int);
	print_arr(arr,sz);

}

void test2()
{
	struct Stu arr2[] = { {"zhangsan",15},{"lisi",50},{"wangwu",32} };
	int sz = sizeof(arr2) / sizeof(arr2[0]);
	bubble(arr2, sz, sizeof(int), cmp_stu_by_age);

}

int main()
{
	//test1();
	//test2();

	int u = 010, v = 0x10, w = 10;
	printf("%d%d%d", u, v, w);
	return 0;
} 