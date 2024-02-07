#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

#define EASY_COUNT 10


//函数的声明

//初始化棋盘
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);

//打印棋盘的
void DisplayBoard(char board[ROWS][COLS], int rows, int cols);

//布置雷
void SetMine(char mine[ROWS][COLS], int row, int col);

//排查雷
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);

