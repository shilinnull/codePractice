#pragma once
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

//行
#define ROW 3
//列
#define COL 3

//初始化棋盘
void InitBoard(char board[ROW][COL],int row,int col);

//打印棋盘
void DisplayBoard(char board[ROW][COL], int row,int col);

//玩家下棋
void PlayMove(char board[ROW][COL], int row, int col);

//电脑随机下棋
void ComputerMove(char board[ROW][COL], int row, int col);

//判断输赢
char IsWin(char board[ROW][COL], int row, int col);
