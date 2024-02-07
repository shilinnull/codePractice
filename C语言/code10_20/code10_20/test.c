#define _CRT_SECURE_NO_WARNINGS 1
//递归实现n的k次方

#include<stdio.h>
//
//
//double Pow(int n ,int k) {
//	if (k > 0) {
//		return n*Pow(n, k - 1);
//	}
//	else if(k == 0){
//		return 1;
//	}
//	else {
//		return 1.0/(Pow(n,-k));
//	}
//}
//
//
//int main() {
//	int n = 0;
//	int k = 0;
//	scanf("%d %d", &n, &k);
//	double ret = Pow(n, k);
//	printf("%lf", ret);
//	return 0;
//}
/*写一个递归函数DigitSum(n)，输入一个非负整数，返回组成它的数字之和

例如，调用DigitSum(1729)，则应该返回1+7+2+9，它的和是19

输入：1729，输出：19

*/

//DigitSum(n) {
//	if (n <=9)
//		return n;
//	else
//		return DigitSum(n / 10) + n % 10;
//}
//int main() {
//	int k = 0;
//	scanf("%d", &k);
//	int ret = DigitSum(k);
//	printf("%d", ret);
//	return 0;
//}

#include<string.h>
#include<assert.h>
//size_t my_strlen(const char*src)
//{
//	assert(src);
//	char* dest = src;
//	size_t count = 0;
//	while (*dest!='\0') {
//		dest++;
//		count++;
//	}
//	return count;
//}

//size_t my_strlen(const char* src) {
//	char* dest = src;
//	if (*dest == '\0')
//		return 0;
//	else
//		return 1 + my_strlen(dest+1);
//}
//
//
//int main() {
//	char arr[] = "abcdef";
//	size_t len = my_strlen(arr);
//	printf("%d", len);
//	return 0;
//}

//Fac(n) {
//	if (n == 1)
//		return 1;
//	else
//		return n * Fac(n - 1);
//}

//Fac(n) {
//	int sum = 1;
//	for (int i = 1; i <= n; i++) {
//		sum *= i;
//	}
//	return sum;
//}
//
//int Fac(int n) {
//	if (n > 9)
//		Fac(n / 10);
//	printf("%d ", n % 10);
//}
//
//int main() {
//	int n = 0;
//	scanf("%d", &n);	
//	int ret = Fac(n);
//	printf("%d", ret);
//	return 0;
//}
//
//size_t my_strlen(const char*src)
//{
//	assert(src);
//	char* dest = src;
//	size_t count = 0;
//	while (*dest!='\0') {
//		dest++;
//		count++;
//	}
//	return count;
//}
//char revers_str(char arr[])
//{
//	int len = my_strlen(arr);
//	char tmp = arr[0];
//	arr[0] = arr[len - 1];
//	arr[len - 1] = '\0';
//	if(my_strlen(arr+1)>=2)
//		revers_str(arr + 1);
//	arr[len - 1] = tmp;
//}
//int main() {
//	char arr[] = "abcdef";
//	char len = revers_str(arr);
//	printf("%s", len);
//	return 0;
//}


//冒泡排序
//
//void bubble_sort(int arr[], int sz) {
//	//冒泡的趟数为数组的长度-1
//	for (int i = 0; i < sz - 1; i++) {
//		int flag = 0;
//		//每交换一下趟数-1
//		for (int j = 0; j < sz - 1 - i; j++) {
//			if (arr[j] < arr[j + 1]) {
//				flag = 1;//flag为1时就说明还是无序
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//			}
//		}
//		if (!flag)//如果flag为0就return
//			return;
//	}
//}
//print_arr(int arr[], int sz) {
//	for (int i = 0; i < sz; i++) {
//		printf("%d ", arr[i]);
//	}
//}
//
//int main() {
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	bubble_sort(arr, sz);
//	print_arr(arr, sz);
//}

//int main()
//{
//	//int a = 10;
//	//int b = 20;
//	//a = a ^ b;
//	//b = a ^ b;
//	//a = a ^ b;
//	//printf("%d %d", a, b);
//
//	return 0;
//}

//int main() {
//	int a = 10;
//	for (int i = 0; i < 32; i+=2) {
//		printf("%d ", (a >> i) & 1);
//	}
//	printf("\n");
//	for (int i = 1; i < 32; i += 2) {
//		printf("%d ", (a >> i) & 1);
//	}
//}
//


//int main() {
//    int y = 0;
//    int m = 0;
//    int arr[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//    scanf("%d%d", &y, &m);
//    int day = arr[m];
//    if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0) {
//        if (m == 2)
//        {
//            day += 1;
//        }
//    }
//    printf("%d", day);
//
//    return 0;
//}


#include <stdio.h>
#include<math.h>
int main() {
    int i = 0;

    for (i = 10000; i <= 99999; i++)
    {
        int sum = 0;
        int j = 0;
        for (j = 1; j <= 4; j++)
        {
            int tmp = (int)pow(10, j);
            sum += ((i / tmp) * (i % tmp));
        }
        if (sum == i)
            printf("%d ", i);
    }
    return 0;
}
