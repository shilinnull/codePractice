#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
//int main()
//{
//	int a[3][4], (*p)[4] = a;
//	printf("%d", *(*p + 1));
//	return 0;
//}

//int main()
//{
//	int a, b, c, num;
//	scanf("%d", &num);
//	a = num % 10;
//	b = num / 10 % 10;
//	c = num / 100 % 10;
//	if ((a + b + c) == 7)
//	{
//		printf("%d", num);
//	}
//	
//}

//int main()
//{
//	int a[4][4] = { 23,44,12,77,13,2,33,12,23,45,12,65,11,9,15,78 };
//	int max = a[0][0];
//	int x, y;
//	for (int i = 0; i < 4; i++)
//	{
//		for (int j = 0; j < 4; j++)
//		{
//			if (a[i][j] > max)
//			{
//				max = a[i][j];
//				x = i;
//				y = j;
//			}
//		}
//	}
//	printf("%d %d %d",max, x, y);
//	return 0;
//}
//
//int main()
//{
//	char a[80];
//	scanf("%s", a);
//	for (int i = 0; a[i] != '\0'; i++)
//	{
//		if (a[i] <= 'z' && a[i] >= 'a')
//		{
//			a[i] -= 32;
//		}
//	}
//	printf("%s", a);
//
//	return 0;
//}

//int main()
//{
//	/*int a[3][4], (*p)[4] = a;
//	*(*p + 1);*/
//	/*int i = 5, k;
//	k = (++i) + (++i) + (i++);*/
//	//printf("%d %d ", k, i);
//	/*float a = .235f;*/
//
//	int x = 100, a = 0, b = 0;
//	switch (x)
//	{
//	case 0:a--; break;
//	case 1:b--; break;
//	case 2:a++;b--; break;
//	case 100:a++;b--;
//	default:a--; b--;
//	}
//	printf("%d%d", --a, b++);
//	return 0;
//}

#include<stdio.h>

//int f(int n)
//{
//	if (n > 2)
//		return (f(n - 1) + f(n - 2));
//	else
//		return 2;
//}
//#include<stdlib.h>
//
//void func(char para[100])
//{
//	void* p = malloc(100);
//	printf("%d, %d\n", sizeof(para), sizeof(p));
//}
//
//int main()
//{
//	//1
//	//int k = 100;
//	//while (k = 100)
//	//{
//	//	k++;
//	//}
//
//	
//	////2
//	//int k = 100;
//
//	//while (k == 100)
//	//{
//	//	k++;
//	//}
//
//
//	//int value = 1024;
//	//char condition = *((char*)(&value));
//	//if (condition) value += 1; condition = *((char*)(&value));
//	//if (condition) value += 1; condition = *((char*)(&value));
//	//printf("%d %d", value, condition);
//
//
//	return 0;
//}

//#include <stdio.h>
//void func(char* p) { 
//	p = p + 1; 
//}
//int main()
//{
//	char s[] = { '1', '2', '3', '4' };
//	func(s);
//	printf("%c", *s);
//	return 0;
//}

//#include <stdio.h>
//void fun(char** p)
//{
//	int i;
//	for (i = 0; i < 4; i++)
//		printf("%s", p[i]);
//}
//int main()
//{
//	char* s[6] = { "ABCD", "EFGH", "IJKL", "MNOP", "QRST", "UVWX" };
//	fun(s);
//	printf("\n");
//	return 0;
//}

//int main()
//{
//	int* k[10][30];
//	printf("%d\n", sizeof(k));
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	static char* s[] = { "black", "white", "pink", "violet" };
//	char** ptr[] = { s + 3, s + 2, s + 1, s }, *** p;
//	p = ptr;
//	++p;
//	printf("%s", **p + 1);
//	return 0;
//}
//#include <stdio.h>
//int main()
//{
//	char* str[3] = { "stra", "strb", "strc" };
//	char* p = str[0];
//	int i = 0;
//	while (i < 3)
//	{
//		printf("%s ", p++);
//		i++;
//	}
//	return 0;
//}
//#include <stdio.h>
//int main() {
//	int m[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
//	int(*p)[4] = (int(*)[4])m;
//	printf("%d", p[1][2]);
//	return 0;
//}
//#include <stdio.h>
//void func(char* p) { 
//	p = p+1; 
//}
//int main()
//{
//	char s[] = { '1', '2', '3', '4' };
//	func(s);
//	printf("%c", *s);
//	return 0;
//}

//int main()
//{
//	int* k[10][30];
//	printf("%d\n", sizeof(k));
//	return 0;
//}

//void f(int** p)
//{
//
//}
//
//int main()
//{
//	int a[4] = { 1,2,3,4 };
//	int b[3][4] = { {1,2,3,4},{5,6,7,8},{9,10,11,12} };
//	int* q[3] = { b[0],b[1],b[2] }; // 函数指针类型
//
//	f(q);
//
//	return 0;
//}

//int main()
//{
//	char* p = (char*)malloc(sizeof(char));
//	//p = getchar();
//	//scanf("%s", p);
//	//char s[] = "china";
//	*p = "china";
//	printf("%s", *p);
//	return 0;
//}

//char fun(char* p)
//{
//
//}
//int main()
//{
//	char* s = "one", a[5] = { 0 }, (*f1)(char*) = fun, ch;
//
//	//*f1(&a);
//	//f1(*s);
//	f1(&ch);
//	// ch = *f1(s)要改成(*f1)(s)才正确
//	return 0;
//}

//#include <stdio.h>
//int main() {
//	int m[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
//	int(*p)[4] = (int(*)[4])m;
//	printf("%d", p[1][2]);
//	return 0;
//}

//int main()
//{
//	char p1[15] = "abcd", * p2 = "ABCD", str[50] = "xyz";
//	strcpy(str + 2, strcat(p1 + 2, p2 + 1));// xy cdBCD
//
//	printf("%s", str);
//	return 0;
//}
//#include<stdio.h>
//void f(char* str, char ch)
//{
//	char* it1 = str;
//	char* it2 = str;
//	while (*it2 != '\0')
//	{
//		while (*it2 == ch)
//		{
//			it2++;
//		}
//		*it1++ = *it2++;
//	}
//	//*it1 = '\0';
//}
//int main() {
//	char a[10] = "abcdcccd";
//	//strcpy(a, "abcdcccd");
//	f(a, 'c');
//	printf("%s", a);
//	return 0;
//}

//char* replaceSpaces(char* S, int length) {
//    char* cur = S;
//    int count = 0;
//    while (*cur != '\0') {
//        if (*cur == ' ')
//            count++;
//        cur++;
//    }
//    int end1 = length - 1;
//    int end2 = length + count * 2 - 1;
//    while (end1 != end2) {
//        if (S[end1] != ' ') {
//            S[end2--] = S[end1--];
//        }
//        else {
//            S[end2--] = '0';
//            S[end2--] = '2';
//            S[end2--] = '%';
//            --end1;
//        }
//    }
//    S[length + count * 2] = '\0';
//
//    return S;
//}


//int main()
//{
//	char arr[2][4];
//	strcpy(arr[0], "you");
//	strcpy(arr[1], "me");
//	arr[0][3] = '&';
//	printf("%s \n", arr);
//	return 0;
//}

//char* replaceSpaces(char* S, int length) {
//    char* cur = S;
//    int count1 = 0;
//    int count2 = 0;
//    //这个肯定是不能这么写的，一定是会越界的，因为空出来的位置也是空格
//    // while (*cur != '\0') {
//    //     if (*cur == ' ')
//    //         count++;
//    //     cur++;
//    // }
//
//    // count1是空格的个数,count2是字符的个数
//    int len = length;
//    while (len--)
//    {
//        if (*cur == ' ')
//            count1++;
//        else
//            count2++;
//        cur++;
//    }
//
//    int end1 = length - 1;
//
//    // 字符的个数加上 空格的个数*3-1
//    int end2 = count2 + 3 * count1 - 1;
//
//    while (end1 >= 0) {
//        if (S[end1] != ' ') {
//            S[end2--] = S[end1--];
//        }
//        else {
//            S[end2--] = '0';
//            S[end2--] = '2';
//            S[end2--] = '%';
//            --end1;
//        }
//    }
//
//    S[count2 + 3 * count1] = '\0';
//
//    return S;
//}
//
//
//int main()
//{
//    char arr[50] = "Mr John Smith    ";
//    printf("%s",replaceSpaces(arr, 13));
//    return 0;
//}
//
//int itoa(char* str, int num) {//简单的一个数字转字符串函数，将转换后的数字字符串放到str空间中
//	char tmp[16] = { 0 };
//	int count = 0;
//	while (num) {
//		tmp[count++] = (num % 10) + '0';//将个位数字转换为对应数字字符放到tmp空间中（逆序的）
//		num /= 10;
//	}
//	for (int i = 0; i < count; i++) {
//		str[i] = tmp[count - i - 1]; //逆序将数字字符放入传入的str空间中
//	}
//	return count;//返回转换的数字字符串长度
//}
//char* compressString(char* S) {
//	int len = strlen(S);
//	//申请新的空间，注意空间有可能所需会变大，比如abc -> a1b1c1
//	char* newstr = (char*)calloc(len, 3);
//	int pos = 0;
//	char* s = S;
//	while (*s != '\0') {
//		char* n = s + 1;
//		while (*n != '\0' && *n == *s) n++;//走到下一个不同字符处停下
//		int l = n - s;//相同字符的长度
//		newstr[pos++] = *s;// 先赋值对应字符
//		pos += itoa(newstr + pos, l);//编写了一个数字转字符函数，将数字放到字符串空间指定位置
//		s = n;//下一个不同的字符处
//	}
//	return strlen(newstr) >= len ? S : newstr;
//}

//int exchangeBits(int num) {
//	int b1 = num & 0xaaaaaaaa; 
//	// 10101010101010101010101010101010
//	// 00000000000000000000000000000010
//	// --------------------------------
//	// 01010101010101010101010101010101
//	// 10101010101010101010101010101010
//
//	int b2 = num & 0x55555555; 
//
//	// 01010101010101010101010101010101 
//	// 00000000000000000000000000000010
//	// --------------------------------
//	// 10101010101010101010101010101010
//	// 01010101010101010101010101010100
//	// 10101010101010101010101010101010
//	// 00000000000000000000000000000001;
//	// 分别右移，左移
//	b1 >>= 1;
//	b2 <<= 1;
//	// 合并
//	return b1 | b2;
//}
//
//int Add(int x, int y)
//{
//	return x * y;
//}
//int main()
//{
//	int (*pf)(int, int) = Add;
//
//	for (int i = 1; i < 10; i++)
//	{
//		for (int j = 1; j <= i; j++)
//		{
//			//printf("%d*%d=%d ",j,i,(*pf)(i, j));
//			printf("%d*%d=%d ",j,i,pf(i, j));
//		}
//		printf("\n");
//	}
//	return 0;
//}
//#include <stdio.h>
//typedef struct List_t
//{
//	struct List_t* next;
//	struct List_t* prev;
//	char data[0];
//}list_t;
//int main()
//{
//	printf("%d", sizeof(list_t));
//	return 0;
//}

//#include<stdio.h>
//void fut(int** s, int p[2][3])
//{
//	**s = p[1][1];
//}
//int main()
//{
//	int a[2][3] = { 1,3,5,7,9,11 }, * p;
//	p = (int*)malloc(sizeof(int));
//	fut(&p, a);
//	printf("%d", *p);
//	return 0;
//}

//#include<string.h>
//
//int main()
//{
//	char arr[10] = { 0 };
//	scanf("%s", arr);
//
//	int len = strlen(arr);
//	int cur = 0, prev = len - 1;
//	int flag = 0;
//	while (cur != prev)
//	{
//		if (arr[cur] == arr[prev])
//		{
//			++cur;
//			--prev;
//			flag = 1;
//		}
//		else
//		{
//			break;
//		}
//	}
//	if(flag)
//		printf("Yes\n");
//	else
//		printf("No\n");
//
//	return 0;
//}

//int main()
//{
//	char arr[] = "abcdef";
//	printf("%zd", strlen(arr));
//	return 0;
//}

//int Add(int x, int y)
//{
//	return x + y;
//}
//
//int Sub(int x, int y)
//{
//	return x - y;
//}
//
//int main()
//{
//	int(* pfArr[5])(int,int) = {&Add,&Sub};
//
//	
//	return 0;
//}

//#include <stdio.h>
//
//menu()
//{
//	printf("*************************\n");
//	printf("********1:add 2:sub****** \n");
//	printf("********3:mul 4:div******\n");
//	printf("********0:exit     ******\n");
//	printf("*************************\n");
//}
//
//int add(int a, int b)
//{
//	return a + b;
//}
//int sub(int a, int b)
//{
//	return a - b;
//}
//int mul(int a, int b)
//{
//	return a * b;
//}
//int div(int a, int b)
//{
//	return a / b;
//}
//
//void calc(int (*pf)(int, int))
//{
//	int ret, x, y;
//	printf("输入操作数：");
//	scanf("%d %d", &x, &y);
//	ret = (*pf)(x, y);
//	printf("ret = %d\n", ret);
//}
//
//int main()
//{
//	int input = 1;
//	do
//	{
//		menu();
//		printf("请选择：");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			calc(add);
//			break;
//		case 2:
//			calc(sub);
//			break;
//		case 3:
//			calc(mul);
//			break;
//		case 4:
//			calc(div);
//			break;
//		case 0:
//			printf("退出程序\n");
//			break;
//		default:
//			printf("选择错误\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}

//void test(const char* str)
//{
//	printf("%s\n", str);
//}
//int main()
//{
//	//函数指针pfun
//	void (*pfun)(const char*) = test;
//	//函数指针的数组pfunArr
//	void (*pfunArr[5])(const char* str);
//	pfunArr[0] = test;
//	//指向函数指针数组pfunArr的指针ppfunArr
//	void (*(*ppfunArr)[5])(const char*) = &pfunArr;
//	return 0;
//}

//int trailingZeroes(int n) {
//    // n的阶乘
//    unsigned long long sum = 1;
//    int i = 0;
//    for (i = 1; i <= n; i++) {
//        sum *= i;
//    }
//    // 看尾数有几个0
//    int count = 0;
//    while (sum % 10 == 0) {
//        if (sum % 10 == 0) {
//            count++;
//        }
//           sum /= 10;
//    }
//    return count;
//}
//int main()
//{
//    printf("%d", trailingZeroes(30));
//    return 0;
//}



//#include <stdio.h>
//
//int main() {
//    int n = 0;
//    double e = 1.0;
//    double term = 1.0;
//
//    while (term > 1e-6) {
//        n++;
//        term /= n;
//        e += term;
//    }
//
//    printf("e = %lf\n", e);
//
//    return 0;
//}
#include<stdlib.h>
#include<string.h>

//int cmp(const void* e1, const void* e2)
//{
//	return *(int*)e1 - *(int*)e2;
//}
//
//
//struct Stu
//{
//	char name[20];
//	int age;
//};
//
//int stu_cmp_by_name(const void* e1, const void* e2)
//{
//	return strcmp(((struct Stu*)e1)->name,((struct Stu*)e2)->name);
//}
//
//int stu_cmp_by_age(const void* e1, const void* e2)
//{
//	return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
//}
//
//int main()
//{
//	struct Stu s[] = { {"zhangsan",20 },{"lisi",18},{"wangwu",30} };
//
//	qsort(s, sizeof(s) / sizeof(s[0]), sizeof(s[0]), stu_cmp_by_age);
//
//	for (int i = 0; i < sizeof(s) / sizeof(s[0]); i++)
//	{
//		printf("%s %d\n", s[i].name, s[i].age);
//	}
//
//	return 0;
//}

//int main()
//{
//	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
//	qsort(arr, 10, sizeof(arr[0]), cmp);
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//void print_arr(int arr[], int sz)	
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}
//
//void Swap(char* buf1, char* buf2, size_t size)
//{
//	for (int i = 0; i < size; i++)
//	{
//		char tmp = *buf1;
//		*buf1 = *buf2;
//		*buf2 = tmp;
//		++buf1;
//		++buf2;
//	}
//}
//
//int cmp_int(const void* e1, const void* e2)
//{
//	return *(int*)e1 - *(int*)e2;
//}
//
//void my_bubble_qsort(void* base, size_t num, size_t size, int(*cmp)(const void* e1, const void* e2))
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < num - 1; i++)
//	{
//		for (j = 0; j < num - i - 1; j++)
//		{
//			// 返回了大于0的数就交换
//			if (cmp((char*)base + j * size, (char*)base + (j + 1) * size) > 0)
//			{
//				Swap((char*)base + j * size, (char*)base + (j + 1) * size, size);
//			}
//		}
//	}
//}
//
//
//int main()
//{
//	int arr[] = { 3,2,5,6,8,7,9,1,4,0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	my_bubble_qsort(arr, sz, sizeof(arr[0]), cmp_int);
//	print_arr(arr, sz);
//	return 0;
//}

//#include<stdio.h>
//#define Mul(x,y) ++x*++y
//int main()
//{
//	int a = 1;
//	int b = 2;
//	int c = 3;
//	printf("%d", Mul(a + b, b + c));
//	return 0;
//}

//int main()
//{
//	char str[] = "abc\\\n\101\x102";
//	printf("%d",sizeof(str));
//	return 0;
//}

//int main()
//{
//	int a[5] = { 1, 2, 3, 4, 5 };
//	int* ptr = (int*)(&a + 1);
//	printf("%d,%d", *(a + 1), *(ptr - 1));
//	return 0;
//}

////由于还没学习结构体，这里告知结构体的大小是20个字节
////x86环境下
//struct Test
//{
//	int Num;
//	char* pcName;
//	short sDate;
//	char cha[2];
//	short sBa[4];
//}*p;
////假设p 的值为0x100000。 如下表表达式的值分别为多少？
////已知，结构体Test类型的变量大小是20个字节
//int main()
//{
//	p = (struct Test*)0x100000;
//	printf("%p\n", p + 0x1);
//	printf("%p\n", (unsigned long)p + 0x1);
//	printf("%p\n", (unsigned int*)p + 0x1);
//	return 0;
//}

//int main()
//{
//	int a[4] = { 1, 2, 3, 4 };
//	int* ptr1 = (int*)(&a + 1);
//	int* ptr2 = (int*)((int)a + 1);
//	printf("%x,%x", ptr1[-1], *ptr2);
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int a[3][2] = { (0, 1), (2, 3), (4, 5) };
//	int* p;
//	p = a[0];
//	printf("%d", p[0]);
//	return 0;
//}

//int main()
//{
//	int a[5][5];
//	int(*p)[4];
//	p = a;
//	printf("%p,%d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);
//	return 0;
//}

//int main()
//{
//	int aa[2][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int* ptr1 = (int*)(&aa + 1);
//	int* ptr2 = (int*)(*(aa + 1));
//	printf("%d,%d", *(ptr1 - 1), *(ptr2 - 1));
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	char* a[] = { "work","at","alibaba" };
//	char** pa = a;
//	pa++;
//	printf("%s\n", *pa);
//	return 0;
//}

int main()
{
	/*char* c[] = { "ENTER","NEW","POINT","FIRST" };
	char** cp[] = { c + 3,c + 2,c + 1,c };
	char*** cpp = cp;
	printf("%s\n", **++cpp);
	printf("%s\n", *-- * ++cpp + 3);
	printf("%s\n", *cpp[-2] + 3);
	printf("%s\n", cpp[-1][-1] + 1);*/
	
	char a = 101;
	int sum = 200;
	a += 27; sum += a;
	printf("%d\n", sum);
	return 0;
}
