#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <stdio.h>
//#include <windows.h>
//int main()
//{
//	for (int i = 0; i < 10; i++) {
//		printf("i=%d\n", i);
//		if (1)
//		{
//			auto int j = 0; //�Զ�����
//			printf("before: j=%d\n", j);
//			j += 1;
//			printf("after : j=%d\n", j);
//		}
//	}
//	system("pause");
//	return 0;
//}

//
//#include <stdio.h>
//#include <windows.h>
//int main()
//{
//	register int a = 0;
//	printf("&a = %p\n", &a);
//	//�������������� 1 error C2103: �Ĵ��������ϵġ�&��
//	//ע�⣬���ﲻ�����еı�����������Ŀǰ���ǵ�vs2013�Ǳ���ġ�
//	system("pause");
//	return 0;
//}

//
//#include<stdio.h>
//int main()
//{
//
//	int i = -20;
//	unsigned int j = 10;
//	printf("%u\n", i + j);
//
//	return 0;
//}
//���Ͼ���

//���Ͼ���
/*
��һ�����־��󣬾����ÿ�д������ǵ����ģ�������ϵ����ǵ����ģ�
���д�����������ľ����в���ĳ�������Ƿ���ڡ�
Ҫ��ʱ�临�Ӷ�С��O(N);

*/
#include<stdio.h>
int FindNum(int arr[][3], int x, int y, int key)
{
	int i = 0;
	int j = y - 1;
	while (j >= 0 && i < x)
	{
		if (arr[i][j] < key)
		{
			i++;
		}
		else if(arr[i][j] > key)
		{
			j--;
		}
		else
		{
			return 1;
		}
	}
	return 0;
}
int main()
{
	int arr[][3] = { {1,2,3},{2,3,4},{3,4,5} };
	int ret = FindNum(arr, 3, 3, 4);
	printf("%d", ret);
	return 0;
}
