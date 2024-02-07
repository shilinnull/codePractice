#include "add.h"

// #define INT_PTR int*
// typedef int*int_ptr;
// INT_PTR a,b;
// int_ptr c,d;

// int main()
// {
// 	int a = 10;
// 	int b = 20;

// 	int c = Add(a, b);
// 	printf("c = %d\n", c);
// 	return 0;
// }
// int main()
// {
// 	printf("%s\n", __FILE__);		//进行编译的源文件
// 	printf("%d\n", __LINE__);		//文件当前的行号
// 	printf("%s\n", __DATE__);		//被编译的日期
// 	printf("%s\n", __TIME__);		//被编译的时间
// 	printf("%s\n", __STDC__);		//因VS2019没有遵循ANSI C --> 报错
// 	return 0;
// }


// #define MAX 100
// int main()
// {
// 	int flag = 0;
// 	int max;
// 	if (flag)
// 		max = MAX;
// 	else
// 		max = 0;

// 	return 0;
// }

/*宏*/
// #define SQUARE(x) x * x
// #define SQUARE(x) (x) * (x)		//加上括号避免运算优先级
// #define DOUBLE(x) (x) + (x)		//计算一个数的两倍
// #define DOUBLE(x) ((x) + (x))		//在外面再加一个括号即可


// /*函数*/
// int GetSquare(int x)		
// {
// 	return x * x;
// }

// int main()
// {
// 	int x = 5;
// 	//int ret = GetSquare(x);
// 	// int ret = SQUARE(x);
//     // int ret = SQUARE(5 + 1);
//     int ret = 10 * DOUBLE(5);		//10 * (5 + 5) = 100

// 	printf("ret = %d\n", ret);

// 	return 0;
// }


// int main()
// {
//     // printf("hello word\n");
//     // printf("hello ""word\n");
//     // int a = 10;
//     // printf("the value of a is %d\n", a);

//     // char b = 'x';                                                                                     
//     // printf("the value of b is %c\n", b);

//     // float c = 3.14f;
//     // printf("the value of c is %f\n", c);

//     return 0;
// }

// #define PRINT(value, format) printf("the value is " format "\n", value)
// #define PRINT(value, format) printf("the value of "#value" is " format "\n", value);
// int main()
// {
//     int a = 10;
//     PRINT(a, "%d");

//     return 0;
// }

// #define CAT(A, B) A##B

// int main()
// {
//     int CentOS = 7;
//     printf("%d\n", CAT(Cent, OS));
//     return 0;
// }

// #define MAX(a, b) ((a) > (b) ? (a) : (b))
// int main()
// {
// 	int a = 3;
// 	int b = 4;
// 	int max = 0;

// 	max = MAX(++a, ++b);
// 	printf("max = %d, a = %d, b = %d\n", max, a, b);  
// }


// int main()
// {
//     int a = 1;
//     int b = a+1;
//     printf("a = %d,b = %d\n",a,b);

//     int c = 1;
//     int d = ++c;
//     printf("c = %d,d = %d\n",c,d);
//     return 0;
// }

// #include <stdio.h>

// int main()
// {
//   int a[sz];
//     int i = 0;
//   for(i = 0; i < sz; ++i)
//     {
//         a[i] = i;
//   }
                                                                                                    
//   for(i = 0; i < sz; ++i)
//     {
//         printf("%d ", a[i]);
//     }
//     printf("\n");

//     return 0;
// }
// #include <stdio.h>
// #define __DEBUG__
// int main()
// {
// 	int i = 0;
// 	int arr[10] = { 0 };
// 	for (i = 0; i < 10; i++)
// 	{
// 		arr[i] = i;
// #ifdef __DEBUG__
// 		printf("%d\n", arr[i]);//为了观察数组是否赋值成功。
// #endif //__DEBUG__
// 	}
// 	return 0;
// }

// int main()
// {
//     printf("haha");
// #if 1>2
//     printf("haha\n");
// #elif 
//     return 0;
// }

#include "add.h"
#include "add.h"
#include "add.h"
#include "add.h"
#include "add.h"

#include <stdio.h>                                                   
int main()
{
   printf("haha\n");
   return 0;
}