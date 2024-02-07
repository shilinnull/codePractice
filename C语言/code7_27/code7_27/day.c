#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>


int main()
{
	int i = 0;
	int j = 0;
	int arr[10][10] = { 0 };
	for (i = 0; i <= 10; i++)
	{

		for (j = 0; j <= i; j++)
		{
			if (j == 0 || i == j)
			{
				arr[i][j] = 1;
			}
			else
			{
				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
			}
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}



























//
//#include <stdio.h>
//// 计算组合数C(n, k)
//int combination(int n, int k) {
//    if (k == 0 || k == n)
//        return 1;
//    return combination(n - 1, k - 1) + combination(n - 1, k);
//}
//// 打印杨辉三角
//void printYangHuiTriangle(int numRows) {
//    for (int i = 0; i < numRows; i++) {
//        // 打印空格，使三角形居中
//        for (int j = 0; j < numRows - i - 1; j++) {
//            printf(" ");
//        }
//        // 打印每行的数字
//        for (int j = 0; j <= i; j++) {
//            printf("%d ", combination(i, j));
//        }
//        printf("\n");
//    }
//}
//
//int main() {
//    int numRows;
//    printf("请输入杨辉三角的行数：");
//    scanf("%d", &numRows);
//    printYangHuiTriangle(numRows);
//    return 0;
//}
//
