#define _CRT_SECURE_NO_WARNINGS 1




#include<stdio.h>
//int main()
//{
//	//int a = -10;
//	int a = 0x12345678;
//	return 0;
//}

//int main()
//{
//	int a = 1;
//	char* p = (char*)&a;
//	if (*p == 1) {
//		printf("小端\n");
//	}
//	else {
//		printf("大端\n");
//	}
//	return 0;
//}
#include <windows.h>

//int main()
//{
//	unsigned int i;
//	for (i = 9; i >= 0; i--)
//	{
//		printf("%u\n", i);
//		Sleep(200);
//	}
//	return 0;
//}
//
//unsigned char i = 0;
//int main()
//{
//	for (i = 0; i <= 255; i++)
//	{
//		printf("hello world\n");
//	}
//	return 0;
//}


//int main()
//{
//	char a[1000];
//	int i;
//	for (i = 0; i < 1000; i++)
//	{
//		a[i] = -1 - i;
//	}
//	printf("%d", strlen(a));
//	return 0;
//}

//int main()
//{
//	int n = 9;
//	float* pFloat = (float*)&n;
//	printf("n的值为：%d\n", n);		//1
//	printf("*pFloat的值为：%f\n", *pFloat);		//2
//	*pFloat = 9.0;
//	printf("num的值为：%d\n", n);	//3
//	printf("*pFloat的值为：%f\n", *pFloat);		//4
//
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//    char a = -128;
//    printf("%u\n", a);
//    return 0;
//}

//#include <stdio.h>
//int main()
//{
//    char a = 128;
//    printf("%d\n", a);
//    return 0;
//}

int main()
{
	int i = -20;
	//10000000000000000000000000010100 - -20 原码
	//11111111111111111111111111101011 - 反码
	//11111111111111111111111111101100 - 补码

	unsigned int j = 10;
	//00000000000000000000000000001010 - 原码
	//11111111111111111111111111101100 - 补码
	//11111111111111111111111111110110 -相加
	//10000000000000000000000000001001
	//10000000000000000000000000001010 - -10
	printf("%d\n", i + j);

	return 0;
}