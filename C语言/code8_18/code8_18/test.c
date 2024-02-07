#define _CRT_SECURE_NO_WARNINGS 1


//int NumberOf1(int n)
//{
//	int count = 0;
//	while (n)
//	{
//		if (n % 2 == 1)
//			count++;
//		n = n / 2;
//	}
//	return count;
//}

#include <stdio.h>
int main()
{
    int a = 10;
    int b = 20;
    printf("a = %d b = %d\n", a, b);
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    printf("a = %d b = %d\n", a, b);
    return 0;
}