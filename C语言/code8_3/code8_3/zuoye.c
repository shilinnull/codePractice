#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>


//�������
//
//int main()
//{
//    int arr[10] = { 0 };
//    for (int i = 0; i < 10; i++)
//    {
//        scanf("%d", &arr[i]);
//    }
//    for (int j = 9; j >= 0; j--)
//    {
//        printf("%d", arr[j]);
//    }
//
//    return 0;
//}





//X��ͼ��
//
//int main()
//{
//    int n = 0;
//    while (scanf("%d", &n))
//    {
//
//        for (int i = 0; i < n; i++)
//        {
//            for (int j = 0; j < n; j++)
//            {
//                if (i == j || (i + j) == n - 1)
//                {
//                    printf("*");
//                }
//                else
//                {
//                    printf(" ");
//                }
//            }
//            printf("\n");
//        }
//
//    }
//    return 0;
//}





//����������ͼ��
//
//int main()
//{
//    int n = 0;
//    while (scanf("%d", &n)!=EOF)
//    {
//        for (int i = 0; i < n; i++)
//        {
//            for (int j = 0; j < n; j++)
//            {
//                if (i == 0 || i == n - 1)
//                {
//                    printf("* ");
//                }
//                else if (j == 0 || j == n - 1)
//                {
//                    printf("* ");
//                }
//                else
//                {
//                    printf("  ");
//                }
//            }
//            printf("\n");
//
//        }
//    }
//
//    return 0;
//}

/*
���������������������������Լ��

���磺

���룺20 40

�����20
*/


/*
���Լ���������������й���Լ��������ߡ�
���ķ�ʽ�Ƚ϶࣬������١�շת�������������𷨡�Stein�㷨�㷨
�˴���Ҫ���ܣ�շת�����


˼·��
���ӣ�18��24�����Լ��
��һ�Σ�a = 18  b = 24  c = a%b = 18%24 = 18
      ѭ���У�a = 24   b=18
�ڶ��Σ�a = 24   b = 18  c = a%b = 24%18 = 6
      ѭ���У�a = 18   b = 6


�����Σ�a = 18   b = 6   c=a%b = 18%6 = 0
  ѭ������

��ʱb�е����ݼ�Ϊ�������е����Լ����
*/

//
//int main()
//{
//	int a = 18;
//	int b = 24;
//	int c = 0;
//
//	while (c = a % b)
//	{
//		a = b;
//		b = c;
//	}
//
//	printf("%d\n", b);
//	return 0;
//}









//������A�е����ݺ�����B�е����ݽ��н�����������һ����

//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6 };
//	int arr2[] = { 2,3,4,5,6,7 };
//	int len = sizeof(arr) / sizeof(arr[0]);
//	for (int i = 0; i < len; i++)
//	{
//		int tmp = arr[i];
//		arr[i] = arr2[i];
//		arr2[i] = tmp;
//	}
//
//	for (int i = 0; i < len; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	for (int i = 0; i < len; i++)
//	{
//		printf("%d ", arr2[i]);
//	}
//	return 0;
//}





/*
�����ת��
*/
//
//int main()
//{
//	int n = 0;
//	int m = 0;
//	scanf("%d %d", &n, &m);
//	int arr[n][m];
//
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < m; j++)
//		{
//			scanf("%d", &arr[i][j]);
//		}
//	}
//
//	for (i = 0; i < m; i++)
//	{
//		for (j = 0; j < n; j++)
//		{
//			printf("%d ", arr[j][i]);
//		}
//		printf("\n");
//	}
//	return 0;
//}






/*
��дһ�����򣬴��û������ж�ȡ10���������洢��һ�������С�Ȼ�󣬼��㲢�����Щ������ƽ��ֵ��
*/
//#include<stdio.h>
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int sum = 0;
//	for (int i = 0; i < sz; i++)
//	{
//		sum += arr[i];
//	}
//	printf("ƽ��ֵ��%f\n", sum * 1.0 / sz);
//
//	return 0;
//}

