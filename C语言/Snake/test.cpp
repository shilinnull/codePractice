#define _CRT_SECURE_NO_WARNINGS 1
#include "Snake.h"
#include <locale.h>

void test()
{
    int ch = 0;
    srand((unsigned int)time(NULL));

    do
    {
        Snake snake = { 0 };
        GameStart(&snake);
        GameRun(&snake);
        GameEnd(&snake);
        SetPos(20, 15);
        printf("����һ����(Y/N):");
        ch = getchar();
        getchar();//����\n

    } while (ch == 'Y');
    SetPos(0, 27);
}

int main()
{
    //�޸ĵ�ǰ����Ϊ����ģʽ��Ϊ��֧�����Ŀ��ַ��Ĵ�ӡ
    setlocale(LC_ALL, "");
    //�����߼�
    test();
    return 0;
}