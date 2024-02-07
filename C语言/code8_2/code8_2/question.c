#define _CRT_SECURE_NO_WARNINGS 1


/*
【8月2日上机打卡&每日一题】
【今日题目】：
编写一个函数void StatCharCount(char str[])，该函数接收一个字符串作为参数，
请统计该字符串中字母、数字、空格和其他字符的个数，
在main函数调用该函数，分别打印字母、数字、空格 和 其他字符的出现次数。
返回提示：一个函数只能返回一个值，此处的统计结果有4个，因此返回结果可以使用全局变量带出来。
*/

/*
此代码使用 fgets 函数来读取输入字符串，以避免输入字符串超过缓冲区大小的问题。
函数 StatCharCount 会根据输入字符串统计字母、数字、空格和其他字符的个数，并将结果存储在全局变量中。
然后，main 函数打印这些统计结果。请确保在调用 StatCharCount 函数之前先清空全局变量，以确保结果的准确性。
*/

#include <stdio.h>

// 全局变量用于存储统计结果
int letterCount = 0;
int digitCount = 0;
int spaceCount = 0;
int otherCount = 0;

// 函数用于统计字符类型的个数
void StatCharCount(char str[]) {
    int i = 0;
    while (str[i] != '\0') {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {
            letterCount++;
        }
        else if (str[i] >= '0' && str[i] <= '9') {
            digitCount++;
        }
        else if (str[i] == ' ') {
            spaceCount++;
        }
        else {
            otherCount++;
        }
        i++;
    }
}

int main() {
    char inputString[100]; // 假设输入的字符串长度不超过100

    printf("请输入一个字符串: ");
    fgets(inputString, sizeof(inputString), stdin);

    // 清空全局变量，以防止前一次统计的结果干扰当前统计
    letterCount = 0;
    digitCount = 0;
    spaceCount = 0;
    otherCount = 0;

    // 调用函数进行统计
    StatCharCount(inputString);

    // 打印结果
    printf("字母个数: %d\n", letterCount);
    printf("数字个数: %d\n", digitCount);
    printf("空格个数: %d\n", spaceCount);
    printf("其他字符个数: %d\n", otherCount);

    return 0;
}
