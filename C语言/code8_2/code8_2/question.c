#define _CRT_SECURE_NO_WARNINGS 1


/*
��8��2���ϻ���&ÿ��һ�⡿
��������Ŀ����
��дһ������void StatCharCount(char str[])���ú�������һ���ַ�����Ϊ������
��ͳ�Ƹ��ַ�������ĸ�����֡��ո�������ַ��ĸ�����
��main�������øú������ֱ��ӡ��ĸ�����֡��ո� �� �����ַ��ĳ��ִ�����
������ʾ��һ������ֻ�ܷ���һ��ֵ���˴���ͳ�ƽ����4������˷��ؽ������ʹ��ȫ�ֱ�����������
*/

/*
�˴���ʹ�� fgets ��������ȡ�����ַ������Ա��������ַ���������������С�����⡣
���� StatCharCount ����������ַ���ͳ����ĸ�����֡��ո�������ַ��ĸ�������������洢��ȫ�ֱ����С�
Ȼ��main ������ӡ��Щͳ�ƽ������ȷ���ڵ��� StatCharCount ����֮ǰ�����ȫ�ֱ�������ȷ�������׼ȷ�ԡ�
*/

#include <stdio.h>

// ȫ�ֱ������ڴ洢ͳ�ƽ��
int letterCount = 0;
int digitCount = 0;
int spaceCount = 0;
int otherCount = 0;

// ��������ͳ���ַ����͵ĸ���
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
    char inputString[100]; // ����������ַ������Ȳ�����100

    printf("������һ���ַ���: ");
    fgets(inputString, sizeof(inputString), stdin);

    // ���ȫ�ֱ������Է�ֹǰһ��ͳ�ƵĽ�����ŵ�ǰͳ��
    letterCount = 0;
    digitCount = 0;
    spaceCount = 0;
    otherCount = 0;

    // ���ú�������ͳ��
    StatCharCount(inputString);

    // ��ӡ���
    printf("��ĸ����: %d\n", letterCount);
    printf("���ָ���: %d\n", digitCount);
    printf("�ո����: %d\n", spaceCount);
    printf("�����ַ�����: %d\n", otherCount);

    return 0;
}
