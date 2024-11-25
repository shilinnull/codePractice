#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

// 使用C语言写⼀个程序打印 1~100之间的奇数，要求输出的数字中间加上空格
#if 0
int main()
{
	int i = 0;
	for (int i = 1; i <= 100; i++)
	{
		if (i % 2 == 1)
			printf("%d ", i);
	}

	return 0;
}


// 使⽤C语⾔写⼀个程序打印9*9乘法⼝诀表

int main()
{
	for (size_t i = 1; i <= 9; i++)
	{
		for (size_t j = 1; j <= i; j++)
		{
			printf("%d*%d=%d ", j, i, i * j);
		}
		printf("\n");
	}

	return 0;
}


// 使⽤C语⾔写⼀个程序打印100~200之间的素数，数字中间使⽤空格分割。
#include <math.h>
int main()
{
	for (size_t i = 101; i <= 200; i += 2)
	{
		int flag = 1;
		for (size_t j = 2; j <= sqrt(i); j++)
		{
			if (i % j == 0)
			{
				flag = 0;
				break;
			}
		}
		if (flag)
			printf("%d ", i);
	}
	return 0;
}


// 输⼊三个整数a,b,c，判断由a,b,c作为三条边组成的三⻆形，
// 如果不能组成三⻆形则输出：⾮三⻆ 形；如果是三⻆形，再继续判断，
// 如果是等边三⻆形，则输出：等边三⻆形；如果是等腰三⻆形，则 输出：等腰三⻆形；否则输出普通三⻆形

int main()
{
	int a, b, c;
	while (~scanf("%d %d %d", &a, &b, &c))
	{
		if (a + b < c || a + c < b || b + c < a)
		{
			printf("非三角形\n");
		}
		else
		{
			if (a == b && b == c)
			{
				printf("等边三角形\n");
			}
			else if ((a == b && a != c) || (b == c && a != b))
			{
				printf("等腰三角形\n");
			}
			else
			{
				printf("普通三角形\n");
			}
		}
	}
	return 0;
}

// 输⼊2个整数m和n，计算m和n的最⼤公约数，并打印出结果
#include <stdbool.h>
int main()
{
#if 0
	int n, m;
	scanf("%d %d", &m, &n);
	int k = n < m ? m : n;
	while (true)
	{
		// 每次拿k试除m和n，如果不能同时整除，则k--，继续试除
		if (n % k == 0 && m % k == 0)
		{
			break;
		}
		k--;
	}
	printf("%d\n", k);
#endif
	int n, m;
	scanf("%d %d", &m, &n);
	int k = n < m ? m : n;

	while (k = m % n)
	{
		m = n;
		n = k;
	}
	printf("%d\n", k);

	return 0;
}


// 统计二进制1的个数
int main()
{
	int n = 10;
	int count = 0;
	while (n)
	{
		n = n & (n - 1);
		count++;
	}
	printf("%d\n", count);
	return 0;
}


// 判断一个数是否为2的次方
int main()
{
	int n = 16;

	if ((n & (n - 1)) == 0)
	{
		printf("yes\n");
	}

	return 0;
}



int main()
{
	int n = 13;
	int m = 5;

	n |= (1 << (m - 1)); // 将第m位置为1
	printf("%d\n", n);

	n &= ~(1 << (m - 1)); // 将第m位置为0
	printf("%d\n", n);

	return 0;
}





int main()
{
	//int i = 10;

	//i = i-- - --i * (i = -3) * i++ + ++i;
	//printf("%d\n", i);
	int k = 0;
	while (k = 1)
	{
		k = k - 1;
	}
	return 0;
}


#include <stdio.h>
int main()
{
	int a, b, c;
	a = 5;
	c = ++a; // c = 6
	b = ++c, c++, ++a, a++; // b = 7 c = 7 a = 6 a = 7
	b += a++ + c; // a = 8 + 7 
	printf("a = %d b = %d c = %d\n:", a, b, c);
	return 0;
}



#include <stdio.h>

int main()
{
	//printf("%5d\n", 123456);
	char a = 'ab';
	printf("%d", a);
	return 0;
}


int main()
{
	double sum = 0.0;
	for (size_t i = 1; i < 100; i++)
	{
		if (i % 2 == 1)
			sum += 1.0 / i;
		if (i % 2 == 0)
			sum -= 1.0 / i;
	}
	printf("%lf", sum);
	return 0;
}



// 冒泡排序
int main()
{
	int arr[10] = { 0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	for (size_t i = 0; i < sz; i++)
	{
		scanf("%d", &arr[i]);
	}

	for (size_t i = 0; i < sz - 1; i++)
	{
		for (size_t j = 0; j < j - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
	for (size_t i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}



// 计算自幂数
#include<math.h>
int main()
{
	for (size_t i = 1; i <= 100000; i++)
	{
		// 计算位数
		int count = 1;
		int tmp = i;
		while (tmp / 10)
		{
			count++;
			tmp /= 10;
		}

		tmp = i;
		int sum = 0;
		while (tmp)
		{
			sum += (int)pow(tmp % 10, count); // 加上每一位
			tmp /= 10;
		}

		if (sum == i)
			printf("%d ", i);
	}

	return 0;
}

#include <math.h>
int main()
{
	//int a = 0;
	//char ch = 'A';
	//ch+++a;
	//printf("%c\n", ch++);
	//printf("%d\n", a);
	//int a = 6, b = 4;
	//int c = ++a+b%a+++b;
	//printf("%d", c);

	float a = 0.1;
	float b = 0.2;
	float c = 0.3;
	if (a + b == c)
		printf("yes\n");
	else
		printf("NO\n");
	return 0;
}




typedef struct stu
{
	int data;
	struct stu* next;
}Stu;

int main()
{
	auto i = 1;
	printf("%d", i);

	return 0;
}


int main()
{
	int a = 6, b;
	b = a << 2;
	//00011000
	printf("%d\n", b);
	return 0;
}



int main()
{
	int a = 1;
	if ((char)a == 0)
		printf("大端\n");
	else
		printf("小端\n");

	return 0;
}




int main()
{
	int a[10] = { 10 * 2,10 };

	printf("%d", &a[9] - a + 1);
	return 0;
}



#include <stdio.h>
#include <windows.h>
int main()
{
	FILE* pf = fopen("data.txt", "w");
	fputs("abcdef", pf);
	Sleep(10000);

	//fflush(pf);

	//fclose(pf);
	pf = NULL;

	return 0;
}


/*写一个二分查找函数

功能：在一个升序数组中查找指定的数值，找到了就返回下标，找不到就返回 - 1.

int bin_search(int arr[], int left, int right, int key)
// arr 是查找的数组
//left 数组的左下标
//right 数组的右下标
//key 要查找的数字
*/

int bin_search(int arr[], int left, int right, int key)
{
	while (left < right)
	{
		int mid = left + (right + left) / 2;
		if (arr[mid] < key)
		{
			left = mid + 1;
		}
		else if (arr[mid] > key)
		{
			right = mid - 1;
		}
		else
			return mid;
	}
	return -1;
}



int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int n = bin_search(arr, 0, sizeof(arr) / sizeof(arr[0]), 3);
	if (-1 == n)
	{
		printf("找不到\n");
	}
	else
	{
		printf("下标为%d", n);
	}
	return 0;
}



#include<string.h>

int main()
{
	char a[7] = "abcdef";
	char b[4] = "ABC";
	strcpy(a, b);
	printf("%s ", a);
	return 0;

}



void fun(char* s[], int n)
{
	char* t;
	int i, j;
	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (strlen(s[i]) > strlen(s[j]))
			{
				t = s[i];
				s[i] = s[j];
				s[j] = t;

			}
		}
	}
}

int main()
{
	char* ss[] = { "bcc","bbcc", "xy", "aaaacc" ,"aabcc" };
	fun(ss, 5);
	printf("%s,%s\n", ss[0], ss[4]);

	return 0;
}



int main()
{
	// 斐波那契数列
	int a, b, c, n;
	a = b = c = 1;

	// 求第n个斐波那契数
	scanf("%d", &n); // 7
	while (n)
	{
		if (n <= 2)
			break;
		else
		{
			a = b;
			b = c;
			c = a + b;
		}
		n--;
	}
	printf("%d", c);

	return 0;
}




#include <math.h>

int main()
{
	//int i = 2.0;
	////printf("%d", -++i);
	//printf("%f", i);

	//int a = 289;
	//char b = 'a';
	//b = a;
	//int a = 10;
	//int b = 0;
	//b = a---a;


	//printf("%d", b);
	//printf("%d", a);
	return 0;
}



int main()
{
	int i, j, n = 0;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n - i; j++) {
			printf(" ");
		}
		for (j = 1; j < i * 2; j++) {
			printf("*");
		}
		printf("\n");
	}

	return 0;
}




int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n - i; j++) {
			printf("  ");
		}
		for (int j = 1; j <= i; j++) {
			printf("%d ", j);
		}
		for (int j = i - 1; j >= 1; j--) {
			printf("%d ", j);
		}
		printf("\n");
	}
}


int main()
{
	//int m, n, i;
	//for (n = 1; n < 10; n++)
	//{
	//	for (i = 1; i <= 4 * n - 4; i++)
	//		printf(" ");
	//	for (m = n; m < 10; m++)
	//		printf("%4d", m * n);
	//	printf("\n");
	//}

	return 0;
}



int main()
{
	int a[5][5] = { 0 };
	int i, j, k = 1;
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			a[i][j] = k++;
		}
	}

	for (i = 0; i < 5; i++)
	{
		for (j = 0; j <= i; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}


int main()
{
	int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int i, b[10] = { 0 };
	for (i = 1; i < 10; i++)
	{
		b[i] = a[i] / a[i - 1];
	}

	for (i = 1; i < 10; i++) {

		printf("%d ", b[i]);
		if (i % 3 == 0) printf("\n");
	}
	return 0;
}


int main()
{
	int a[10][10], i, j, k = 0, m, n;
	scanf("%d", &n);
	if (n % 2 == 0) 
		m = n / 2; // 偶数
	else 
		m = n / 2 + 1; // 奇数

	for (i = 0; i < m; i++)
	{
		for (j = i; j < n - i; j++) {
			k++;
			a[i][j] = k;
		}
		for (j = i + 1; j < n - i; j++) {
			k++;
			a[j][n - i - 1] = k;
		}
		for (j = n - i - 2; j >= i; j--) {
			k++;
			a[n - i - 1][j] = k;
		}

		for (j = n - i - 2; j >= i + 1; j--) {
			k++;
			a[j][i] = k;
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			printf("%5d", a[i][j]);
		printf("\n");
	}
	return 0;
}



int main()
{
	int i = 0,j;
	char a[30], b[30];
	gets(a);
	gets(b);
	while (a[i++] != '\0');
	for (j = 0, i--; j < 5 && b[j] != 0; j++)
		a[i++] = b[j];
	a[i] = '\0';
	puts(a);

	return 0;
}



int main()
{
	int x = 0,i;
	int a[5] = { 0 };
	while (x != -1)
	{
		scanf("%d", &x);
		if (x >= 0 && x <= 4)
			a[x]++;
	}
	for (i = 0; i < 5; i++)
		printf("%d ", a[i]);

	return 0;
}


float fun(int m,int n)
{
	float p = 1.0;
	int i;
	for (i = 1; i <= m; i++)
	{
		p *= i;
	}
	for (i = 1; i <= n; i++)
	{
		p /= i;
	}
	for (i = 1; i <= m-n; i++)
	{
		p /= i;
	}

	return p;
}

int main()
{
	int m, n;
	float p = 1.0;

	scanf("%d", &m);
	scanf("%d", &n);
	p = fun(m, n);
	printf("%lf", p);

	return 0;
}



int main()
{
	int bitNumber(int);

	int n;
	scanf("%d", &n);
	
	printf("%d", bitNumber(n));

	return 0;
}

int bitNumber(int n)
{
	int sum = 0;
	if (n < 9)
		return 1;

	while (n > 0)
	{
		sum++;
		n /= 10;
	}
	return sum;
}





#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
int max() {

    return 0;
}
int main() {
//    printf("%p\n", max);
//    printf("%p\n", &max);
    char str[]  = "OK";
    char *p1 = str;
    char *p2 = &str;
    char (*p)[3] = &str;
    printf("%s\n", p1);
    printf("%s\n", p2);
    printf("%s\n", p);
    return 0;
}


void main() {
    char *a = "Turbo C";
    printf("%c %s\n", a[0], a);

    char *p = &a[4];
    printf("%c", *p);
}
#include <stdio.h>
#include <string.h>

void reverse(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}
int main() {
    char str[] = "Hello World";
    reverse(str);
    printf("%s\n", str);
    return 0;
}


int main()
{
    // 汽水
    int bottle = 21;
    int sum = 20;

    while(bottle >= 2)
    {
        if(bottle % 2 == 0) {
            sum += bottle / 2;
            bottle = bottle / 2;
        }
        else {
            sum += bottle / 2 + 1;
            bottle /= 2;
        }
    }
    printf("%d\n",sum);
}


int main()
{
    int money = 0;
    int total = 0;
    int empty = 0;


    scanf("%d", &money);

    //方法1
    total = money;
    empty = money;
    while(empty>1)
    {
        total += empty/2;
        empty = empty/2+empty%2;
    }

    printf("total = %d\n", total);
    return 0;
}

int main()
{
    int arr[10] = {0};
    float fun(int* a);
    for (int i = 0; i < 10; ++i) {
        scanf("%d",&arr[i]);
    }
    printf("%lf",fun(arr));
    return 0;
}

float fun(int *a){
    int max = a[0],min = a[0];
    for (int i = 0; i < 10; ++i) {
        if(a[i] > max)
            max = a[i];
        else if(a[i]<min)
            min = a[i];
    }
    return (float)(max + min) / 10;
}


int main()
{
	bool is_year(int);
	int m[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int month, year, day;
	scanf("%d %d %d", &year, &month, &day);
	for (int i = 1; i < month; i++) {
		day += m[i];
	}
	if (is_year(year) || month >= 2)
		day++;

	printf("there is %d", day);

	return 0;
}

bool is_year(int y)
{
	return ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0);
}


#endif











































































































































































































































































































































































































































































































































































