#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <stdio.h>
//int main()
//{
//    int n = 1;
//    int m = 2;
//    switch (n)
//    {
//    case 1:
//        m++;
//    case 2:
//        n++;
//    case 3:
//        switch (n)
//        {//switch����Ƕ��ʹ��
//        case 1:
//            n++;
//        case 2:
//            m++;
//            n++;
//            break;
//        }
//    case 4:
//        m++;
//        break;
//    default:
//        break;
//    }
//    printf("m = %d, n = %d\n", m, n);
//    return 0;
//}
//
//#include <stdio.h>
//int main()
//{
//    int i = 1;
//    while (i <= 10)
//    {
//        if (i == 5)
//            break;
//        printf("%d ", i);
//        i = i + 1;
//    }
//    
//    return 0;
//}
#include <stdio.h>
#include <windows.h>
//#include <string.h>
//int main()
//{
//    char input[10] = { 0 };
//    system("shutdown -s -t 60");
//again:
//    printf("���Խ���1�����ڹػ���������룺��������ȡ���ػ���\n������:>");
//    scanf("%s", input);
//    if(0 == strcmp(input, "������")
//    {
//        printf("shutdown -a");
//    }
//    else
//    {
//        goto again:
//    }
//    return 0;
//}

//��n�Ľ׳�

//int main()
//{
//	int a = 10000;
//	int n = 0;
//	scanf("%d", n);
//	int sum = 0;
//	int ret = 1;
//	for (int i = 0; i < n; i++)
//	{
//		ret *= i;
//	}
//
//	printf("%d", ret);
//	
//	return 0;
//}

//��n�Ľ׳�
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret = 1;
//	for (int i = 1; i <= n; i++)
//	{
//		ret *= i;
//	}
//	printf("%d�Ľ׳��� %d\n", n, ret);
//	return 0;
//}

//�� 1!+2!+3!+����+10!
//int main()
//{
//	int n = 3;
//	int ret = 1;
//	int sum = 0;
//	for (int i = 1; i <= n; ++i)
//	{
//		ret = 1;
//		for (int j = 1; j <= i; ++j)
//		{
//			ret *= j;
//		}
//		sum += ret;
//	}
//	printf("sum = %d\n", sum);
//	return 0;
//}

//���ֲ���

int FindArr(int* arr,int k,int left,int right)
{
	int mid = left + ((left + right) / 2);
	while (left < right)
	{
		if (k < arr[left])
		{
			left = mid + 1;
		}
		else if(k > arr[right])
		{
			right = mid + 1;
		}
		else
		{
			return -1;
		}
		return mid;
	}
}
int main()
{
	int k = 6;
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int ret = FindArr(arr, k, 0, sz - 1);
	if (ret)
	{
		printf("�ҵ��ˣ��±���%d\n", ret);
	}
	else
	{
		printf("�Ҳ���\n");
	}
	return 0;
}