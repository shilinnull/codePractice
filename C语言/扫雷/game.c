#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"


void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	for (i = 0; i < rows; i++)
	{
		int j = 0;
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}


void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	printf("--------ɨ����Ϸ-------\n");
	for (i = 0; i <= row; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		int j = 0;
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("--------ɨ����Ϸ-------\n");
}

void SetMine(char mine[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;

	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count--;
		}
	}
}

static int GetMineCount(char mine[ROWS][COLS], int x, int y)
{
	return (mine[x - 1][y] +
		mine[x - 1][y - 1] +
		mine[x][y - 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] +
		mine[x][y + 1] +
		mine[x - 1][y + 1] - 8 * '0');
}


void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0, y = 0, z = 0;
	int win = 0;;// �����ж��Ƿ����е����Ѿ��ž�
	int s = EASY_COUNT;//����
	while (win < (row * col) - s)
	{
		system("cls");
		if (z == 0)
		{
			printf("��Ϸ��ʼ\n");
		}
		if (z > 0)
		{
			printf("\n");
		}
		DisplayBoard(show, ROW, COL);
		printf("������Ҫ�Ų������:>");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{

				system("cls");
				printf("���ź�����ը����!!1\n");
				DisplayBoard(mine, ROW, COL);
				break;
			}
			else
			{
				expand(mine, show, x, y, &win);

				//ͳ����Χ����
				int c = GetMineCount(mine, x, y);
				show[x][y] = c + '0';// �ַ�0ascllΪ48 1Ϊ49 ���ַ����ɴ�ӡ����Χ���ϵ���ص��ַ�
				//ÿ�Ų�һ�δ�ӡһ������
				DisplayBoard(mine, ROW, COL);
				win++;
			}
		}
		else
		{
			printf("����Ƿ�����������\n");
		}
		z++;
	}
	if (win == (row * col) - s)
	{
		printf("��ϲ�㣬���׳ɹ�\n");
		DisplayBoard(mine, ROW, COL);

	}
}


void expand(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y, int* win)
{

	if (x >= 1 && x <= ROW && y >= 1 && y <= COL) //������������չ������ֹԽ��
	{
		int count = GetMineCount(mine, x, y);//��ȡ����

		if (count == 0) //����û�ף�����ݹ�չ��
		{
			show[x][y] = ' ';//����û�׵ĸ�Ϊ �ո�  ' '

			int i = 0;
			//�����ܹ�8��λ�õݹ�
			for (i = x - 1; i <= x + 1; i++)
			{
				int j = 0;
				for (j = y - 1; j <= y + 1; j++)
				{

					//ֻ�� '*' ����չ������ֹ��ѭ��
					if (show[i][j] == '*')
					{
						expand(mine, show, i, j, win);
					}
				}
			}
		}
		else   //����������ʾ����
		{
			show[x][y] = count + '0';
		}
		//��¼չ��������
		(*win)++;
	}
}

