#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>


/*
思路：
仔细观察图形，可以发现，此图形中是由空格和*按照不同个数的输出组成的。
上三角：先输出空格，后输出*，每行中
  空格：从上往下，一行减少一个
  *：2*i+1的方式递增

下三角：先输出空格，后输出*，每行中
  空格：从上往下，每行多一个空格
  *： 从上往下，按照2*(line-1-i)-1的方式减少，其中：line表示总共有多少行
按照上述方式，将上三角和下三角中的空格和*分别输出即可。
*/
//
//int main() {
//
//	int n = 0;
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n - i - 1; j++) {
//			printf(" ");
//		}
//		for (int j = 0; j < 2 * i + 1; j++) {
//			printf("*");
//		}
//		printf("\n");
//	}
//
//	for (int i = 0; i < n-1; i++) {
//		for (int j = 0; j <= i; j++) {
//			printf(" ");
//		}
//		for (int j = 0; j < 2 * (n - 1 - i) - 1; j++) {
//			printf("*");
//		}
//		printf("\n");
//	}
//
//	
//	return 0;
//}


#include<math.h>
//int main() {
//	int i = 0;
//	for (i = 0; i <= 999999; i++)
//	{
//		int count = 1;
//		int tmp = i;
//		int sum = 0;
//		//判断i是否为水仙花数
//		//1. 求判断数字的位数
//		while (tmp / 10)
//		{
//			count++;
//			tmp = tmp / 10;
//		}
//
//		//2. 计算每一位的次方和
//		tmp = i;
//		while (tmp)
//		{
//			sum += pow(tmp % 10, count);
//			tmp = tmp / 10;
//		}
//
//		//3. 判断
//		if (sum == i)
//			printf("%d ", i);
//	}
//	return 0;
//}
//
//int main() {
//	int n = 0;
//	int m = 0;
//	scanf("%d%d", &n, &m);
//	int tmp = 0;
//	int i = 0;
//	int sum = 0;
//	while (n) {
//		for (i = 0; i < n; i++) {
//			tmp += n * 10 + i;
//			sum += tmp;
//		}
//	}
//	printf("%d", sum);
//	return 0;
//}

//喝汽水问题
//题目内容：
//喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，给20元，可以喝多少汽水（编程实现）。

//int main() {
//	int money = 20;
//	int bottle = money;
//	int empty_bottle = 0;
//	while (empty_bottle) {
//		empty_bottle/=2
//	}
//	//bottle = money * 2 - 1;
//	printf("%d", bottle);
//	return 0;
//}

/*
思路：
1. 20元首先可以喝20瓶，此时手中有20个空瓶子
2. 两个空瓶子可以喝一瓶，喝完之后，空瓶子剩余：empty/2(两个空瓶子换的喝完后产生的瓶子) + empty%2(不够换的瓶子)
3. 如果瓶子个数超过1个，可以继续换，即重复2
*/

//strcpy实现

#include<assert.h>
//#include<string.h>
//char* my_strcpy(char* dest,const char* src) {
//	assert(dest && src);
//	char* start = dest;
//	while (*dest++ = *src++) {
//		;
//	}
//	return start;
//}
//
//
//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[10] = { 0 };
//	my_strcpy(arr2, arr1);
//	printf("%s", arr2);
//	return 0;
//}


//size_t my_strlen(const char* str) {
//	assert(str);
//	size_t count = 0;
//	while (*str) {
//		str++;
//		count++;
//	}
//	return count;
//}
//
//int main() {
//	char arr[] = "abcdef";
//	size_t len = my_strlen(arr);
//	printf("%d", len);
//	return 0;
//}

//题目：

//输入一个整数数组，实现一个函数，
//
//来调整该数组中数字的顺序使得数组中所有的奇数位于数组的前半部分，
//
//所有偶数位于数组的后半部分。


//
//Swap(int arr[], int left,int right) {
//	while (left < right) {
//		while (arr[left] % 2 == 0) {
//			left++;
//		}
//		while (arr[right] % 2 == 1) {
//			right--;
//		}
//
//		if (left<right) {
//			int tmp = arr[left];
//			arr[left] = arr[right];
//			arr[right] = tmp;
//		}
//	}
//
//}
//
//int main() {
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	Swap(arr,0,sz-1);
//	for (int i = 0; i < sz; i++) {
//		printf("%d ", arr[i]);
//	}
//
//
//	return 0;
//}

/*
猜名次
题目内容：
5位运动员参加了10米台跳水比赛，有人让他们预测比赛结果：
A选手说：B第二，我第三；
B选手说：我第二，E第四；
C选手说：我第一，D第二；
D选手说：C最后，我第三；
E选手说：我第四，A第一；
比赛结束后，每位选手都说对了一半，请编程确定比赛的名次。


以下为4个嫌疑犯的供词:
A说：不是我。
B说：是C。
C说：是D。
D说：C在胡说
已知3个人说了真话，1个人说的是假话。
*/

//int main() {
//	int killer = 0;
//	for (killer = 'a'; killer <= 'd'; killer++) {
//		if ((killer!='a') + (killer=='c') + (killer == 'd') + (killer !='d') == 3) {
//			printf("%c", killer);
//		}
//	}
//	return 0;
//}


//求最小公倍数

//int main() {
//	int m = 0;
//	int n = 0;
//	scanf("%d%d", &n, &m);
//
//	int i = 1;
//	while (i * n % m != 0)
//	{
//		i++;
//	}
//	printf("%d", i * n);
//	return 0;
//}

#include <stdio.h>

int main() {
    int n = 0;
    //scanf("%d", &n);
    int arr[10][10] = {0};
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || i == j) {
                arr[i][j] = 1;
            }
            if (i >= 2 && j >= 1) {
                arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
            }
        }
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%5d", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}

