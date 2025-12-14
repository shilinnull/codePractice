#pragma once
#include "app.h"
#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <chrono>
#include <thread>
#include <stdbool.h>

//组件常量定义

//输入框默认大小
const int InputBox_Width = 150;
const int InputBox_Height = 100;


/*组件制作*/
/*组件结构体定义*/
//按钮结构体
typedef struct Button {
	int width;		//按钮宽度
	int height;		//按钮高度
	int round;		//按钮半径
	int x;			//按钮横坐标
	int y;			//按钮纵坐标
	int nWidth;		//文字宽度
	int nHeight;	//文字高度
	COLORREF textColor;	//文本颜色
	COLORREF PColor;	//按钮点击前颜色
	COLORREF NColor;	//按钮点击后颜色
	const wchar_t* textSytle;	//按钮字体样式
	bool clicked;	//按钮是否点击
	bool reach;		//鼠标是否在按钮上
}Button;


//输入框结构体
typedef struct Input_Box {
	wchar_t* pString;		//输入结果存储
	int		nMaxCount;		//最大输入字符数
	const wchar_t* pPrompt;	//提示信息
	const wchar_t* pTitle;	//标题
	const wchar_t* pDefault;//默认值
	int		width;			//宽度
	int		height;			//高度
	bool	bHideCancelBtn;	//是否隐藏取消按钮
}Input_Box;


/*组件函数*/

//按钮组件函数
Button* Creat_Button(int x, int y, int width, int height);
Button* Creat_Button(int x, int y, int width, int height, int nHeight, int nWidth);
bool widgetRButton(ExMessage* mouse, Button* b, const wchar_t* str);			//方形按钮
bool widgetCButton(ExMessage* mouse, Button* b, const wchar_t* str, int round); //圆形按钮

//输入框组件函数
Input_Box* Creat_InputBox(int width, int height);	// 创建输入框
wchar_t* widgetInputBox(); //默认
wchar_t* widgetInputBox(const wchar_t* pPrompt, const wchar_t* pTitle);//高级


//按钮输入框结合
wchar_t* ButtonInputRBox(ExMessage* mouse, Button* b, const wchar_t* str);//方的
wchar_t* ButtonInputRBox(ExMessage* mouse, Button* b, const wchar_t* str, const wchar_t* pPrompt, const wchar_t* pTitle);
wchar_t* ButtonInputCBox(ExMessage* mouse, Button* b, const wchar_t* str, int round);//圆的

//标签Lable
void widgetLable(int x, int y, int width, int height, const wchar_t* str, COLORREF BgColor);

//窗口关闭函数
bool CloseWindow(ExMessage* mouse);

//帧数限定
void setFPS(int fps);