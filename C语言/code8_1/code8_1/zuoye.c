#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>



/*
��Sn=a+aa+aaa+aaaa+aaaaa��ǰ5��֮�ͣ�����a��һ�����֣�

���磺2+22+222+2222+22222


*/


#include <stdio.h>

int main() 
{
    int a, n, term, sum = 0;

    printf("����������a��");
    scanf("%d", &a);

    n = 5; // ��ǰ5��֮��

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
���0��100000֮������С�ˮ�ɻ������������

��ˮ�ɻ�������ָһ��nλ�������λ���ֵ�n�η�֮��ȷ�õ��ڸ�������
��:153��1^3��5^3��3^3����153��һ����ˮ�ɻ�������
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
//			printf("��ˮ�ɻ���\n");
//		}
//		else
//		{
//			printf("����ˮ�ɻ���\n");
//		}
//	}
//
//	return 0;
//}
//
//








/*
��ӡ����
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
//        printf("���������εĴ�С����������\n");
//        scanf("%d", &n);
//
//        if (n % 2 == 0)
//        {
//            printf("������������С������!\n");
//        }
//        else
//        {
//
//            // ��ӡ�ϰ벿��
//            for (i = 1; i <= n; i += 2) {
//                // ��ӡ�ո�
//                for (space = 0; space < (n - i) / 2; space++) {
//                    printf(" ");
//                }
//
//                // ��ӡ�Ǻ�
//                for (j = 1; j <= i; j++) {
//                    printf("*");
//                }
//
//                printf("\n");
//            }
//
//            // ��ӡ�°벿��
//            for (i = n - 2; i >= 1; i -= 2) {
//                // ��ӡ�ո�
//                for (space = 0; space < (n - i) / 2; space++) {
//                    printf(" ");
//                }
//
//                // ��ӡ�Ǻ�
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
����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ����20Ԫ�����Զ�����ˮ�����ʵ�֣���
*/
//
//int main()
//{
//	int money = 20;//20ƿ��ˮ
//	int bottles = money;//��ʼ��ƿ�����ڽ��
//	int total_drinks = money;//��ʼ��ˮ�������ڽ��
//	while (bottles >= 2)
//	{
//		int drink = bottles / 2;
//		total_drinks += drink;
//		bottles = bottles % 2 + drink;
//	}
//	printf("�ܹ����Թ��� %d ƿ��ˮ\n", total_drinks);
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
//#include <ctype.h>  // ����ctype.hͷ�ļ������ڵ���isdigit����
//
//int main() {
//    char input[100]; // �����������Ϊ99���ַ�
//
//    printf("������һ�����֣�");
//    scanf("%s", input);
//
//    // ����������Ƿ������ĸ
//    int hasLetters = 0;
//    for (int i = 0; input[i] != '\0'; i++) {
//        if (isalpha(input[i])) { // ����ַ�����ĸ
//            hasLetters = 1;
//            break;
//        }
//    }
//
//    if (hasLetters) {
//        printf("�������������ĸ����ֻ�������֡�\n");
//    }
//    else {
//        // ������ת��Ϊ������������ִ�г���
//        int number;
//        sscanf(input, "%d", &number);
//        printf("������������ǣ�%d\n", number);
//        // ���������ִ�г������������...
//    }
//
//    return 0;
//}


