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

    char words[100][100]; // �洢�ַ���������
    int count = 0; // �ַ���������

    char word[100];
    while (fscanf(inputFile, "%s", word) != EOF) {
        strcpy(words[count], word); // ����ȡ���ַ������Ƶ�������
        count++;
    }

    qsort(words, count, sizeof(char[100]), compare); // �������������

    for (int i = 0; i < count; i++) {
        fprintf(outputFile, "%s\n", words[i]); // ���������ַ���д���ļ�
    } 
    fclose(inputFile);
    fclose(outputFile);

    return 0;
}