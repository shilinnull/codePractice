#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"


void InitBoard(char board[ROWS][COLS], int rows, int cols, char set) {
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			board[i][j] = set;
		}
	}
}

void DisplayBoard(char board[ROWS][COLS], int row, int col) {
	int i = 0;
	int j = 0;
	printf("---------ɨ��--------\n");
	for (i = 0; i <= col; i++) {
		printf("%d ", i);//��ӡ��
	}
	printf("\n");
	for (i = 1; i <= row; i++) {
		printf("%d ", i);//��ӡ��
		for (j = 1; j <= col; j++) {
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("---------ɨ��--------\n");
}


void SetMine(char mine[ROWS][COLS], int row, int col) {
	int count = EASY_COUNT;
	while (count) {
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if ('0' == mine[x][y])
		{
			mine[x][y] = '1';
			count--;
		}
	}
}

int GetMineCount(char mine[ROWS][COLS],int x, int y) {
	return mine[x - 1][y] +
		mine[x - 1][y - 1] +
		mine[x][y - 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] +
		mine[x][y + 1] +
		mine[x - 1][y + 1] - 8 * '0';
}


void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col) {
	int x = 0;
	int y = 0;
	int win = 0;
	while (win < row * col + EASY_COUNT) {
		printf("���������꣬�����Ų��ף�>");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col) {
			if (show[x][y] != '*'){
				printf("�����걻�Ų��ˣ���������������\n");
			}
			else if ('1' == mine[x][y]) {
				printf("���ź�����ը����!\n");
				DisplayBoard(mine, ROW, COL);
				break;
			}
			else {
				int c = GetMineCount(mine, x, y);
				show[x][y] = c + '0';
				DisplayBoard(show, ROW, COL);
				win++;
			}
		}
		else {
			printf("��������Ƿ�������������!\n");
		}
		if (win == row * col - EASY_COUNT) {
			printf("��ϲ�㣬���׳ɹ�\n");
			DisplayBoard(mine, ROW, COL);
		}
	}
}

