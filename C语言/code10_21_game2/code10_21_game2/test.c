#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

void enmu() {
	printf("\n");
	printf("***********************\n");
	printf("*******  1.play  ******\n");
	printf("*******  0.exit  ******\n");
	printf("***********************\n");
	printf("\n");
}

void game() {
	//��Ϸ�����߼�
	//��������
	char mine[ROWS][COLS];
	char show[ROWS][COLS];
	//��ʼ������
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	DisplayBoard(show, ROW, COL);
	//������
	SetMine(mine, ROW, COL);
	//DisplayBoard(mine, ROW, COL);
	//�Ų���
	FindMine(mine,show, ROW, COL);

} 

int main() {
	srand((unsigned int)time(NULL));
	int input = 0;
	do {
		enmu();
		printf("��ѡ��>");
		scanf("%d", &input);
		switch (input) {
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ");
			break;
		default:
			printf("ѡ�����������ѡ��!\n");
			break;
		}
	} while (input);
}