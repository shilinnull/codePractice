#define _CRT_SECURE_NO_WARNINGS 1


#include<stdio.h>
//int check_sys()
//{
//	int a = 1;
//	return (char*)&a;
//}
//
//int main()
//{
//	if (check_sys())
//		printf("С��");
//	else
//		printf("���");
//	return 0;
//}
//
//#include<windows.h>
//
//int main()
//{
//	//1000001
//	//1111110
//	//1111111
//	//
//	//unsigned char a = -1;
//	//char a = -128;
//	//10000000
//	//01111111
//	//10000000
//	//11111111111111111111111110000000
//	//char a = 128;
//	//10000000
//	//01111111
//	//10000000
//	//11111111111111111111111110000000
//	//printf("%u", a);
//	unsigned int i; 
//	for (i = 9; i >= 0; i--) 
//	{ 
//		printf("%u\n", i); 
//		Sleep(1000);
//	}
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	/*
//	(-1)^S * M * 2^E
//	(-1)^S��ʾ����λ����S=0��VΪ��������S=1��VΪ����
//	��S=1��VΪ������ 
//	M��ʾ��Ч���֣����ڵ���1��С��2�� 2^E��ʾָ��λ��
//	*/
//
//	return 0;
//}



/*
дһ���ݹ麯��DigitSum(n)������һ���Ǹ����������������������֮��

���磬����DigitSum(1729)����Ӧ�÷���1+7+2+9�����ĺ���19

���룺1729�������19


*/
//
//#include<stdio.h>
//int DigitSum(int n)
//{
//	if (n > 9)
//		return DigitSum(n / 10) + (n % 10);
//	return n;
//}
//int main()
//{
//
//	size_t n = 0;
//	scanf("%d", &n);
//	size_t ret = DigitSum(n);
//	printf("%d", ret);
//	return 0;
//}

/*
��дһ������ reverse_string(char * string)���ݹ�ʵ�֣�

ʵ�֣��������ַ����е��ַ��������У����������ӡ��

Ҫ�󣺲���ʹ��C�������е��ַ�������������

����:

char arr[] = "abcdef";


����֮����������ݱ�ɣ�fedcba
*/
//#include<string.h>
//void reverse_string(char* string)
//{
//	char* left = string;
//	char* right = string + strlen(string) - 1;
//	while (left < right)
//	{
//		int tmp = *left;
//		*left = *right;
//		*right = tmp;
//		left++;
//		right--;
//	}
//}
//
//int main()
//{
//	char arr[] = "abcdef";
//	reverse_string(arr);
//	printf("%s", arr);
//	return 0;
//}

//strlen��ģ�⣨�ݹ�ʵ�֣�

//
//
//#include<stdio.h>
//#include<assert.h>
//size_t my_strlen(const char *src)
//{
//	size_t count = 0;
//	assert(src);
//	while (src++)
//	{
//		count++;
//	}
//	return count;
//}
//
//int main()
//{
//	char arr[] = "abcdef";
//	int len = my_strlen(arr);
//	printf("%d\n", len);
//	return 0;
//}




//
//#include<stdio.h>
//
//size_t my_strlen(const char *src)
//{
//	if ('\0' == src)
//		return 0;
//	else
//		return (1 + my_strlen(1 + src));
//}
//
//int main()
//{
//	char arr[] = "abcdef";
//	size_t len = my_strlen(arr);
//	printf("%d\n", len);
//
//	return 0;
//}
//#include<stdio.h>
//
//int Strlen(const char* str)
//{
//	if (*str == '\0')
//		return 0;
//	else
//		return 1 + Strlen(str + 1);
//}
//int main()
//{
//	char* p = "abcdef";
//	int len = Strlen(p);
//	printf("%d\n", len);
//	return 0;
//}
//�ݹ�ͷǵݹ�ֱ�ʵ����n�Ľ׳ˣ���������������⣩

//long long Func(int n)
//{
//	int i = 0;
//	long long ret = 1;
//	for (i = 2; i <= n; i++)
//	{
//		ret *= i;
//	}
//	return ret;
//}
//
//long long Func(int n)
//{
//	if (n <= 1)
//		return 1;
//	else
//		return Func(n - 1) * n;
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	long long ret = Func(n);
//	printf("%d", ret);
//	return 0;
//}

//�ݹ鷽ʽʵ�ִ�ӡһ��������ÿһλ
//void print(int n)
//{
//	if (n > 9)
//		print(n / 10);
//	printf("%d ", n % 10);
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	print(n);
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//    int arr[] = { 1,2,(3,4),5 };
//    printf("%d\n", sizeof(arr));
//    return 0;
//}

#include <stdio.h>
//int main()
//{
//    char str[] = "hello bit";
//    printf("%d %d\n", sizeof(str), strlen(str));
//    return 0;
//}   
//char acX[] = "abcdefg";
//char acY[] = { 'a','b','c','d','e','f','g' };


/*
����һ���������飬��ɶ�����Ĳ���

ʵ�ֺ���init() ��ʼ������Ϊȫ0
ʵ��print()  ��ӡ�����ÿ��Ԫ��
ʵ��reverse()  �����������Ԫ�ص����á�
Ҫ���Լ�������Ϻ����Ĳ���������ֵ��
*/
//#include<stdio.h>
//init(int arr[],int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		arr[i] = 0;
//	}
//}
//int print(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}
//int reverse(int arr[], int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//	while (left < right)
//	{
//		int tmp = arr[left];
//		arr[left] = arr[right];
//		arr[right] = tmp;
//		left++;
//		right--;
//	}
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	print(arr, sz);
//	init(arr,sz);
//	reverse(arr, sz);
//	print(arr, sz);
//	return 0;
//}

//ʵ��һ�������������ð������
//
//void bubble_arr(int arr[], int sz)
//{
//	for (int i = 0; i <= sz; i++)
//	{
//		for (int j = 0; j <= sz - 1 - i; j++)
//		{
//			int tmp = arr[j];
//			arr[j] = arr[j + 1];
//			arr[j + 1] = tmp;
//		}
//	}
//
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
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	bubble_arr(arr, sz - 1);
//	print(arr, sz);
//	return 0;
//}
//
//
//void Swap(int arr1[], int arr2[])
//{
//	for (int i = 0; i < 10; i++)
//	{
//		int tmp = arr1[i];
//		arr1[i] = arr2[i];
//		arr2[i] = tmp;
//	}
//}
//
//print(int arr1[], int arr2[])
//{
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", arr1[i]);
//	}
//	printf("\n");
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", arr2[i]);
//	}
//}
//int main()
//{
//	int arr1[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int arr2[10] = { 2,4,6,8,10,1,3,5,7,9 };
//	Swap(arr1,arr2);
//	print(arr1, arr2);
//	return 0;
//}
//#include <stdio.h>
//int main()
//{
//	int a, b, c;
//	a = 5;
//	c = ++a; // a = 6  c = 6
//	b = ++c, c++, ++a, a++; //c = 8 a = 8  b = 8
//	b += a++ + c;//b = 24 a = 9
//	printf("a = %d b = %d c = %d\n:", a, b, c);
//	return 0;
//}

//����������ʱ������������������������

//int main()
//{
//	int a = 10;
//	int b = 20;
//	a = a ^ b;
//	b = a ^ b;
//	a = a ^ b;
//	printf("a = %d b = %d \n", a, b);
//	return 0;
//}
//#include<stdio.h>
//
//size_t num(size_t n)
//{
//    size_t count = 0;
//    size_t i = 0;
//    for (i = 0; i < 32; i++)
//    {
//        if (((n >> i) & 1) == 1)
//            count++;
//    }
//    return count;
//}
//
//int main()
//{
//    size_t a = 0;
//    scanf("%d", &a);
//    
//        size_t n = num(a);
//        printf("%d\n",n);
//    
//    return 0;
//}

//��ȡһ���������������������е�ż��λ������λ���ֱ��ӡ������������

int main()
{
	int a = 0;
	while (scanf("%d", &a) != EOF)
	{
		for (int i = 1; i <=32; i++)
		{
			printf("%d ", (a >> i) & 1);
		}
		printf("\n");
		for (int i = 1; i <=32; i++)
		{
			printf("%d ", (a >> i) & i);
		}
		printf("\n");

	}
	return 0;
}
