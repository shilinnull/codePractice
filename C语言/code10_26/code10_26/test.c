#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//int main()
//{
//	int a = 100;
//	int* pa = &a;
//	*pa = 0;
//	return 0;
//}

//#include <stdio.h>
////指针变量的大小取决于地址的大小
////32位平台下地址是32个bit位（即4个字节）
////64位平台下地址是64个bit位（即8个字节）
//int main()
//{
//	printf("%zd\n", sizeof(char*));
//	printf("%zd\n", sizeof(short*));
//	printf("%zd\n", sizeof(int*));
//	printf("%zd\n", sizeof(double*));
//	return 0;
//}

#include <stdio.h>
//指针变量的大小取决于地址的大小
//32位平台下地址是32个bit位（即4个字节）
//64位平台下地址是64个bit位（即8个字节）
//int main()
//{
//	int num = 10;
//	int* p = &num;
//	
//	char ch = 'w';
//	char* pc = &ch;
//
//	printf("%zd\n", sizeof(p));
//	printf("%zd\n", sizeof(pc));
//	return 0;
//}




//#include <stdio.h>
//int main()
//{
//	int n = 0x11223344;
//	int* pi = &n;
//	*pi = 0;
//	return 0;
//}
// 
// 
//#include <stdio.h>
//int main()
//{
//	int n = 0x11223344;
//	int* p = &n;
//	char* pc = &n;
//
//	printf("p = %p\n", p);
//	printf("p + 1 = %p\n", p + 1);
//
//	printf("pc = %p\n", pc);
//	printf("pc + 1 = %p\n", pc + 1);
//	return 0;
//}


//int main() {
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	//下标的方式
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	//int i = 0;
//	//for (i = 0; i < sz; i++) {
//	//	printf("%d ", arr[i]);
//	//}
//
//	//指针的方式
//	int i = 0;
//	int* p = &arr[0];
//	for (i = 0; i < sz; i++) {
//		printf("%d ", *(p + i));
//	}
//	return 0;
//}

