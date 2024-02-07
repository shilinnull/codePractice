#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 9
#define COL 9

//要布置的雷个数
#define EASY_COUNT 10


#define ROWS ROW+2
#define COLS COL+2

//初始化数组
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);

//打印
void DisplayBoard(char board[ROWS][COLS], int row, int col);

//布置雷
void SetMine(char mine[ROWS][COLS], int row, int col);

//排查雷

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);

