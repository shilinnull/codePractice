#define _CRT_SECURE_NO_WARNINGS 1


//计算斐波那契数

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
//    printf("请输入n：");
//    scanf("%d", &n);
//
//    int result = fibonacciRecursive(n);
//    printf("第%d个斐波那契数是：%d\n", n, result);
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
//    printf("请输入n：");
//    scanf("%d", &n);
//
//    int result = fibonacciNonRecursive(n);
//    printf("第%d个斐波那契数是：%d\n", n, result);
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
//    printf("请输入n和k：");
//    scanf("%lf %d", &n, &k);
//
//    double result = powerRecursive(n, k);
//    printf("%.2lf的%d次方是：%.2lf\n", n, k, result);
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
//    printf("请输入一个非负整数：");
//    scanf("%d", &num);
//
//    int sum = DigitSum(num);
//    printf("数字之和是：%d\n", sum);
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
//    printf("请输入n：");
//    scanf("%d", &n);
//
//    unsigned long long result = factorialNonRecursive(n);
//    printf("%d的阶乘是：%llu\n", n, result);
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
//    printf("请输入n：");
//    scanf("%d", &n);
//
//    unsigned long long result = factorialNonRecursive(n);
//    printf("%d的阶乘是：%llu\n", n, result);
//
//    return 0;
//}

#include <stdio.h>

void printDigits(int n) {
    if (n < 10) {
        printf("%d ", n); // 打印最后一位数字
    }
    else {
        printDigits(n / 10); // 递归处理剩余的数字
        printf("%d ", n % 10); // 打印最后一位数字
    }
}

int main() {
    int num;
    printf("请输入一个整数：");
    scanf("%d", &num);

    printf("每一位数字：");
    printDigits(num);
    printf("\n");

    return 0;
}
