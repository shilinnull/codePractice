#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>


/*
˼·��
��ϸ�۲�ͼ�Σ����Է��֣���ͼ�������ɿո��*���ղ�ͬ�����������ɵġ�
�����ǣ�������ո񣬺����*��ÿ����
  �ո񣺴������£�һ�м���һ��
  *��2*i+1�ķ�ʽ����

�����ǣ�������ո񣬺����*��ÿ����
  �ո񣺴������£�ÿ�ж�һ���ո�
  *�� �������£�����2*(line-1-i)-1�ķ�ʽ���٣����У�line��ʾ�ܹ��ж�����
����������ʽ���������Ǻ��������еĿո��*�ֱ�������ɡ�
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
//		//�ж�i�Ƿ�Ϊˮ�ɻ���
//		//1. ���ж����ֵ�λ��
//		while (tmp / 10)
//		{
//			count++;
//			tmp = tmp / 10;
//		}
//
//		//2. ����ÿһλ�Ĵη���
//		tmp = i;
//		while (tmp)
//		{
//			sum += pow(tmp % 10, count);
//			tmp = tmp / 10;
//		}
//
//		//3. �ж�
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

//����ˮ����
//��Ŀ���ݣ�
//����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ����20Ԫ�����Ժȶ�����ˮ�����ʵ�֣���

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
˼·��
1. 20Ԫ���ȿ��Ժ�20ƿ����ʱ������20����ƿ��
2. ������ƿ�ӿ��Ժ�һƿ������֮�󣬿�ƿ��ʣ�ࣺempty/2(������ƿ�ӻ��ĺ���������ƿ��) + empty%2(��������ƿ��)
3. ���ƿ�Ӹ�������1�������Լ����������ظ�2
*/

//strcpyʵ��

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

//��Ŀ��

//����һ���������飬ʵ��һ��������
//
//�����������������ֵ�˳��ʹ�����������е�����λ�������ǰ�벿�֣�
//
//����ż��λ������ĺ�벿�֡�


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
������
��Ŀ���ݣ�
5λ�˶�Ա�μ���10��̨��ˮ����������������Ԥ����������
Aѡ��˵��B�ڶ����ҵ�����
Bѡ��˵���ҵڶ���E���ģ�
Cѡ��˵���ҵ�һ��D�ڶ���
Dѡ��˵��C����ҵ�����
Eѡ��˵���ҵ��ģ�A��һ��
����������ÿλѡ�ֶ�˵����һ�룬����ȷ�����������Ρ�


����Ϊ4�����ɷ��Ĺ���:
A˵�������ҡ�
B˵����C��
C˵����D��
D˵��C�ں�˵
��֪3����˵���滰��1����˵���Ǽٻ���
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


//����С������

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

