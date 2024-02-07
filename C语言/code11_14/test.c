#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>


//int main()
//{
//	char arr1[3] = { 'a', 'b', 'c' };
//	char arr2[] = "abc";
//	printf("%d\n", strlen(arr1));
//	printf("%d\n", strlen(arr2));
//	printf("%d\n", sizeof(arr1));
//	printf("%d\n", sizeof(arr1));
//	return 0;
//}

//int main()
//{
//	//char arr2[] = "ab\0c";
//
//	//char arr1[] = { 'a', 'b', 'c' };
//	//printf("%d\n", strlen(arr1));
//
//	short s = 10;
//	int i = 2;
//	int n = sizeof(s = i + 4);
//	printf("%d\n", n);
//	printf("%d\n", s);
//
//	return 0;
//}

//int main()
//{
//	int a[] = { 1,2,3,4 };
//	printf("%d\n", sizeof(a));
//	printf("%d\n", sizeof(a + 0));
//	printf("%d\n", sizeof(*a));
//	printf("%d\n", sizeof(a + 1));
//	printf("%d\n", sizeof(a[1]));
//	printf("%d\n", sizeof(&a));
//	printf("%d\n", sizeof(*&a));
//	printf("%d\n", sizeof(&a + 1));
//	printf("%d\n", sizeof(&a[0]));
//	printf("%d\n", sizeof(&a[0] + 1));
//	return 0;
//}


//字符数组

//int main()
//{
//	char arr[] = { 'a','b','c','d','e','f' };
//	printf("%d\n", sizeof(arr));
//	printf("%d\n", sizeof(arr + 0));
//	printf("%d\n", sizeof(*arr));
//	printf("%d\n", sizeof(arr[1]));
//	printf("%d\n", sizeof(&arr));
//	printf("%d\n", sizeof(&arr + 1));
//	printf("%d\n", sizeof(&arr[0] + 1));
//
//	return 0;
//}



//---------------------------------------------------------------------------------------
//
//数组名的理解：
//数组名是数组首元素的地址
//但是有2个例外：
//&数组名
//sizeof(数组名)
//
//int main()
//{
//	char arr[] = { 'a','b','c','d','e','f' };
//
//	printf("%d\n", sizeof(arr));//6
//	printf("%d\n", sizeof(arr + 0));//4/8  地址
//	printf("%d\n", sizeof(*arr));//1
//	printf("%d\n", sizeof(arr[1]));//1
//	printf("%d\n", sizeof(&arr));//4/8
//	printf("%d\n", sizeof(&arr + 1));//4/8
//	printf("%d\n", sizeof(&arr[0] + 1));//4/8
//
//
//	return 0;
//}
//

#include <string.h>

//
//int main()
//{
//	char arr[] = { 'a','b','c','d','e','f' };
//	printf("%d\n", strlen(arr));
//	printf("%d\n", strlen(arr + 0));
//	//printf("%d\n", strlen(*arr));
//	//printf("%d\n", strlen(arr[1]));
//	printf("%d\n", strlen(&arr));
//	printf("%d\n", strlen(&arr + 1));
//	printf("%d\n", strlen(&arr[0] + 1));
//	return 0;
//}


//int main()
//{
//	char arr[] = "abcdef";
//	printf("%d\n", sizeof(arr));
//	printf("%d\n", sizeof(arr + 0));
//	printf("%d\n", sizeof(*arr));
//	printf("%d\n", sizeof(arr[1]));
//	printf("%d\n", sizeof(&arr));
//	printf("%d\n", sizeof(&arr + 1));
//	printf("%d\n", sizeof(&arr[0] + 1));
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//
//int main()
//{
//	char arr[] = "abcdef";
//	printf("%d\n", strlen(arr));
//	printf("%d\n", strlen(arr + 0));
//	//printf("%d\n", strlen(*arr));
//	//printf("%d\n", strlen(arr[1]));
//	printf("%d\n", strlen(&arr));
//	printf("%d\n", strlen(&arr + 1));
//	printf("%d\n", strlen(&arr[0] + 1));
//	return 0;
//}

//
//int main()
//{
//	char* p = "abcdef";
//	printf("%d\n", sizeof(p));
//	printf("%d\n", sizeof(p + 1)); 
//	printf("%d\n", sizeof(*p));
//	printf("%d\n", sizeof(p[0]));
//	printf("%d\n", sizeof(&p));
//	printf("%d\n", sizeof(&p + 1));
//	printf("%d\n", sizeof(&p[0] + 1));
//	return 0;
//}


//
//int main()
//{
//	char* p = "abcdef";
//	printf("%d\n", strlen(p));
//	printf("%d\n", strlen(p + 1));
//	//printf("%d\n", strlen(*p));
//	//printf("%d\n", strlen(p[0]));
//	printf("%d\n", strlen(&p));
//	printf("%d\n", strlen(&p + 1));
//	printf("%d\n", strlen(&p[0] + 1));
//
//	return 0;
//}

//
//int main()
//{
//	int a[3][4] = { 0 };
//	printf("%d\n", sizeof(a));//计算的是整个二维数组的大小，单位是字节-48
//	printf("%d\n", sizeof(a[0][0]));//a[0][0]是第一行第一个元素，大小是4个字节
//	printf("%d\n", sizeof(a[0]));//16 - a[0]其实就是第一行的数组名
//	//这里第一行的数组名单独放在sizeof内部了，计算的是第一行的大小
//
//	printf("%d\n", sizeof(a[0] + 1));//
//	//a[0]是第一行这个数组的数组名，但是数组名并非单独放在sizeof内部，所以数组名表示数组首元素的
//	//地址，也就是a[0][0]的地址，a[0]+1是第一行第二个元素（a[0][1]）的地址
//	//地址的大小是4/8个字节
//	printf("%d\n", sizeof(*(a[0] + 1)));//a[0] + 1是第一行第二个元素（a[0][1]）的地址
//	//*(a[0] + 1)就是第一行第二个元素，大小是4个字节
//	printf("%d\n", sizeof(a + 1));//
//	//a 没有单独放在sizeof内部，没有&，数组名a就是数组首元素的地址，也就是第一行的地址
//	//a+1,就是第二行的地址
//	//a -- int(*)[4]
//	//a+1 -- int(*)[4]
//	printf("%d\n", sizeof(*(a + 1)));//16
//	printf("%d\n", sizeof(a[1]));//16
//	//*(a + 1) --> a[1]
//	printf("%d\n", sizeof(&a[0] + 1));//4/8
//	//a[0]是第一行的数组名，&a[0]取出的是第一行的地址，&a[0]+1得到的就是第二行的地址
//	//&a[0]+1
//	//a+1
//	printf("%d\n", sizeof(*(&a[0] + 1)));//16
//	printf("%d\n", sizeof(*a));//16-数组名a就是数组首元素的地址，也就是第一行的地址,*a就是一行的
//	//*a == *(a+0) == a[0]
//	printf("%d\n", sizeof(a[3]));//16
//	//a[3] -- arr[0]
//	//
//	return 0;
//}
//-----------------------------------------------------------------------------------------------------
//
//#include <stdio.h>
//int main()
//{
//	int a[5] = { 1, 2, 3, 4, 5 };
//
//	int* ptr = (int*)(&a + 1);
//	printf("%d, %d", *(a + 1), *(ptr - 1));
//
//	return 0;
//}
//

//在X86环境下
//假设结构体的⼤⼩是20个字节
//程序输出的结构是啥？
//指针运算中的指针+-整数
//struct Test
//{
//	int Num;
//	char* pcName;
//	short sDate;
//	char cha[2];
//	short sBa[4];
//} * p = (struct Test*)0x100000;
//
//int main()
//{
//	printf("%p\n", p + 0x1);//+1到底+几？//0x00100014
//	
//	printf("%p\n", (unsigned long)p + 0x1);//0x00100001
//	printf("%p\n", (unsigned int*)p + 0x1);//0x00100004
//
//	return 0;
//}

//后期再讲
//#include <stdio.h>
//
//int main()
//{
//	int a[4] = { 1, 2, 3, 4 };
//
//	int* ptr1 = (int*)(&a + 1);
//	int* ptr2 = (int*)((int)a + 1);
//	printf("%x,%x", ptr1[-1], *ptr2);
//	return 0;
//}
//

//#include <stdio.h>
//int main()
//{
//	int a[3][2] = { (0, 1), (2, 3), (4, 5) };
//	// 1 3
//	// 5 0 
//	// 0 0
//	int* p;
//	p = a[0];
//	printf("%d", p[0]);
//
//	return 0;
//}

//假设环境是x86环境，程序输出的结果是啥？
//#include <stdio.h>
//int main()
//{
//	int a[5][5];
//	int(*p)[4];
//	p = a;
//	printf("%p,%d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);
//
//	return 0;
//}
//

//#include <stdio.h>
//int main()
//{
//	int aa[2][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int* ptr1 = (int*)(&aa + 1);
//	int* ptr2 = (int*)(*(aa + 1));
//	printf("%d,%d", *(ptr1 - 1), *(ptr2 - 1));
//
//	return 0;
//}


//#include <stdio.h>
//
//int main()
//{
//	char* a[] = { "work","at","alibaba" };
//	char** pa = a;
//	pa++;
//	printf("%s\n", *pa);
//	return 0;
//}
//

//
//#include <stdio.h>
//
//int main()
//{
//	char* c[] = { "ENTER","NEW","POINT","FIRST" };
//	char** cp[] = { c + 3,c + 2,c + 1,c };
//	char*** cpp = cp;
//
//	printf("%s\n", **++cpp);
//	printf("%s\n", *-- * ++cpp + 3);
//	printf("%s\n", *cpp[-2] + 3);
//	printf("%s\n", cpp[-1][-1] + 1);
//
//	return 0;
//}




















