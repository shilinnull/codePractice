#pragma once

#include <windows.h>
#include <time.h>
#include <stdio.h>

#define KEY_PRESS(VK)  ((GetAsyncKeyState(VK)&0x1) ? 1 : 0)

//����
enum DIRECTION
{
    UP = 1,
    DOWN,
    LEFT,
    RIGHT
};

//��Ϸ״̬
enum GAME_STATUS
{
    OK,//��������
    KILL_BY_WALL,//ײǽ
    KILL_BY_SELF,//ҧ���Լ�
    END_NOMAL//��������
};

#define WALL L'��'
#define BODY L'��'  //����������
#define FOOD L'��'  //����������

//�ߵĳ�ʼλ��
#define POS_X 24
#define POS_Y 5

//����ڵ�
typedef struct SnakeNode
{
    int x;
    int y;
    struct SnakeNode* next;
}SnakeNode, * pSnakeNode;

typedef struct Snake
{
    pSnakeNode _pSnake;//ά�������ߵ�ָ��
    pSnakeNode _pFood;//ά��ʳ���ָ��
    enum DIRECTION _Dir;//��ͷ�ķ���Ĭ��������
    enum GAME_STATUS _Status;//��Ϸ״̬
    int _Socre;//��ǰ��÷���
    int _Add;//Ĭ��ÿ��ʳ��10��
    int _SleepTime;//ÿ��һ������ʱ��
}Snake, * pSnake;



//��Ϸ��ʼǰ�ĳ�ʼ��
void GameStart(pSnake ps);

//��Ϸ���й���
void GameRun(pSnake ps);

//��Ϸ����
void GameEnd(pSnake ps);

//���ù�������
void SetPos(short x, short y);

//��ӭ����
void WelcomeToGame();

//��ӡ������Ϣ
void PrintHelpInfo();

//������ͼ
void CreateMap();

//��ʼ����
void InitSnake(pSnake ps);

//����ʳ��
void CreateFood(pSnake ps);

//��ͣ��Ӧ
void pause();

//��һ���ڵ���ʳ��
int NextIsFood(pSnakeNode psn, pSnake ps);

//��ʳ��
void EatFood(pSnakeNode psn, pSnake ps);

//����ʳ��
void NoFood(pSnakeNode psn, pSnake ps);

//ײǽ���
int KillByWall(pSnake ps);

//ײ������
int KillBySelf(pSnake ps);

//�ߵ��ƶ�
void SnakeMove(pSnake ps);

//��Ϸ��ʼ��
void GameStart(pSnake ps);

//��Ϸ����
void GameRun(pSnake ps);

//��Ϸ����
void GameEnd(pSnake ps);