#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

//int main() {
//	const int n = 100;
//
//	const int* p = &n;
//	int* const p = &n;
//	*p = 200;
//
//	printf("%d\n", n);
//	return 0;
//}
//
//int main() {
//	int m = 100;
//	int n = 10;
//
//	int* const p = &n;
//	*p = 0;
//
//	p = &m;
//
//	printf("%d\n", n);
//	return 0;
//}

//#include <stdlib.h>
//#include <stdio.h>
//int main() {
//    int x = 0;
//    int y = 0;
//    scanf("%d", &x);
//    if (x >= 0) {
//        y = x;
//    }
//    else {
//        y = -x;
//    }
//
//    printf("%d", y);
//    return 0;
//}

//#include <stdio.h>
////指针+- 整数
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int* p = &arr[0];
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", *(p + i));//p+i 这里就是指针+整数
//	}
//	return 0;
//}

//指针-指针
//#include <stdio.h>
//int my_strlen(char* s)
//{
//	char* p = s;
//	while (*p != '\0')
//		p++;
//	return p - s;
//}
//int main()
//{
//	printf("%d\n", my_strlen("abc"));
//	return 0;
//}

//int main() {
//	int arr[10] = { 0 };
//	int ret = &arr[9] - &arr[0];
//
//	printf("%d", ret);
//
//	return 0;
// }
//
//int my_strlen(char* p)
//{
//	int count = 0;
//	while (*p != '\0')
//	{
//		count++;
//		p++;
//	}
//	return count;
//}
//
//
//int main() 
//{
//	char arr[] = "abcdef";
//	int len = my_strlen(arr);
//
//	printf("%d\n", len);
//
//	return 0;
//}

//#include <stdio.h>
//int my_strlen(char* s)
//{
//	char* p = s;
//	while (*p != '\0')
//		p++;
//	return p - s;
//}
//int main()
//{
//	printf("%d\n", my_strlen("abcdef"));
//	return 0;
//}

//指针的关系运算
//#include <stdio.h>
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int* p = &arr[0];
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	while (p < arr + sz) //指针的大小比较
//	{
//		printf("%d ", *p);
//		p++;
//	}
//	return 0;
//}


//#include <stdio.h>
//int main()
//{
//	int* p;//局部变量指针未初始化，默认为随机值
//	*p = 20;
//	return 0;
//}
//
//#include <stdio.h>
//int main()
//{
//	int arr[10] = { 0 };
//	int* p = &arr[0];
//	int i = 0;
//	for (i = 0; i <= 11; i++)
//	{
//		//当指针指向的范围超出数组arr的范围时，p就是野指针
//		*(p++) = i;
//	}
//	return 0;
//}

#include <stdio.h>
int* test()
{
	int n = 100;
	return &n;
}
int main()
{
	int* p = test();
	printf("%d\n", *p);
	return 0;
}