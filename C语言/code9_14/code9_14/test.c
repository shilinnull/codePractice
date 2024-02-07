#define _CRT_SECURE_NO_WARNINGS 1


/*
有一个数字矩阵，矩阵的每行从左到右是递增的，矩阵从上到下是递增的，
请编写程序在这样的矩阵中查找某个数字是否存在。
要求：时间复杂度小于O(N);
*/

//
//#include <stdio.h>
//
//int findnum(int a[][3], int x, int y, int k) //第一个参数的类型需要调整
//{
//	int i = 0;
//	int j = y - 1; //从右上角开始遍历
//	while (j >= 0 && i < x) //矩阵的右上角>=0并且矩阵的第一个元素<最左边
//	{
//		if (a[i][j] < k) //比要找到的数字大就向下
//		{
//			i++;
//		}
//		else if (a[i][j] > k) //比要找的数字小就向左
//		{
//			j--;
//		}
//		else
//		{
//			return 1;
//		}
//	}
//	return 0;
//}
//
//
//int main()
//{
//	int a[][3] = { {1, 3, 5},{3, 5, 7},{5, 7, 9} }; 
//	int k = 0;
//	scanf("%d", &k);
//
//	if (findnum(a, 3, 3, k))//传入3行3列返回1或者0
//	{
//		printf("找到了！\n");
//	}
//	else
//	{
//		printf("找不到！\n");
//	}
//
//	return 0;
//}

//
//int main()
//{
//	char* arr[5] = { "hello", "bit" };
//	//一个元素是h，一个元素是b
//	test(arr);//调用test函数，传参是arr
//
//	/*
//	A.void test(char* arr);
//	B.void test(char** arr);
//	C.void test(char arr[5]);
//	D.void test(char* arr[5]);
//	*/
//	return 0;
//}
//

#include<stdio.h>
//
//
//int main()
//{
//
//	//int aa[2][5] = { 10,9,8,7,6,5,4,3,2,1 };
//
//	//int* ptr1 = (int*)(&aa + 1);
//
//	//int* ptr2 = (int*)(*(aa + 1));
//	//
//	//printf("%d,%d", *(ptr1 - 1), *(ptr2 - 1));
//
//	//int arr[3][5] = { 1,2,3,4,5,6,7,8,9,10 };
//	//print_arr(arr, 3, 5);
//	/*
//A.void print_arr(int arr[][],int row, int col);x
//B.void print_arr(int* arr, int row, int col);x
//C.void print_arr(int (*arr)[5], int row, int col);
//D.void print_arr(int (*arr)[3], int row, int col);x
//	*/
//
//
//
//	return 0;
//}
//

//int main()
//{
//	int a[5] = { 5, 4, 3, 2, 1 };
//	int* ptr = (int*)(&a + 1);
//	printf("%d,%d", *(a + 1), *(ptr - 1)); //4   1
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int* p = NULL;
//
//	int arr[10] = { 0 };
//	
//	/*
//	
//	A.p = arr;
//	B.int (*ptr)[10] = &arr;
//	C.p = &arr[0];
//	D.p = &arr;
//
//	*/
//	return 0;
//}

//int main()
//{
//	int arr[10] = { 0 };
//	return 0;
//}
//#include<assert.h>
////逆序字符串
//void LeftRound(char* src, int k)
//{
//	int len = strlen(src);
//	int count = k % len;
//	//要移动的次数
//	for (int i = 0; i < count; i++)
//	{
//		//将数组的第一个字符存储到临时tmp变量中
//		char tmp = src[0];
//		int j = 0;
//		//将数组中的字符向进行覆盖前面
//		for (j = 0; j < len - 1; j++)
//		{
//			src[j] = src[j + 1];
//		}
//		//最后将临时变量赋值给原数组中，完成移动
//		src[j] = tmp;
//	}
//}
//int main()
//{
//	char arr[] = "abcd";
//	int n = 0;
//	printf("请输入要逆序几次:>");
//	scanf("%d", &n);
//	//调用函数进行实现
//	LeftRound(arr, n);
//	printf("%s", arr);
//	return 0;
//}
//
//#include<stdio.h>
//#include<string.h>
////使用库方法实现
//int find(char* str1, char* str2)
//{
//	char tmp[256] = { 0 };
//	//将字符串拷贝到临时变量
//	strcpy(tmp, str1);
//	//将字符串拼接到临时变量后面
//	strcat(tmp, str1);
//	//在tmp里寻找str2字符串
//	return strstr(tmp, str2) != NULL;
//}
//
//int main()
//{
//	char arr[] = "AABCD";
//	int ret = find(arr, "BCDAA");
//	printf("%d", ret);
//	return 0;
//}


/*
5位运动员参加了10米台跳水比赛，有人让他们预测比赛结果：
A选手说：B第二，我第三；
B选手说：我第二，E第四；
C选手说：我第一，D第二；
D选手说：C最后，我第三；
E选手说：我第四，A第一；
比赛结束后，每位选手都说对了一半，请编程确定比赛的名次。
*/
#include <stdio.h>

void swapArgs(int* a, int* b) //交换函数
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void diveRank(int* p, int n)
{
	if (n >= 5) //此时的n也是用来控制循环层数的。
	{
		if ((p[1] == 2) + (p[0] == 3) == 1 && //B第二，我第三
			(p[1] == 2) + (p[4] == 4) == 1 && //我第二，E第四
			(p[2] == 1) + (p[3] == 2) == 1 && //我第一，D第二
			(p[2] == 5) + (p[3] == 3) == 1 && //C最后，我第三
			(p[4] == 4) + (p[0] == 1) == 1)   //我第四，A第一
			//由于此时是执行的全排列，所以查重也省了。
		{
			for (int i = 0; i < 5; i++)
			{
				printf("%d ", p[i]);
			}
			putchar('\n');
		}
		return;
	}

	int i;
	for (i = n; i < 5; i++) //这个递归方式就完成了对1~5的全排列，方法是从后向前不停的执行交换。可以参考改进二和原代码，将这个递归程序写回成循环后，可以更好的理解。
	{
		swapArgs(p + i, p + n);
		diveRank(p, n + 1);
		swapArgs(p + i, p + n);
	}
}

int main()
{
	int p[5] = { 1, 2, 3, 4, 5 }; //当然由于是全排列，所以初值必须给好。

	diveRank(p, 0);

	return 0;
}


/*
在屏幕上打印杨辉三角。
1
1 1
1 2 1
1 3 3 1
……
*/
//
//void yangHuiTriangle(int n)
//{
//	int data[30] = { 1 };
//
//	int i, j;
//	printf("1\n"); 
//	for (i = 1; i < n; i++) 
//	{
//		for (j = i; j > 0; j--) 
//		{
//			data[j] += data[j - 1]; 
//		}
//
//		for (j = 0; j <= i; j++) 
//		{
//			printf("%d ", data[j]);
//		}
//		putchar('\n');
//	}
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	yangHuiTriangle(n);
//	return 0;
//}
