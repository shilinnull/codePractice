#define _CRT_SECURE_NO_WARNINGS 1

//
//#include<stdio.h>
//int main()
//{
//	char arr1[20] = "hello ";
//	char arr2[20] = "word";
//	strcat(arr1, arr2);
//	printf("%s\n", arr1);
//	return 0;
//}
#include<stdio.h>
#include<string.h>
#include<assert.h>
//char* my_strcat(char* dest, const char* src)
//{
//	assert(dest && src);
//	char* ret = dest;//保存一下目标字符串的起始地址
//	//1.寻找目标字符串中的\0
//	while (*dest != '\0')
//	{
//		dest++;
//	}
//	//2.从目标字符串的\0开始拷贝源字符串
//	while (*dest++ = *src++)
//	{
//		;
//	}
//	return ret;
//}
//
//int main()
//{
//	char arr1[20] = "abcdef";
//	char arr2[] = "ghi";
//	my_strcat(arr1, arr2);
//	printf("%s\n", arr1);
//	return 0;
//}
//
//int my_strcmp(const char* str1, const char* str2)
//{
//	assert(str1 && str2);
//	while (*str1 == *str2)
//	{
//		if (*str1 == '\0')//二者相同且为'\0'，return 0
//		{
//			return 0;
//		}
//		str1++;
//		str2++;		//否则向后继续查找
//	}
//	return *str1 - *str2;//指针相减等于个数
//}
//
//int main()
//{
//	char arr1[] = "zhangsan";
//	char arr2[] = "zhangsan";
//
//	int ret = my_strcmp(arr1, arr2);
//	if (ret == 1)
//		printf(">\n");
//	else if (ret == -1)
//		printf("<\n");
//	else
//		printf("==\n");
//	return 0;
//}

//int main()
//{
//	char arr[4] = { 0 };
//	strcpy(arr, "abcdef");
//	printf("%s", arr);
//	return 0;
//}
//
//char* my_strncpy(char* dest, const char* src, size_t num)
//{
//	assert(dest && src);
//	char* start = dest;
//	while (num && (*dest++ = *src++))
//	{
//		num--;
//	}
//
//	//若是跳出循环后num > 0，表示num > 原字符串的长度
//	if (num)
//	{
//		while (--num)
//		{
//			*dest++ = '\0';		//再补充num个'\0'
//		}
//	}
//	return start;
//}
//
//int main()
//{
//	char arr1[10] = { 0 };
//	char arr2[] = "hello word!";
//	my_strncpy(arr1, arr2, 5);
//	printf("%s\n", arr1);
//	return 0;
//}
//int main()
//{
//	char arr1[20] = "hello ";
//	char arr2[] = "word !";
//	strncat(arr1, arr2, 5);
//	printf("%s\n", arr1);
//	return 0;
////}
//int main()
//{
//	char arr1[] = "abczef";
//	char arr2[] = "abcd";
//	int ret = strncmp(arr1, arr2, 4);
//	if (ret == 0) {
//		printf("==\n");
//	}
//	else if (ret < 0) {
//		printf("<\n");
//	}
//	else {
//		printf(">\n");
//	}
//	return 0;
//}




//int main()
//{
//	char str1[] = "abcdefabcdef";
//	char str2[] = "deff";
//
//	char* substr = strstr(str1, str2);
//	if (substr == NULL)
//		printf("子串不存在\n");
//	else
//		printf("%s\n", substr);
//	return 0;
//}
//
//int main()
//{
//	char sep[] = "@.";
//	char email[30] = "256652753@qq.com";
//
//	char* ret = strtok(email, sep);
//	if (ret != NULL)
//		printf("%s\n", ret);
//
//	ret = strtok(NULL, sep);
//	if (ret != NULL)
//		printf("%s\n", ret);
//
//	ret = strtok(NULL, sep);
//	if (ret != NULL)
//		printf("%s\n", ret);
//	return 0;
//}

//int main(void)
//{
//	printf("%s\n", strerror(0));
//	printf("%s\n", strerror(1));
//	printf("%s\n", strerror(2));
//	printf("%s\n", strerror(3));
//	printf("%s\n", strerror(4));
//	printf("%s\n", strerror(5));
//	return 0;
//}
//int main()
//{
//	FILE* pf = fopen("test.txt", "r");
//	if (NULL == pf)
//	{
//		printf("%s\n", strerror(errno));
//		return 1;
//	}
//	else {
//		printf("文件打开正常\n");
//	}
//	return 0;
//}
//
//#include <stdio.h>
//#include <ctype.h>
//int main()
//{
//	int i = 0;
//	char str[] = "Test String.\n";
//	char c;
//	while (str[i])
//	{
//		c = str[i];
//		if (isupper(c))
//			c = tolower(c);
//		putchar(c);
//		i++;
//	}
//	return 0;
//}

//int main(void)
//{
//	int arr1[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr1) / sizeof(arr1[0]);
//	int arr2[10] = { 0 };
//
//	memcpy(arr2, arr1, sizeof(int) * sz);
//	return 0;
//}

//int main()
//{
//	float arr1[] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
//	int sz = sizeof(arr1) / sizeof(arr1[0]);
//	float arr2[5] = { 0 };
//
//	memcpy(arr2, arr1, sizeof(int) * sz);
//	return 0;
//}
void* my_memcpy(void* dest, const void* src, int num)
{
	assert(dest && src);
	void* ret = dest;
	while (num--)
	{
		*(char*)dest = *(char*)src;
		dest = (char*)dest + 1;
		src = (char*)src + 1;
	}
	return ret;
}
//int main(void)
//{
//	int arr1[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int arr2[10] = { 0 };
//
//	my_memcpy(arr2, arr1, 20);
//	for (int i = 0; i < 10; ++i)
//	{
//		printf("%d ", arr2[i]);
//	}
//	return 0;
//}

//int main()
//{
//	int arr1[10] = { 1,2,3,4,5,6,7,8,9,10 };
//
//	my_memcpy(arr1 + 2, arr1, 20);
//	for (int i = 0; i < 10; ++i)
//	{
//		printf("%d ", arr1[i]);
//	}
//	return 0;
//}
//
//void* my_mommove(void* dest, const void* src, size_t num)
//{
//	assert(dest && src);
//	char* start = dest;
//	if (dest < src)
//	{
//		//memcpy()的拷贝逻辑
//		while (num--)
//		{
//			*(char*)dest = *(char*)src;
//			dest = (char*)dest + 1;
//			src = (char*)src + 1;
//		}
//	}
//	else	//dest >= src
//	{
//		while (num--)
//		{
//			*((char*)dest + num) = *((char*)src + num);
//		}
//	}
//	return start;
//}
//int main()
//{
//	int arr1[10] = { 1,2,3,4,5,6,7,8,9,10 };
//
//	my_mommove(arr1 + 2, arr1, 20);
//	for (int i = 0; i < 10; ++i)
//	{
//		printf("%d ", arr1[i]);
//	}
//	return 0;
//}

//int main()
//{
//	int arr[10];
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	memset(arr, 1, sizeof(int) * sz);
//	return 0;
//}
//int main()
//{
//	int arr1[10] = { 1,2,3,4,5 };
//	int arr2[10] = { 1,2,3 };
//
//	int ret = memcmp(arr1, arr2, 12);
//	printf("%d\n", ret);
//	return 0;
//}
//struct
//{
//	int a;
//	char b;
//	float c;
//}x;
//struct
//{
//	int a;
//	char b;
//	float c;
//}a[20], * p;
//
//int main()
//{
//	p = &x;
//	return 0;
//}

//struct Node
//{
//	int data;
//	struct Node next;
//};
//typedef struct Node
//{
//	int data;
//	Node* next;
//}Node;
//struct Point {
//	int x;
//	int y;
//};
//struct MyStruct
//{
//	char c;
//	struct Point p;
//	double d;
//	char str[20];
//};
//
//
//int main()
//{
//	struct Point p = { 10, 20 };
//
//	//struct MyStruct ms = { 'c', {40, 80}, 3.14f, "haha" };
//	struct MyStruct ms2 = { .d = 6.28, .str = "abcdef", .c = 'cc' };
//	//printf("%c %d %d %f %s", ms.c, ms.p.x, ms.p.y, ms.d, ms.str);
//	printf("%c %d %d %f %s", ms2.c, ms2.p.x, ms2.p.y, ms2.d, ms2.str);
//	return 0;
//}
//
//struct Stu
//{
//	char name[20];
//	int age;
//};
//
//int main(void)
//{
//	struct Stu s1 = { "zhangsan", 20 };
//	printf("普通形式访问：%s %d\n\n", s1.name, s1.age);
//
//	struct Stu* ss = &s1;
//	printf("指针形式：%s %d\n", ss->name, ss->age);
//
//	return 0;
//}
#include<stddef.h>
#include<stddef.h>
//struct S1
//{
//	char c1;
//	int i;
//	char c2;
//};
//
//struct S2
//{
//	char c1;
//	char c2;
//	int i;
//};
//
//struct S3
//{
//	double d;
//	char c;
//	int i;
//};
//
//
//
//struct S4
//{
//	char c1;
//	struct S3 s3;	//成员变量为另一个结构体
//	double d;
//};
//int main()
//{
//	//printf("%d\n", offsetof(struct S1, c1));
//	//printf("%d\n", offsetof(struct S1, i));
//	//printf("%d\n", offsetof(struct S1, c2));
//
//	//printf("%d\n", sizeof(struct S3));
//	//printf("%d\n", sizeof(struct S1));
//	//printf("%d\n", sizeof(struct S4));
//
//	//printf("%d\n", offsetof(struct S3, d));
//	//printf("%d\n", offsetof(struct S3, c));
//	//printf("%d\n", offsetof(struct S3, i));
//
//	printf("%d\n", offsetof(struct S4, c1));
//	printf("%d\n", offsetof(struct S4, s3));
//	printf("%d\n", offsetof(struct S4, d));
//
//
//	return 0;
//}

////#pragma pack(1)//设置默认对齐数为1
//struct S1
//{
//	char c1;
//	int i;
//	char c2;
//};
////#pragma pack()//取消设置的默认对齐数，还原为默认
//
//int main()
//{
//	//输出的结果是什么？
//	//printf("%d\n", sizeof(struct S1));
//	printf("%d\n", offsetof(struct S1, c1));
//	printf("%d\n", offsetof(struct S1, i));
//	printf("%d\n", offsetof(struct S1, c2));
//	return 0;
//}

//#include <stdio.h>
//union Un
//{
//	short s[7];
//	int n;
//};
//
//
//int main()
//{
//	printf("%d\n", sizeof(union Un));
//	return 0;
//}
//
//typedef struct {
//	int a;
//	char b;
//	short c;
//	short d;
//}AA_t;
//int main()
//{
//	printf("%d\n", sizeof(AA_t));
//	return 0;
//}
//#pragma pack(4)/*编译选项，表示4字节对齐 平台：VS2013。语言：C语言*/
////假设long 是4个字节
//int main(int argc, char* argv[])
//{
//	struct tagTest1
//	{
//		short a;
//		char d;
//		long b;
//		long c;
//	};
//	struct tagTest2
//	{
//		long b;
//		short c;
//		char d;
//		long a;
//	};
//	struct tagTest3
//	{
//		short c;
//		long b;
//		char d;
//		long a;
//	};
//	struct tagTest1 stT1;
//	struct tagTest2 stT2;
//	struct tagTest3 stT3;
//
//	printf("%d %d %d", sizeof(stT1), sizeof(stT2), sizeof(stT3));
//	return 0;
//}
//#include<stdio.h>
//#define MAX_SIZE 2+3
//struct _Record_Struct
//{
//	unsigned char Env_Alarm_ID : 4;
//	unsigned char Para1 : 2;
//	unsigned char state;
//	unsigned char avail : 1;
//}*Env_Alarm_Record;
//struct _Record_Struct* pointer = (struct _Record_Struct*)malloc(sizeof(struct _Record_Struct) * MAX_SIZE);


//struct A
//{
//	int _a : 2;
//	int _b : 5;
//	int _c : 10;
//	int _d : 30;
//};
//
//struct S
//{
//	char a : 3;
//	char b : 4;
//	char c : 5;
//	char d : 4;
//};
//
//int main()
//{
//	struct S s = { 0 };
//	s.a = 10;
//	s.b = 12;
//	s.c = 3;
//	s.d = 4;
//	return 0;
//}


//enum Color {
//	RED = 3,
//	GREEN,
//	BLUE
//};
//int main()
//{
//	GREEN;
//	printf("%d\n", RED);
//	printf("%d\n", GREEN);
//	printf("%d\n", BLUE);
//	return 0;
//}
//
//enum Color {
//	RED = 3,
//	GREEN,
//	BLUE
//};
//int main()
//{
//	enum Color c = RED;
//	enum Color c2 = 3;
//	printf("%d", c2);
//	return 0;
//}
//union Un
//{
//	int i;
//	char c;
//};
//int main()
//{
//
//	union Un un;
//	printf("%p\n", &(un.i));
//	printf("%p\n", &(un.c));
//
//	//un.i = 0x11223344;
//	//un.c = 0x55;
//	//printf("%x\n", un.i);
//}
//
//union Un1
//{
//	char c[5];
//	int i;
//};
//union Un2
//{
//	short c[7];	
//	int i;		
//};
//int main()
//{
//	printf("%zu\n", sizeof(union Un2));
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	union
//	{
//		short k;	// 2/4 = 2
//		char i[2];	// 1/4 = 1
//		// 大小：2
//	}*s, a;
//	s = &a;
//	s->i[0] = 0x39;
//	s->i[1] = 0x38;
//	printf("%x\n", a.k);
//	return 0;
//}

//int check_sys() 
//{
//	union 
//	{
//		char c;
//		int i;
//	}un;
//	un.i = 1;
//	return un.c;
//}
//int main()
//{
//	if (check_sys())
//	{
//		printf("小端\n");
//	}
//	else
//	{
//		printf("大端");
//	}
//	return 0;
//}

//#define MAX_SIZE 2+3
//struct _Record_Struct
//{
//	unsigned char Env_Alarm_ID : 4;
//	unsigned char Para1 : 2;
//	unsigned char state;
//	unsigned char avail : 1;
//}*Env_Alarm_Record;
//int main()
//{
//	struct _Record_Struct* pointer = (struct _Record_Struct*)malloc(sizeof(struct _Record_Struct) * MAX_SIZE);
//	printf("%d", sizeof(Env_Alarm_Record));
//	return 0;
//}
#include<stdio.h>

//enum ENUM_A
//{
//	X1,
//	Y1,
//	Z1 = 255,
//	A1,
//	B1,
//};
//
//int main()
//{
//	enum ENUM_A enumA = Y1;
//	enum ENUM_A enumB = B1;
//	printf("%d %d\n", enumA, enumB);
//	return 0;
//}


//int main()
//{
//	unsigned char puc[4];
//	struct tagPIM
//	{
//		unsigned char ucPim1;
//		unsigned char ucData0 : 1;
//		unsigned char ucData1 : 2;
//		unsigned char ucData2 : 3;
//	}*pstPimData;
//	pstPimData = (struct tagPIM*)puc;
//	memset(puc, 0, 4);
//	pstPimData->ucPim1 = 2;
//	pstPimData->ucData0 = 3;
//	pstPimData->ucData1 = 4;
//	pstPimData->ucData2 = 5;
//	printf("%02x %02x %02x %02x\n", puc[0], puc[1], puc[2], puc[3]);
//	return 0;
//}
//struct A
//{
//	int a;
//	short b;
//	int c;
//	char d;
//};
//
//struct B
//{
//	int a;
//	short b;
//	char c;
//	int d;
//};
//
//int main()
//{
//	printf("%d\n", sizeof(struct A));
//	printf("%d\n", sizeof(struct B));
//	return 0;
//}


//check_sys()
//{
//	union un
//	{
//		char i;
//		int c;
//	}n;
//	n.c = 1;
//	return n.i;
//	
//}
//int main()
//{
//	if (check_sys())
//		printf("小端\n");
//	else
//		printf("大端\n");
//	
//	return 0;
//}
struct gift_list
{
	int stock_number;//库存量
	double price; //定价
	int item_type;//商品类型

	union {
		struct
		{
			char title[20];//书名
			char author[20];//作者
			int num_pages;//⻚数
		}book;
		struct
		{
			char design[30];//设计
		}mug;
		struct
		{
			char design[30];//设计
			int colors;//颜⾊
			int sizes;//尺⼨
		}shirt;
	}item;
};
struct gift_list
{
	//公共属性
	int stock_number;//库存量
	double price; //定价
	int item_type;//商品类型

	//特殊属性
	char title[20];//书名
	char author[20];//作者
	int num_pages;//⻚数

	char design[30];//设计
	int colors;//颜⾊
	int sizes;//尺⼨
};