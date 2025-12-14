#pragma once
#define _CRT_SECURE_NO_WARNINGS//防止部分程序因不安全报错
//头文件
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <graphics.h>
#include <conio.h>
#include <time.h>
#include <chrono>
#include <thread>
#include <stdbool.h>
#include <Windows.h>


// 1. 信息存储   基本功能
// 2. 窗口   屏幕


//存储信息结构体定义
typedef struct Message {
	wchar_t NAME[50];//姓名
	wchar_t STREET[50];//街道
	wchar_t CITY[50];//城市
	wchar_t STATE[50];//国家
	wchar_t EIP[50];//邮编
}Message;

//存储结构定义(双向链表)
typedef struct DoubleLink {
	//数据域
	Message* data;
	//指针域
	struct DoubleLink* prev;
	struct DoubleLink* next;
}DLNode;


//基本功能函数声明

//初始化双向链表
DLNode* InitDLink();
//新建节点
DLNode* CreatDLNode(Message* data);
//销毁链表
void DestoryDLink(DLNode* head);
//输入信息
void enter(DLNode* head, Message* data);
//查找信息(名字是key
DLNode** search(DLNode* node, const wchar_t* key);
//删除信息
void Delete(DLNode* cur);
//信息存盘
void save(DLNode* head);
//信息装入
void load(DLNode* head);
//获取链表头部(包括信息装入
DLNode* GetDLinkHead();

//信息结点存储
Message* CreatMessage(const wchar_t* name, const wchar_t* street, const wchar_t* city, const wchar_t* state, const wchar_t* tel);


//窗口结构体
typedef struct ScreenWindow {
	int width;//屏幕宽度
	int height;//屏幕高度
	COLORREF bkColor;//背景颜色
}ScreenWindow;


//屏幕函数声明

//初始化屏幕
void InitScreen(ScreenWindow* Screen);

//屏幕线条布局
void DrawLines(ScreenWindow* Screen);

//信息录入
/*要求实现
* 1.绘制输入背景等布局
* 2.点击按钮触发输入框输入内容,输入完后立即显示,可重复修改
* 3.最后返回信息结构体,并回到主页面
*/
Message* enterMessage(ScreenWindow* Screen, ExMessage* mouse);

//信息录入背景绘制
void enterDrawBG(ScreenWindow* Screen);

//信息显示背景绘制
void displayDrawBG(ScreenWindow* Screen);

//个人信息展示
int displayAllMessage(ScreenWindow* Screen, ExMessage* mouse, DLNode* cur);

//信息显示
void displayMessage(ScreenWindow* Screen, ExMessage* mouse, DLNode* head);

//信息查询背景绘制
void searchDrawBG(ScreenWindow* Screen);
//信息查询
void searchMessage(ScreenWindow* Screen, ExMessage* mouse, DLNode* head);
