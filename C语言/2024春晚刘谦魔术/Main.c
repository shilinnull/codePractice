#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main()
{
    srand((unsigned int)time(NULL));
    while (1)
    {
        //任意选四张牌
        int card[4];
        printf("请输入四个牌的数字:>");
        for (int i = 0; i < 4; i++)
        {
            scanf("%d", &card[i]);
        }
        int cardend[8];
        for (int i = 0; i < 4; i++)
        {
            cardend[i] = card[i];
        }
        for (int i = 4; i < 8; i++)
        {
            cardend[i] = card[i - 4];
        }
        //报名字字数
        printf("请输入名字个数:>");
        //有几个名字往后挪几张
        int name = 0;
        scanf("%d", &name);
        int x = 0;
        for (int i = 0; i < name; i++)
        {
            x = cardend[0];
            for (int j = 0; j < 7; j++)
            {
                cardend[j] = cardend[j + 1];
            }
            cardend[7] = x;
        }
        //最上面三张插到中间位置
        //取随机数进行处理保证插的位置随机
        //此时剩五张牌，有四个位置
        int cardmove[8];
        int where = rand() % 4;
        where++;
        for (int i = 0; i < where; i++)
        {
            cardmove[i] = cardend[i + 3];
        }
        int num = 0;
        for (int i = where; i < where + 3; i++)
        {
            cardmove[i] = cardend[num];
            num++;
        }
        int end = 7;
        for (int i = 0; i < 5 - where; i++)
        {
            cardmove[end] = cardend[end];
            end--;
        }
        //第一张牌
        printf("藏起来的牌为%d\n", cardmove[0]);
        cardmove[0] = 0;
        for (int i = 0; i < 7; i++)
        {
            cardmove[i] = cardmove[i + 1];
        }
        //南方人输入1，北方人输入2,不确定3张
        printf("南方人输入1，北方人输入2,不确定3张:>");
        int place = 0;
        scanf("%d", &place);
        for (int i = 0; i < 8; i++)
        {
            cardend[i] = cardmove[i];
        }
        if (place == 1)
        {
            int where1 = rand() % 1;
            where1++;
            for (int i = 0; i < where1; i++)
            {
                cardmove[i] = cardend[i + 1];
            }
            int num = 0;
            for (int i = where1; i < where1 + 1; i++)
            {
                cardmove[i] = cardend[num];
                num++;
            }
            int end = 7;
            for (int i = 0; i < 6 - where1; i++)
            {
                cardmove[end] = cardend[end];
                end--;
            }
        }
        if (place == 2)
        {
            int where2 = rand() % 2;
            where2++;
            for (int i = 0; i < where2; i++)
            {
                cardmove[i] = cardend[i + 2];
            }
            int num = 0;
            for (int i = where2; i < where2 + 2; i++)
            {
                cardmove[i] = cardend[num];
                num++;
            }
            int end = 7;
            for (int i = 0; i < 5 - where2; i++)
            {
                cardmove[end] = cardend[end];
                end--;
            }
        }

        if (place == 3)
        {
            int where3 = rand() % 3;
            where3++;
            for (int i = 0; i < where3; i++)
            {
                cardmove[i] = cardend[i + 3];
            }

            int num = 0;
            for (int i = where3; i < where3 + 3; i++)
            {
                cardmove[i] = cardend[num];
                num++;
            }

            int end = 7;
            for (int i = 0; i < 4 - where3; i++)
            {
                cardmove[end] = cardend[end];
                end--;
            }
        }

        //男女
        printf("男生拿一张，女生拿两张:>");
        int sex = 0;
        scanf("%d", &sex);
        for (int i = 0; i < sex; i++)
        {
            cardmove[i] = 0;
        }
        int numbercard = 8 - sex;

        //见证奇迹的时刻挪七张
        printf("见证奇迹的时刻\n");
        int magic = 7;
        for (int i = 0; i < magic; i++)
        {
            int first = cardmove[0];
            for (int j = 0; j < numbercard; j++)
            {
                cardmove[j] = cardmove[j + 1];
            }
            cardmove[numbercard - 1] = first;
        }
        //扔牌
        int flag = 1;
        while (numbercard > 1)
        {
            if (flag > numbercard)
            {
                flag -= numbercard;
            }
            while (cardmove[flag] == 0)
            {
                flag++;
            }
            cardmove[flag - 1] = 0;
            printf("好运留下来\n");
            printf("烦恼丢出去\n");
            numbercard--;
        }
        int endcard = 0;
        for (int i = 0; i < 7; i++)
        {
            if (cardmove[i] != 0)
            {
                endcard = cardmove[i];
            }
        }
        printf("剩下的第一张为%d\n", endcard);
    }
}

