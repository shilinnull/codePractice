#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//int main()
//{
//	int i = 100, j, count = 0;//count 作为计数器数出有多少个素数
//	for (i; i <= 200; i++)
//	{
//		int flag = 1;//先假设i就为素数
//		for (j = 2; j < i; j++)
//		{
//			if (i % j == 0)//判断是否余0余0则换下一位整数【这也可以写成if(i%j)】
//			{
//				flag = 0;
//				break;
//			}
//		}
//		if (flag == 1)//满足条件则 说明该数为素数【这也可以写成if(flag)】
//		{
//			count++;//素数个数加1
//			printf("%d ", i);//打印该素数
//		}
//	}
//	printf("\n%d", count); //打印100 - 200间素数的个数
//}

/*
最大公约数：即两个数据中公共约数的最大者。
求解的方式比较多，暴力穷举、辗转相除法、更相减损法、Stein算法算法
此处主要介绍：辗转相除法


思路：
例子：18和24的最大公约数
第一次：a = 18  b = 24  c = a%b = 18%24 = 18
	  循环中：a = 24   b=18
第二次：a = 24   b = 18  c = a%b = 24%18 = 6
	  循环中：a = 18   b = 6


第三次：a = 18   b = 6   c=a%b = 18%6 = 0
  循环结束

此时b中的内容即为两个数中的最大公约数。
*/

//
//int main()
//{
//	int a = 18;
//	int b = 24;
//	int c = 0;
//	while (c = a % b)
//	{
//		a = b;
//		b = c;
//	}
//	printf("%d", b);
//	return 0;
//}
//


/*
思路：
1. 从上述表达式可以分析出
   a. 该表达式主要由100项，基数项为正，偶数项为负
2. 设置一个循环从1~100，给出表达式中的每一项：1.0/i, 注意此处不能使用1，否则结果全部为0
	然后使用flag标记控制奇偶项，奇数项为正，偶数项为负
	然后将所有的项相加即可
*/

//int main()
//{
//
//
//	int i = 0;
//	double sum = 0.0;
//	int flag = 1;
//	for (i = 1; i <= 100; i++) {
//		sum += flag * 1.0 / i;
//		flag = -flag;
//	}
//	printf("%lf", sum);
//
//	return 0;
//}


/*
思路：
素数：即质数，除了1和自己之外，再没有其他的约数，则该数据为素数，具体方式如下
*/
//
//int main()
//{
//	int i = 0;
//	int j = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		int flag = 1;
//		for (j = 2; j < i; j++)
//		{
//			if (i % j == 0)
//			{
//				flag = 0;
//				break;
//			}
//		}
//
//		if (flag)
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}
//

//int main()
//{
//	int a = 18;
//	int b = 24;
//	int c = 0;
//	while (c = a % b)
//	{
//		a = b;
//		b = c;
//	}
//
//	printf("%d", b);
//	return 0;
//}
//计算1/1-1/2+1/3-1/4+1/5 …… + 1/99 - 1/100 的值，打印出结果

//int main()
//{
//	double sum = 0.0;
//	int flag = 1;
//	for (int i = 1; i <= 100; i++)
//	{
//		sum += flag * 1.0 / i;
//		flag = -flag;
//	}
//	printf("%lf", sum);
//	return 0;
//}
//编写程序数一下 1到 100 的所有整数中出现多少个数字9
//int main()
//{
//	int i = 0;
//	int count = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		if (i % 10 == 9)
//		{
//			count++;
//		}else if (i / 10 == 9)
//		{
//			count++;
//		}
//		
//	}
//
//	printf("%d", count);
//	return 0;
//}
//

//猜数字游戏
//
//#include<stdlib.h>
//#include<math.h>
//#include<time.h>
//void enmu()
//{
//	printf("\n");
//	printf("********************\n");
//	printf("****  1. play  *****\n");
//	printf("****  0. exit  *****\n");
//	printf("********************\n");
//	printf("\n");
//}
//
//
//void game()
//{
//	int ret = rand() % 100 + 1;
//	int flag = 10;
//	while (1)
//	{
//		int n = 0;
//		printf("次数有%d\n", flag);
//
//		printf("请猜数字:>");
//		scanf("%d", &n);
//		if (ret > n)
//		{
//			printf("猜小了\n");
//			flag--;
//		}
//		else if (ret < n)
//		{
//			printf("猜大了\n");
//			flag--;
//		}
//		else {
//			printf("猜对了,数字是%d\n", ret);
//			break;
//		}
//		if (flag == 0)
//		{
//			printf("次数用完了数字是%d\n", ret);
//			break;
//		}
//	}
//}
//
//int main()
//{
//	int input = 0;
//	srand((unsigned int)time(NULL));
//
//	do
//	{
//		enmu();
//		printf("请选择：>\n");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			game();
//			break;
//		case 0:
//			printf("退出游戏\n");
//			break;
//		default:
//			printf("选择错误，请重新选择\n");
//		}
//	} while (input);
//
//
//
//	return 0;
//}

//二分查找
//
//void Find_key(int arr[], int left, int right, int k)
//{
//	int flag = 0;
//	while (left <= right) {
//		int mid = left + (right - left) / 2;
//		if (arr[mid] > k) {
//			right = mid - 1;
//		}
//		else if (arr[mid] < k) {
//			left = mid + 1;
//		}
//		else {
//			flag = 1;
//			printf("找到了下标是%d\n", mid);
//			break;
//		}
//	}
//	if(flag ==0)
//		printf("找不到\n");
//}
//
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int k = 7;
//	Find_key(arr, 0, sz - 1, k);
//	return 0;
//}
//void PrintMulTable(int k){
//	int i = 0;
//	int j = 0;
//	for (i = 1; i <= k; i++) {
//		for (j = 1; j <= i; j++) {
//			printf("%d*%d=%-2d ", j, i, i * j);
//		}
//		printf("\n");
//	}
//}
//
//int main() {
//	int n = 0;
//	while (scanf("%d", &n) != EOF) {
//		PrintMulTable(n);
//	}
//	return 0;
//}

//实现函数判断year是不是润年。

//void is_leap_year(int y) {
//	if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0) {
//		printf("%d ", y);
//	}
//}
//
//int main() {
//	for (int y = 1000; y < 2000; y++){
//		is_leap_year(y);
//	}
//	
//}

#include<math.h>
//int is_prime(int n) {
//	for (int j = 2; j <= sqrt(n); j++)
//	{
//		if (n % j == 0) {
//			return 0;
//		}
//	}
//	return 1;
//}
//
//int main() {
//	for (int i = 101; i < 200; i+=2) {
//		if (is_prime(i)) {
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}

//int Fun(int n)
//{
//	if (n == 5)
//		return 2;
//	else
//		return 2 * Fun(n + 1);
//}

//int Fib(int n) {
//	if (n <= 2)
//		return 1;
//	else
//		return Fib(n - 1) + Fib(n - 2);
//}
//
//
//int main(){
//	int n = 0;
//	scanf("%d", &n);
//	int ret = Fib(n);
//	printf("%d", ret);
//	return 0;
//}

//int main() {
//	int a = 1;
//	int b = 1;
//	int c = 1;
//	int n = 0;
//	scanf("%d", &n);
//	while (n >= 3) {
//		c = a + b;
//		a = b;
//		b = c;
//		n--;
//	}
//	printf("%d", c);
//
//}
#include<string.h>
void reveres_string(char* str, int len) {
	char* start = str;
	char* end = str+len - 1;
	while (start < end) {
		char tmp = *start;
		*start = *end;
		*end = tmp;
		start++;
		end--;
	}
}

int main() {
	char arr[] = "abcdef";
	int len = strlen(arr);
	reveres_string(arr,len);
	printf("%s", arr);
	return 0;
}


