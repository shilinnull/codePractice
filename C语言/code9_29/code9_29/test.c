#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//����1
//int main()
//{
//    int age = 0;
//    scanf("%d", &age);
//    if (age < 18)
//    {
//        printf("δ����\n");
//    }
//}
////����2
//#include <stdio.h>
//int main()
//{
//    int age = 0;
//    scanf("%d", &age);
//    if (age < 18)
//    {
//        printf("δ����\n");
//    }
//    else
//    {
//        printf("����\n");
//    }
//}
//����3
//#include <stdio.h>
//int main()
//{
//    int age = 0;
//    scanf("%d", &age);
//    if (age < 18)
//    {
//        printf("����\n");
//    }
//    else if (age >= 18 && age < 30)
//    {
//        printf("����\n");
//    }
//    else if (age >= 30 && age < 50)
//    {
//        printf("����\n");
//    }
//    else if (age >= 50 && age < 80)
//    {
//        printf("����\n");
//    }
//    else
//    {
//        printf("������\n");
//    }
//
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	if (n % 2 == 1)
//	{
//		printf("YES\n");
//	}
//	else
//	{
//		printf("NO\n");
//	}
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int i = 1;
//	while (i<= 100)//����1~100������
//	{
//		if(i % 2 ==1)
//			printf("%d ", i);
//		i++;
//	}
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int i = 1;
//	while (i <= 100)//����1~100������
//	{
//		printf("%d ", i);
//		//i+=2;
//		i = i + 2;//Ҳ��������д
//	}
//	return 0;
//}

//
//#include <stdio.h>
////switch������ʾ
//int main()
//{
//    int day = 0;
//    switch (day)
//    {
//        case 1:
//        case 2:
//        case 3:
//        case 4:
//        case 5:
//            printf("weekday\n");
//            break;
//        case 6:
//        case 7:
//            printf("weekend\n");
//            break;
//    }
//    return 0;
//}

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
//            continue;
//        printf("%d ", i);
//        i = i + 1;
//    }
//    return 0;
//}


#include <stdio.h>
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
//    return 0;
//}
//#include <stdio.h>
//int main()
//{
//    int i = 1;
//    while (i <= 10)
//    {
//        i = i + 1; 
//        if (i == 5)
//            continue;
//        printf("%d ", i);
//    }
//    return 0;
//}

//#include <stdio.h>
//int main()
//{
//    int ch = 0;
//    while ((ch = getchar()) != EOF)
//        putchar(ch);
//    return 0;
//}
//����Ĵ����ʵ����޸��ǿ�����������������.
//����2
//#include <stdio.h>
//int main()
//{
//    char ch = '\0';
//    while ((ch = getchar()) != EOF)
//    {
//        if (ch < '0' || ch > '9')
//            continue;
//        putchar(ch);
//    }
//    return 0;
//}
//�������������ǣ�ֻ��ӡ�����ַ������������ַ��ġ�
//
//#include <stdio.h>
//int main()
//{
//	int i = 0;
//	//for(i=1/*��ʼ��*/; i<=10/*�жϲ���*/; i++/*��������*/)
//	for (i = 1; i <= 10; i++)
//	{
//		printf("%d ", i);
//	}
//	return 0;
//}
//
//int main()
//{
//	char password[20];
//	scanf("%s", password);
//	printf("��ȷ�ϣ�Y/N����");
//	int ch = getchar();
//	if ('Y' == ch)
//		printf("ȷ�ϳɹ�\n");
//	else
//		printf("ȷ��ʧ��\n");
//	return 0;
//}
//
//for (...)
//for (...)
//{
//    for (...)
//    {
//        if (disaster)
//            goto error;
//    }
//}
//��
//error :
//if (disaster)
//// ����������
//
//void menu()
//{
//	printf("********************************\n");
//	printf("**********  1.play  ************\n");
//	printf("**********  0.exit  ************\n");
//}
//int main(void)
//{
//	int input = 0;
//	do
//	{
//		menu();
//		printf("���������ѡ��>");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			printf("������\n");
//			break;
//		case 0:
//			printf("�˳���Ϸ\n");
//			break;
//		default:
//			printf("���������������\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//void menu()
//{
//	printf("**********************************\n");
//	printf("*********** 1.play     **********\n");
//	printf("*********** 0.exit     **********\n");
//	printf("**********************************\n");
//}
////RAND_MAX--rand�����ܷ�������������ֵ��
//void game()
//{
//	int random_num = rand() % 100 + 1;
//	int input = 0;
//	while (1)
//	{
//		printf("������µ�����>:");
//		scanf("%d", &input);
//		if (input > random_num)
//		{
//			printf("�´���\n");
//		}
//		else if (input < random_num)
//		{
//			printf("��С��\n");
//		}
//		else
//		{
//			printf("��ϲ�㣬�¶���\n");
//			break;
//		}
//	}
//}
//int main()
//{
//	int input = 0;
//	srand((unsigned)time(NULL));
//	do
//	{
//		menu();
//		printf("��ѡ��>:");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			game();
//			break;
//		case 0:
//			break;
//		default:
//			printf("ѡ�����,����������!\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}

//int main(void)
//{
//	char arr1[] = "############";
//	char arr2[] = "hello bit";
//	strcpy(arr1, arr2);
//	printf("%s\n", arr1);
//	return 0;
//}
//int main()
//{
//
//	char arr[] = "hello bit";
//	memset(arr, 'x', 5);
//	printf("%s\n", arr);
//	return 0;
//}
//void swap(int x, int y)
//{
//	int t = x;
//	x = y;
//	y = t;
//}
//
//int main(void)
//{
//	int a = 10;
//	int b = 20;
//
//	printf("����ǰ��a = %d, b = %d\n", a, b);
//	swap(a, b);
//	printf("������a = %d, b = %d\n", a, b);
//	return 0;
//}
//
//
//#include<stdio.h>
//#include<assert.h>
//
//size_t my_strlen(const char* src)
//{
//	assert(src);
//	size_t len = 0;
//	while (*src != '\0')
//	{
//		len++;
//		src++;
//	}
//	return len;
//}
//
//int main()
//{
//	char arr[] = "abcdef";
//	size_t ret = my_strlen(arr);
//	printf("%d", ret);
//	return 0;
//}


#include<stdio.h>
#include<assert.h>

char* my_strcpy(char* dest,const char* src)
{
	assert(src && dest);
	char* ret = dest;
	while (*dest++ = *src++);
	return ret;
}

int main()
{
	char arr1[20] = { 0 };
	char arr2[] = "abcdef";
	my_strcpy(arr1, arr2);
	printf("%s", arr1);
	return 0;
}