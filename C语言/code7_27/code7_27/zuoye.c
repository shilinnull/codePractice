#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//int main()
//{
//    int arr[] = { 1,2,(3,4),5 };
//    printf("%d\n", sizeof(arr));
//    return 0;
//}



//A.int a[2][] = { {0,1,2},{3,4,5} };��
//B.int a[][3] = { {0,1,2},{3,4,5} };��
//C.int a[2][4] = { {0,1,2},{3,4},{5} };��
//D.int a[][3] = { {0,,2},{},{3,4,5} };��


//#include <stdio.h>
//int main()
//{
//    //char str[] = "hello bit";
//    //printf("%d %d\n", sizeof(str), strlen(str));
//    char acX[] = "abcdefg";
//    char acY[] = { 'a','b','c','d','e','f','g' };
//    printf("%d %d", sizeof(acX), sizeof(acY));
//    printf("%d %d", strlen(acX), strlen(acY));
//    return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int arr[10] = { 0 };
//	int sum = 0;
//	for (int i = 0; i < 10; i++)
//	{
//		scanf("%d", &arr[i]);
//		sum += arr[i];
//
//	}
//	double n = (double)sum / 10;
//	printf("ƽ��ֵ��%lf", n);
//	return 0;
//}


//#include<stdio.h>
//
//int main()
//{
//	int arr1[] = { 0 };
//	int arr2[] = { 0 };
//	int i = 0;
//	printf("������10������:>");
//	for (i = 0; i < 10; i++)
//	{
//		scanf("%d", &arr1[i]);
//	}
//	printf("������10������:>");
//	for (i = 0; i < 10; i++)
//	{
//		scanf("%d", &arr2[i]);
//	}
//
//	for (i = 0; i < 10; i++)
//	{
//		int tmp = arr1[i];
//		arr1[i] = arr2[i];
//		arr2[i] = tmp;
//	}
//
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int year = 0;
//	for (int i = 1000; i < 2000; i++)
//	{
//		if((i % 4 == 0) && (i % 100 != 0) || (i % 400 == 0))
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	while (b)
//	{
//		int t = a % b;
//		a = b;
//		b = t;
//	}
//	printf("���Լ����%d\n", a);
//	return 0;
//}


//#include <stdio.h>
//int main() 
//{
//    int n = 0;
//    int m = 0;
//    scanf("%d %d", &n, &m);
//     ����ԭ�����ת�þ���
//    int matrix[n][m];
//    int transpose[m][n];
//
//     ����ԭ����
//    for (int i = 0; i < n; i++) 
//    {
//        for (int j = 0; j < m; j++) 
//        {
//            scanf("%d", &matrix[i][j]);
//        }
//    }
//
//     ת�þ���
//    for (int i = 0; i < m; i++) 
//    {
//        for (int j = 0; j < n; j++) 
//        {
//            transpose[i][j] = matrix[j][i];
//        }
//    }
//
//     ���ת�þ���
//    for (int i = 0; i < m; i++) 
//    {
//        for (int j = 0; j < n; j++) 
//        {
//            printf("%d ", transpose[i][j]);
//        }
//        printf("\n");
//    }
//
//    return 0;
//}






