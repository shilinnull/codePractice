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
//// ���������C(n, k)
//int combination(int n, int k) {
//    if (k == 0 || k == n)
//        return 1;
//    return combination(n - 1, k - 1) + combination(n - 1, k);
//}
//// ��ӡ�������
//void printYangHuiTriangle(int numRows) {
//    for (int i = 0; i < numRows; i++) {
//        // ��ӡ�ո�ʹ�����ξ���
//        for (int j = 0; j < numRows - i - 1; j++) {
//            printf(" ");
//        }
//        // ��ӡÿ�е�����
//        for (int j = 0; j <= i; j++) {
//            printf("%d ", combination(i, j));
//        }
//        printf("\n");
//    }
//}
//
//int main() {
//    int numRows;
//    printf("������������ǵ�������");
//    scanf("%d", &numRows);
//    printYangHuiTriangle(numRows);
//    return 0;
//}
//
