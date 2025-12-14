#include "app.h"
#include "widget.h"
#include "ConstData.h"


int main() {
	//屏幕结构体
	ScreenWindow Screen = {
		Screen.width = Screen_Width,		// 400
		Screen.height = Screen_Height,		// 600
		Screen.bkColor = Screen_BKColor,	// RGB(255, 0, 0)
	};

	// 初始化屏幕
	InitScreen(&Screen);

	//鼠标定义
	ExMessage* mouse = (ExMessage*)malloc(sizeof(ExMessage));

	//按钮定义
	Button* btnEnter = Creat_Button(25, 500, 100, 50);				// 信息录入按钮
	Button* btnSearch = Creat_Button(150, 500, 100, 50);			// 信息查询
	Button* btnDispaly = Creat_Button(275, 500, 100, 50);			// 信息显示

	Button* btnClose = Creat_Button(Screen.width - 73, 3, 70, 30);	// 退出

	//获取链表头部
	DLNode* head = GetDLinkHead();
	load(head);		//文件信息导入

	while (true) {
	start:
		setbkcolor(BROWN);	// 设置主界面的背景颜色：棕色
		cleardevice();
		BeginBatchDraw();	// 开启绘图
		DrawLines(&Screen);	// 屏幕线条

		//实现图片加载
		IMAGE img;

		//这里要注意文件路径需要转义 或者直接使用当前目录下的文件即可
		loadimage(&img, _T("all.jpg"), 395, 395, true);
		putimage(3, 50, &img);

		//获取鼠标消息
		getmessage(mouse, EX_MOUSE | EX_WINDOW);	// EX_MOUSE | EX_WINDOW 获取鼠标和窗口消息

		//主页面设置
		//信息录入框
		bool IsEnter = widgetRButton(mouse, btnEnter, L"信息录入");
		if (IsEnter) {
			Message* Info = enterMessage(&Screen, mouse);
			if (Info != NULL) {
				enter(head, Info);
			}
			goto start;
		}
		//搜索框
		bool IsSearch = widgetRButton(mouse, btnSearch, L"信息查询");
		if (IsSearch) {
			searchMessage(&Screen, mouse, head);
			goto start;
		}
		//展示目录框
		bool IsDisplay = widgetRButton(mouse, btnDispaly, L"信息显示");
		if (IsDisplay) {
			displayMessage(&Screen, mouse, head);
			goto start;
		}

		//关闭窗口
		bool IsClosed = widgetRButton(mouse, btnClose, L"退出");
		if (IsClosed) {
			bool result = CloseWindow(mouse);
			if (result)break;
		}

		FlushBatchDraw();		// 刷新绘图
		setFPS(ScreenFPS);		// 设置帧率120
	}

	//文件信息存储
	save(head);
	
	//链表销毁
	DestoryDLink(head);

	//关闭图形化界面
	closegraph();
	return 0;
}