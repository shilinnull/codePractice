#define _CRT_SECURE_NO_WARNINGS 1


/*
��һ�����־��󣬾����ÿ�д������ǵ����ģ�������ϵ����ǵ����ģ�
���д�����������ľ����в���ĳ�������Ƿ���ڡ�
Ҫ��ʱ�临�Ӷ�С��O(N);
*/

//
//#include <stdio.h>
//
//int findnum(int a[][3], int x, int y, int k) //��һ��������������Ҫ����
//{
//	int i = 0;
//	int j = y - 1; //�����Ͻǿ�ʼ����
//	while (j >= 0 && i < x) //��������Ͻ�>=0���Ҿ���ĵ�һ��Ԫ��<�����
//	{
//		if (a[i][j] < k) //��Ҫ�ҵ������ִ������
//		{
//			i++;
//		}
//		else if (a[i][j] > k) //��Ҫ�ҵ�����С������
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
//	if (findnum(a, 3, 3, k))//����3��3�з���1����0
//	{
//		printf("�ҵ��ˣ�\n");
//	}
//	else
//	{
//		printf("�Ҳ�����\n");
//	}
//
//	return 0;
//}

//
//int main()
//{
//	char* arr[5] = { "hello", "bit" };
//	//һ��Ԫ����h��һ��Ԫ����b
//	test(arr);//����test������������arr
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
////�����ַ���
//void LeftRound(char* src, int k)
//{
//	int len = strlen(src);
//	int count = k % len;
//	//Ҫ�ƶ��Ĵ���
//	for (int i = 0; i < count; i++)
//	{
//		//������ĵ�һ���ַ��洢����ʱtmp������
//		char tmp = src[0];
//		int j = 0;
//		//�������е��ַ�����и���ǰ��
//		for (j = 0; j < len - 1; j++)
//		{
//			src[j] = src[j + 1];
//		}
//		//�����ʱ������ֵ��ԭ�����У�����ƶ�
//		src[j] = tmp;
//	}
//}
//int main()
//{
//	char arr[] = "abcd";
//	int n = 0;
//	printf("������Ҫ���򼸴�:>");
//	scanf("%d", &n);
//	//���ú�������ʵ��
//	LeftRound(arr, n);
//	printf("%s", arr);
//	return 0;
//}
//
//#include<stdio.h>
//#include<string.h>
////ʹ�ÿⷽ��ʵ��
//int find(char* str1, char* str2)
//{
//	char tmp[256] = { 0 };
//	//���ַ�����������ʱ����
//	strcpy(tmp, str1);
//	//���ַ���ƴ�ӵ���ʱ��������
//	strcat(tmp, str1);
//	//��tmp��Ѱ��str2�ַ���
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
5λ�˶�Ա�μ���10��̨��ˮ����������������Ԥ����������
Aѡ��˵��B�ڶ����ҵ�����
Bѡ��˵���ҵڶ���E���ģ�
Cѡ��˵���ҵ�һ��D�ڶ���
Dѡ��˵��C����ҵ�����
Eѡ��˵���ҵ��ģ�A��һ��
����������ÿλѡ�ֶ�˵����һ�룬����ȷ�����������Ρ�
*/
#include <stdio.h>

void swapArgs(int* a, int* b) //��������
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void diveRank(int* p, int n)
{
	if (n >= 5) //��ʱ��nҲ����������ѭ�������ġ�
	{
		if ((p[1] == 2) + (p[0] == 3) == 1 && //B�ڶ����ҵ���
			(p[1] == 2) + (p[4] == 4) == 1 && //�ҵڶ���E����
			(p[2] == 1) + (p[3] == 2) == 1 && //�ҵ�һ��D�ڶ�
			(p[2] == 5) + (p[3] == 3) == 1 && //C����ҵ���
			(p[4] == 4) + (p[0] == 1) == 1)   //�ҵ��ģ�A��һ
			//���ڴ�ʱ��ִ�е�ȫ���У����Բ���Ҳʡ�ˡ�
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
	for (i = n; i < 5; i++) //����ݹ鷽ʽ������˶�1~5��ȫ���У������ǴӺ���ǰ��ͣ��ִ�н��������Բο��Ľ�����ԭ���룬������ݹ����д�س�ѭ���󣬿��Ը��õ���⡣
	{
		swapArgs(p + i, p + n);
		diveRank(p, n + 1);
		swapArgs(p + i, p + n);
	}
}

int main()
{
	int p[5] = { 1, 2, 3, 4, 5 }; //��Ȼ������ȫ���У����Գ�ֵ������á�

	diveRank(p, 0);

	return 0;
}


/*
����Ļ�ϴ�ӡ������ǡ�
1
1 1
1 2 1
1 3 3 1
����
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
