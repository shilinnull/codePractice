#define _CRT_SECURE_NO_WARNINGS 1


//����쳲�������

//
//#include <stdio.h>
//
//int fibonacciRecursive(int n) {
//    if (n <= 1)
//        return n;
//    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
//}
//
//int main() {
//    int n;
//    printf("������n��");
//    scanf("%d", &n);
//
//    int result = fibonacciRecursive(n);
//    printf("��%d��쳲��������ǣ�%d\n", n, result);
//
//    return 0;
//}
//
//#include <stdio.h>
//
//int fibonacciNonRecursive(int n) {
//    if (n <= 1)
//        return n;
//
//    int prev = 0;
//    int curr = 1;
//    int next;
//
//    for (int i = 2; i <= n; i++) {
//        next = prev + curr;
//        prev = curr;
//        curr = next;
//    }
//
//    return curr;
//}
//
//int main() {
//    int n;
//    printf("������n��");
//    scanf("%d", &n);
//
//    int result = fibonacciNonRecursive(n);
//    printf("��%d��쳲��������ǣ�%d\n", n, result);
//
//    return 0;
//}
//


//
//#include <stdio.h>
//
//double powerRecursive(double n, int k) {
//    if (k == 0)
//        return 1.0;
//    else if (k > 0)
//        return n * powerRecursive(n, k - 1);
//    else
//        return 1.0 / (n * powerRecursive(n, -k - 1));
//}
//
//int main() {
//    double n;
//    int k;
//    printf("������n��k��");
//    scanf("%lf %d", &n, &k);
//
//    double result = powerRecursive(n, k);
//    printf("%.2lf��%d�η��ǣ�%.2lf\n", n, k, result);
//
//    return 0;
//}

//#include <stdio.h>
//
//int DigitSum(int n) {
//    if (n < 10)
//        return n;
//    else
//        return n % 10 + DigitSum(n / 10);
//}
//
//int main() {
//    int num;
//    printf("������һ���Ǹ�������");
//    scanf("%d", &num);
//
//    int sum = DigitSum(num);
//    printf("����֮���ǣ�%d\n", sum);
//
//    return 0;
//}



//#include <stdio.h>
//
//unsigned long long factorialNonRecursive(int n) {
//    unsigned long long result = 1;
//    for (int i = 2; i <= n; i++) {
//        result *= i;
//    }
//    return result;
//}
//
//int main() {
//    int n;
//    printf("������n��");
//    scanf("%d", &n);
//
//    unsigned long long result = factorialNonRecursive(n);
//    printf("%d�Ľ׳��ǣ�%llu\n", n, result);
//
//    return 0;
//}

//
//#include <stdio.h>
//
//unsigned long long factorialNonRecursive(int n) {
//    unsigned long long result = 1;
//    for (int i = 2; i <= n; i++) {
//        result *= i;
//    }
//    return result;
//}
//
//int main() {
//    int n;
//    printf("������n��");
//    scanf("%d", &n);
//
//    unsigned long long result = factorialNonRecursive(n);
//    printf("%d�Ľ׳��ǣ�%llu\n", n, result);
//
//    return 0;
//}

#include <stdio.h>

void printDigits(int n) {
    if (n < 10) {
        printf("%d ", n); // ��ӡ���һλ����
    }
    else {
        printDigits(n / 10); // �ݹ鴦��ʣ�������
        printf("%d ", n % 10); // ��ӡ���һλ����
    }
}

int main() {
    int num;
    printf("������һ��������");
    scanf("%d", &num);

    printf("ÿһλ���֣�");
    printDigits(num);
    printf("\n");

    return 0;
}
