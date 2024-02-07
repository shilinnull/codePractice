#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//
//#include <stdio.h>
//int main()
//{
//	int i = 0;
//	for (i = 32; i <= 127; i++)
//	{
//		printf("%c ", i);
//		if (i % 16 == 15)
//			printf("\n");
//	}
//	return 0;
//}
//#include <stdio.h>
//enum Colour
//{
//    red,
//    blue,
//    green
//};
////括号中的 red,blue,green 是枚举常量               
//int main()
//{
//    3.14;                       //字面常量
//    1000;                       //字面常量 
//    const float pai = 3.14f;    //const修饰的常量，默认为double类型，在3.14后加一个小写的f向计算机表示为float类型
//    //pai = 5.14;                 //因为被定义为常量，所以说pai是不能直接修改的，此次修改无效
//#define MAX 100                //#define的标识符常量
//    printf("%d\n", red);
//    printf("%d\n", blue);
//    printf("%d\n", green);
//    return 0;
//}
//
//#include <stdio.h>
//int main()
//{
//	char arr1[] = "hello world";
//	char arr2[] = { 'h', 'e', 'l', 'l', 'o' };
//	char arr3[] = { 'h', 'e', 'l', 'l', 'o','\0' };
//	printf("%s\n", arr1);
//	printf("%s\n", arr2);
//	printf("%s\n", arr3);
//	return 0;
//}


//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	char arr1[] = "hello world";
//	printf("%d\n", strlen(arr1));  //计算字符串长度
//	printf("%d\n", sizeof(arr1));  //计算字符串在内存中包含的字符
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//    printf("c:\code\test.c\n");
//    return 0;
//}
//
//int main()
//{
//	printf("%*.*f\n", 6, 2,0.5);
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int a, b, c;
//	a = 5;
//	c = ++a; //c=6  a=6
//	b = ++c, c++, ++a, a++; // c=7 c=8 a=7 a=8  b=8
//	b += a++ + c;  //a=9 c=8 b=17+8=25
//	printf("a = %d b = %d c = %d\n:", a, b, c); //9 //25 //17
//	return 0;
//}

//#include <stdio.h>
//int num = 10;
//int main()
//{
//    int num = 1;
//    printf("num = %d\n", num);
//    return 0;
//}

//#include <stdio.h>
//int main()
//{
//    int a = 7;
//    int b = 2;
//    float c = 2.0f;
//    printf("%d\n", 3);
//    printf("%f\n", a / c);
//    return 0;
//}

//#include <stdio.h>
//
//int main() {
//    int a = 0;
//    while (scanf("%d", &a) != EOF);
//    if (a >= 140)
//    {
//        printf("Genius\n");
//    }
//    return 0;
//}



#include <stdio.h>

int main() {
    int n = 0;
    while (scanf("%d", &n) != EOF)
    {
        int i = 0;
        for (i = 0; i < n; i++)
        {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}


