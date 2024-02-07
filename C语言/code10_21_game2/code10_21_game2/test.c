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
	//游戏代码逻辑
	//创建数组
	char mine[ROWS][COLS];
	char show[ROWS][COLS];
	//初始化棋盘
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	DisplayBoard(show, ROW, COL);
	//布置雷
	SetMine(mine, ROW, COL);
	//DisplayBoard(mine, ROW, COL);
	//排查雷
	FindMine(mine,show, ROW, COL);

} 

int main() {
	srand((unsigned int)time(NULL));
	int input = 0;
	do {
		enmu();
		printf("请选择：>");
		scanf("%d", &input);
		switch (input) {
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏");
			break;
		default:
			printf("选择错误，请重新选择!\n");
			break;
		}
	} while (input);
}