#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <assert.h>
/*
打印杨辉三角
*/


//
//int main() {
//    int n = 0;
//    //scanf("%d", &n);
//    int arr[10][10] = { 0 };
//    for (int i = 0; i < 10; i++) {
//        for (int j = 0; j <= i; j++) {
//            if (j == 0 || i == j) {
//                arr[i][j] = 1;
//            }
//            if (i >= 2 && j >= 1) {
//                arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
//            }
//        }
//    }
//    for (int i = 0; i < 10; i++) {
//        for (int j = 0; j <= i; j++) {
//            printf("%5d", arr[i][j]);
//        }
//        printf("\n");
//    }
//    return 0;
//}
//
//int main()
//{
//	//在一个有序数组中查找具体的某个数组n
//	//1 2 3 4 5 6 7 8 9 10
//	
//	//二分查找法
//	int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(a) / sizeof(a[0]);
//	int key = 7;//要查找的数字k
//	int left = 0;
//	int right = sz - 1;
//
//	while (left <= right)
//	{
//		int mid = (left + right) / 2;//中间元素下标一定在循环内部，不断变化
//		if (key < a[mid])
//			right = mid - 1;
//		else if (key > a[mid])
//			left = mid + 1;
//		else
//		{
//			printf("找到了，下标是%d\n", mid);
//			break;		//找到了便跳出循环
//		}
//	}
//	if (left > right)
//		printf("没找到此元素\n");
//	return 0;
//}
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//void menu()
//{
//	printf("\n");
//	printf("********************************\n");
//	printf("**********  1.play  ************\n");
//	printf("**********  0.exit  ************\n");
//	printf("********************************\n");
//	printf("\n");
//}
//void game()
//{
//	int random_num = rand() % 100 + 1;
//	int flag = 10;
//	int input = 0;
//	while (1)
//	{
//		printf("次数还有%d\n", flag);
//
//		printf("请输入猜的数字>:");
//		scanf("%d", &input);
//		if (input > random_num)
//		{
//			printf("猜大了\n");
//			flag--;
//		}
//		else if (input < random_num)
//		{
//			printf("猜小了\n");
//			flag--;
//		}
//		else
//		{
//			printf("恭喜你，猜对了\n");
//			break;
//		}
//		if (flag == 0) {
//			printf("次数用完了，数字是%d", random_num);
//			break;
//		}
//	}
//}
//int main()
//{
//	int input = 0;
//	srand((unsigned int)time(NULL));
//	do
//	{
//		menu();
//		printf("请选择>:");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			game();
//			break;
//		case 0:
//			break;
//		default:
//			printf("选择错误,请重新输入!\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}
//
//int main() {
//	int x = 1;
//	if (x) {
//		printf("hehe");
//	}
//	else {
//		printf("haha");
//	}
//	return 0;
//}

//
//int main() {
//	int s = 0;
//	int i = 1;
//	while (s <= 10) {
//		s = s + i * i;
//		i++;
//	}
//	printf("%d\n", --i);
//	return 0;
//}
int main() {
	int a = 10;
	a = a | 1 << 2;
	printf("%d", a);
	return 0;
}