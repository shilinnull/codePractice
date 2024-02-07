#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

//int main()
//{
//	int a = 5;
//	int b = 2;
//	int c = a / b;
//	printf("%d", c);
//	return 0;
//}

//int main()
//{
//	//float a = 5;
//	//float b = 2.0f;
//	//float c = a / b;
//	//printf("%.2f\n", c);
//
//	int a = 2;
//	int b = 5;
//	int c = b % a;
//	printf("%d", c);
//	return 0;
//}

//int main()
//{
//	int a = 4;
//	//0 0000000000000000000000000000100 - 4的原码
//	//0 0000000000000000000000000000100 - 4的反码
//	//0 0000000000000000000000000000100 - 4的补码
//
//	int b = a << 1;		//把a向左移动一位
//	printf("a = %d, b = %d\n", a, b);
//	return 0;
//}
//
//int main()
//{
//	int a = -4;
//	//1 0000000000000000000000000000100 - -4的原码
//	//1 1111111111111111111111111111011 - -4的反码
//	//1 1111111111111111111111111111100 - -4的补码
//
//	int b = a << 1;		//把a向左移动一位
//
//	//1 1111111111111111111111111111000 - -4移位后的的补码
//	//1 1111111111111111111111111110111 - -4移位后的的反码
//	//1 0000000000000000000000000001000 - -4移位后的的原码
//	printf("a = %d, b = %d\n", a, b);
//	return 0;
//}

//
//int main()
//{
//	int a = 4;
//	//0 0000000000000000000000000000100 - 4的原码
//	//0 0000000000000000000000000000100 - 4的反码
//	//0 0000000000000000000000000000100 - 4的补码
//
//	int b = a >> 1;		//把a向右移动一位
//	printf("a = %d, b = %d\n", a, b);
//	return 0;
//}


//int main()
//{
//	int a = -4;
//	//1 0000000000000000000000000000100 - -4的原码
//	//1 1111111111111111111111111111011 - -4的反码
//	//1 1111111111111111111111111111100 - -4的补码
//
//	int b = a >> 1;		//把a向右移动一位
//	//1 1111111111111111111111111111110 - -4移位后的补码
//	//1 1111111111111111111111111111101 - -4移位后的反码
//	//1 0000000000000000000000000000010 - -4移位后的反码
//
//	printf("a = %d, b = %d\n", a, b);
//	return 0;
//}

//int main()
//{
//	int a = 3;
//	int b = -5;
//	int c = a & b;
//	printf("c = %d\n", c);
//	//00000000000000000000000000000011 - 3的原码、反码、补码
//
//	//10000000000000000000000000000101 - -5的原码
//	//11111111111111111111111111111010 - -5的反码
//	//11111111111111111111111111111011 - -5的补码
//
//	//00000000000000000000000000000011
//	//11111111111111111111111111111011
//	//00000000000000000000000000000011 - 3【补码即为原码】
//	return 0;
//}


//int main()
//{
//	int a = 3;
//	int b = -5;
//	int c = a | b;
//	printf("c = %d\n", c);
//	//00000000000000000000000000000011 - 3的原码、反码、补码
//
//	//10000000000000000000000000000101 - -5的原码
//	//11111111111111111111111111111010 - -5的反码
//	//11111111111111111111111111111011 - -5的补码
//
//	//00000000000000000000000000000011
//	//11111111111111111111111111111011
//// --------------------------------------
//	//11111111111111111111111111111011 |
//	//11111111111111111111111111111010 |
//	//10000000000000000000000000000101 | - 5
//	return 0;
//}


//int main()
//{
//	int a = 3;
//	int b = -5;
//	int c = a ^ b;
//	printf("c = %d\n", c);
//	//00000000000000000000000000000011 - 3的原码、反码、补码
//
//	//10000000000000000000000000000101 - -5的原码
//	//11111111111111111111111111111010 - -5的反码
//	//11111111111111111111111111111011 - -5的补码
//
//	//00000000000000000000000000000011
//	//11111111111111111111111111111011
//// --------------------------------------
//	//11111111111111111111111111111000
//	//11111111111111111111111111110111
//	//10000000000000000000000000001000 -> -8
//	return 0;
//}


//int main()
//{
//	int a = 0;
//	int b = ~a;
//	printf("b = %d\n", b);
//
//	//00000000000000000000000000000000
//	//11111111111111111111111111111111  按位取反【补码】	
//	//11111111111111111111111111111110	【反码】
//	//10000000000000000000000000000001 -> -1【原码】
//	return 0;
//}

//int main()
//{
//	int a = 3;
//	int b = 5;
//	printf("a = %d, b = %d\n", a, b);
//
//	a = a + b;
//	b = a - b;		//a + b - b
//	a = a - b;		//a + b - a
//
//	printf("a = %d, b = %d\n", a, b);
//	return 0;
//}
//
//int main()
//{
//	int a = 3;
//	int b = 5;
//	printf("a = %d, b = %d\n", a, b);
//
//	a = a ^ b;
//	b = a ^ b;		//a ^ b ^ b = a ^ 0 = a
//	a = a ^ b;		//a ^ b ^ a = b ^ 0 = b
//
//	printf("a = %d, b = %d\n", a, b);
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	a = a | 1 << 4;
//	printf("a = %d\n", a);
//	return 0;
//}
//
//int main()
//{
//	int a = 10;
//	int n = 0;
//
//	while (scanf("%d", &n)!=EOF)
//	{
//		a = a | 1 << (n - 1);
//		//把变量a的第n为置1
//		//000000000000000000001010
//		//000000000000000000010000
//	//--------------------------------
//		//000000000000000000001110
//		printf("置1：a = %d\n", a);
//
//
//		a = a & ~(1 << (n - 1));
//		//把变量a的第n为置0
//		//000000000000000000001110
//		//111111111111111111111011
//	//--------------------------------
//		//000000000000000000001010
//		printf("置0：a = %d\n", a);
//	}
//	
//	return 0;
//}

//int main()
//{
//	//int a = 10;
//	//int b = a += 10;
//	//printf("a = %d\n", a);
//	//printf("b = %d\n", b);
//	int a = 10;
//	a += 10;
//	printf("a = %d\n", a);
//
//	a <<= 1;//扩大两倍
//	printf("a = %d", a);
//
//	return 0;
//}
//
//int main()
//{
//	int flag = 0;
//	if (!flag)
//	{
//		printf("haha\n");
//	}
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	//char ch = 'q';
//	//printf("&a = %p\n", &a);
//
//	//printf("a = %p\n", &a);
//	//printf("ch = %p\n", &ch);
//	int* pa = &a;
//	//int ret = *pa;
//	pa = 20;
//	printf("pa = %p\n", pa);
//
//	return 0;
//}

//int main()
//{
//	*(int*)0x0012f40 = 100;
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	int* p;
//	int arr[10];
//
//	printf("%zu\n", sizeof(a));			//int 4
//	printf("%zu\n", sizeof(p));			//int 4
//	printf("%zu\n", sizeof(arr));		//特殊，计算的是整个数组的大小
//	printf("%zu\n", sizeof(arr[0]));	//int [10] 40
//	printf("%zu\n", sizeof(arr[10]));	//int 4
//	return 0;
//}

//int main()
//{
//	int a = 0;
//	printf("%d\n", sizeof a);
//	printf("%d\n", sizeof(a));
//	return 0;
//}


//int main()
//{
//	short s = 10;
//	int a = 2;
//
//	s = a + 5;
//	printf("%d", s);
//
//	//printf("%d\n", sizeof(s = a + 2));
//	//printf("%d\n", s);
//
//	return 0;
//}


//#include <stdio.h>
//void test1(int arr[])
//{
//	printf("%d\n", sizeof(arr));//4
//}
//
//void test2(char ch[])
//{
//	printf("%d\n", sizeof(ch));//1
//}
//
//int main()
//{
//	int arr[10] = { 0 };
//	char ch[10] = { 0 };
//	printf("%d\n", sizeof(arr)); //40
//	printf("%d\n", sizeof(ch));//10
//	test1(arr);
//	test2(ch);
//	return 0;
//}

//int main()
//{
//	//int a = 10;
//	//int b = ++a;
//	////a = a + 1; b = a;
//
//	//printf("a = %d, b = %d\n", a, b);
//
//
//	//int a = 10;
//	//int b = a++;
//	////b = a; a = a + 1; 
//
//	//printf("a = %d, b = %d\n", a, b);
//
//
//	//int a = 10;
//	//int b = --a;
//	////a = a - 1; b = a;
//	//printf("a = %d, b = %d\n", a, b);
//
//
//
//	int a = 10;
//	int b = a--;
//	b = a; a = a - 1; 
//
//	printf("a = %d, b = %d\n", a, b);
//	return 0;
//}

//int main()
//{
//	int a = (int)3.14;
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//    //int i = 0, a = 0, b = 2, c = 3, d = 4;
//    //i = a++ && ++b && d++;
//
//    //int i = 0, a = 1, b = 2, c = 3, d = 4;
//    //i = a++ && ++b && d++;
//
//    //int i = 0, a = 0, b = 2, c = 3, d = 4;
//    //i = a++ || ++b || d++;
//
//    int i = 0, a = 1, b = 2, c = 3, d = 4;
//    i = a++ || ++b || d++;
//
//    printf("a = %d\nb = %d\nc = %d\nd = %d\n", a, b, c, d);
//    printf("------\n");
//    printf("i = %d\n", i);
//    return 0;
//}

//
//int main()
//{
//	int a = 5;
//	int b = 0;
//
//	//if (5 == a)
//	//	b = 3;
//	//else
//	//	b = -3;
//
//	b = (5 == a) ? 3 : -3;
//
//	printf("a = %d\n", a);
//	printf("b = %d\n", b);
//	return 0;
//}

//int main()
//{
//	int arr[] = { 1,2,3,4,5 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", i[arr]);
//	}
//	return 0;
//}
//
//typedef struct book {
//	char writer[20];
//	double price;
//}st;
//
//
//
//int main()
//{
//	st s1 = { "罗曼·罗兰", 50 };
//
//	st* ps = &s1;
//
//	printf("name = %s\n", ps->writer);	//结构体指针->结构体成员名
//	printf("price = %f\n", ps->price);
//
//	//printf("name = %s\n", (*ps).writer);
//	//printf("name = %s\n", s1.writer);
//	//printf("price = %f\n", s1.price);  //结构体变量.结构体成员名
//	return 0;
//}

//int main()
//{
//	char a = 0xb6;
//	short b = 0xb600;
//	int c = 0xb6000000;
//	if (a == 0xb6)
//		printf("a");
//	if (b == 0xb600)
//		printf("b");
//	if (c == 0xb6000000)
//		printf("c");
//	return 0;
//}
//
//int main()
//{
//	//char c = 1;
//	//printf("%u\n", sizeof(c));
//	//printf("%u\n", sizeof(c + 1));
//	//printf("%u\n", sizeof(+c));
//	//printf("%u\n", sizeof(-c));
//
//	char c = 1;
//	printf("%u\n", sizeof(c + 1));
//	printf("%u\n", sizeof(+c));
//
//	printf("-------------------\n");
//	printf("%u\n", sizeof(c = c + 1));
//	printf("%u\n", sizeof(++c));
//
//	return 0;
//}

//int main()
//{
//	float f = 3.14;
//	int num = f;//隐式转换，会有精度丢失
//
//	printf("%d\n", num);
//	return 0;
//}

//int fun()
//{
//    static int count = 1;
//    return ++count;
//}
//int main()
//{
//    int answer;
//    answer = fun() - fun() * fun();
//    printf("%d\n", answer);//输出多少？
//    return 0;
//}

#include <stdio.h>
int main()
{
	int i = 1;
	int ret = (++i) + (++i) + (++i);
	printf("%d\n", ret);
	printf("%d\n", i);
	return 0;
}