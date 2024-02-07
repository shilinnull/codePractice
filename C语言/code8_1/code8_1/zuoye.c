#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>



/*
求Sn=a+aa+aaa+aaaa+aaaaa的前5项之和，其中a是一个数字，

例如：2+22+222+2222+22222


*/


#include <stdio.h>

int main() 
{
    int a, n, term, sum = 0;

    printf("请输入数字a：");
    scanf("%d", &a);

    n = 5; // 求前5项之和

    for (int i = 1; i <= n; i++) 
    {
        term = 0;
        for (int j = 0; j < i; j++) 
        {
            term = term * 10 + a;
        }
        sum += term;
    }

    printf("Sn = %d\n", sum);

    return 0;
}









/*
求出0～100000之间的所有“水仙花数”并输出。

“水仙花数”是指一个n位数，其各位数字的n次方之和确好等于该数本身，
如:153＝1^3＋5^3＋3^3，则153是一个“水仙花数”。
*/

//
//int main()
//{
//	int n = 0;
//
//	while (scanf("%d", &n) != EOF)
//	{
//		int a = n % 10;
//		int b = n / 10 % 10;
//		int c = n / 100;
//		if (((a * a * a) + (b * b * b) + (c * c * c)) == n)
//		{
//			printf("是水仙花数\n");
//		}
//		else
//		{
//			printf("不是水仙花数\n");
//		}
//	}
//
//	return 0;
//}
//
//








/*
打印菱形
*/
//#include <stdio.h>
//
//int main() 
//{
//    int n = 0;
//    int i = 0;
//    int j = 0;
//    int space = 0;
//    while (1)
//    {
//        printf("请输入菱形的大小（奇数）：\n");
//        scanf("%d", &n);
//
//        if (n % 2 == 0)
//        {
//            printf("请输入奇数大小的菱形!\n");
//        }
//        else
//        {
//
//            // 打印上半部分
//            for (i = 1; i <= n; i += 2) {
//                // 打印空格
//                for (space = 0; space < (n - i) / 2; space++) {
//                    printf(" ");
//                }
//
//                // 打印星号
//                for (j = 1; j <= i; j++) {
//                    printf("*");
//                }
//
//                printf("\n");
//            }
//
//            // 打印下半部分
//            for (i = n - 2; i >= 1; i -= 2) {
//                // 打印空格
//                for (space = 0; space < (n - i) / 2; space++) {
//                    printf(" ");
//                }
//
//                // 打印星号
//                for (j = 1; j <= i; j++) {
//                    printf("*");
//                }
//
//                printf("\n");
//            }
//
//        }
//
//    }
//
//
//    return 0;
//}







/*
喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，给20元，可以多少汽水（编程实现）。
*/
//
//int main()
//{
//	int money = 20;//20瓶汽水
//	int bottles = money;//初始空瓶数等于金额
//	int total_drinks = money;//初始汽水总数等于金额
//	while (bottles >= 2)
//	{
//		int drink = bottles / 2;
//		total_drinks += drink;
//		bottles = bottles % 2 + drink;
//	}
//	printf("总共可以购买 %d 瓶汽水\n", total_drinks);
//	return 0;
//}



//int main()
//{
//	int i = 0;
//
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//
//	for (i = 0; i <= 12; i++)
//	{
//		arr[i] = 0;
//		printf("hehe\n");
//	}
//	return 0;
//}
//

//#include <stdio.h>
//#include <ctype.h>  // 包含ctype.h头文件，用于调用isdigit函数
//
//int main() {
//    char input[100]; // 假设输入最多为99个字符
//
//    printf("请输入一个数字：");
//    scanf("%s", input);
//
//    // 检查输入中是否包含字母
//    int hasLetters = 0;
//    for (int i = 0; input[i] != '\0'; i++) {
//        if (isalpha(input[i])) { // 如果字符是字母
//            hasLetters = 1;
//            break;
//        }
//    }
//
//    if (hasLetters) {
//        printf("错误：输入包含字母。请只输入数字。\n");
//    }
//    else {
//        // 将输入转换为整数，并继续执行程序
//        int number;
//        sscanf(input, "%d", &number);
//        printf("您输入的数字是：%d\n", number);
//        // 在这里继续执行程序的其他部分...
//    }
//
//    return 0;
//}


