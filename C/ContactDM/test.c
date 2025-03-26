#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void* a, const void* b) {
    return strcmp(*(const char**)a, *(const char**)b);
}

int main() {
    FILE* inputFile = fopen("input.txt", "r");
    FILE* outputFile = fopen("output.txt", "w");

    if (inputFile == NULL || outputFile == NULL) {
        printf("Failed to open file.\n");
        return 1;
    }

    char words[100][100]; // 存储字符串的数组
    int count = 0; // 字符串的数量

    char word[100];
    while (fscanf(inputFile, "%s", word) != EOF) {
        strcpy(words[count], word); // 将读取的字符串复制到数组中
        count++;
    }

    qsort(words, count, sizeof(char[100]), compare); // 对数组进行排序

    for (int i = 0; i < count; i++) {
        fprintf(outputFile, "%s\n", words[i]); // 将排序后的字符串写入文件
    } 
    fclose(inputFile);
    fclose(outputFile);

    return 0;
}