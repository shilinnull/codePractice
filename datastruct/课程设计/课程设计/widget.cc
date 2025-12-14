#include "app.h"
#include "widget.h"


/*组件开发*/
//按钮组件函数
// 创建按钮
Button* Creat_Button(int x, int y, int width, int height) {
	Button* DefaultButton = (Button*)malloc(sizeof(Button));
	if (DefaultButton == NULL) {
		printf("按钮创建失败!\n");
		return NULL;
	}
	*DefaultButton = {
		DefaultButton->width = width,
		DefaultButton->height = height,
		DefaultButton->round = 1,
		DefaultButton->x = x,
		DefaultButton->y = y,
		DefaultButton->nHeight = 8,
		DefaultButton->nWidth = 0,
		DefaultButton->textColor = RGB(0,0,0),
		DefaultButton->PColor = RGB(255,255,255),
		DefaultButton->NColor = RGB(156,153,153),
		DefaultButton->textSytle = L"黑体",
		DefaultButton->clicked = false,
		DefaultButton->reach = false,
	};
	return DefaultButton;
}
// 创建按钮(文体大小
Button* Creat_Button(int x, int y, int width, int height, int nHeight, int nWidth) {
	Button* DefaultButton = (Button*)malloc(sizeof(Button));
	if (DefaultButton == NULL) {
		printf("按钮创建失败!\n");
		return NULL;
	}
	*DefaultButton = {
		DefaultButton->width = width,
		DefaultButton->height = height,
		DefaultButton->round = 1,
		DefaultButton->x = x,
		DefaultButton->y = y,
		DefaultButton->nHeight = nHeight,
		DefaultButton->nWidth = nWidth,
		DefaultButton->textColor = RGB(0,0,0),
		DefaultButton->PColor = RGB(255,255,255),
		DefaultButton->NColor = RGB(156,153,153),
		DefaultButton->textSytle = L"黑体",
		DefaultButton->clicked = false,
		DefaultButton->reach = false,
	};
	return DefaultButton;
}

//方形按钮
bool widgetRButton(ExMessage* mouse, Button* b, const wchar_t* str) {
	if (b->clicked == false) {
		setfillcolor(b->PColor);	// 设置按钮点击前的颜色
	}
	else {
		setfillcolor(b->NColor);	// 设置按钮点击后的颜色
	}

	if (b->reach) {	// 检测鼠标是否在按钮上
		setlinecolor(RGB(61, 243, 241));
		setlinestyle(PS_SOLID, 2);
	}
	else {
		setlinecolor(NULL);
		setlinestyle(NULL);
	}
	setbkmode(TRANSPARENT);		// 设置背景透明
	settextcolor(b->textColor);	// 设置文本颜色
	settextstyle(b->nHeight, b->nWidth, b->textSytle);	// 设置文本样式宽高
	//创建组件
	fillrectangle(b->x, b->y, b->x + b->width, b->y + b->height);
	//文体居中
	RECT position = {
		position.left = b->x,
		position.top = b->y,
		position.right = b->x + b->width,
		position.bottom = b->y + b->height,
	};
	drawtext(str, &position, DT_CENTER | DT_VCENTER | DT_WORD_ELLIPSIS | DT_SINGLELINE);//wcslen()用于处理宽字符的长度

	//鼠标交互事件
	//if (peekmessage(mouse, EX_MOUSE, true)) {

	//判断区域以及是否点击鼠标
	if (mouse->x > position.left && mouse->x<position.right && mouse->y>position.top && mouse->y < position.bottom) {
		//左键被点击
		if (mouse->message == WM_LBUTTONDOWN && b->clicked == false) {
			//更换背景颜色
			b->clicked = true;
			printf("左键被点击\n");
			//一定要记得重置
			mouse->message = NULL;
			return true;
		}
		else if (mouse->message == WM_LBUTTONUP) {
			//鼠标弹起
			b->clicked = false;
		}
		else {
			//鼠标到达
			b->reach = true;
		}
	}
	else {
		//离开按钮区域
		b->clicked = false;
		b->reach = false;
		//清空鼠标消息
		flushmessage(EX_MOUSE);
	}
	//}
	return false;
}
//圆形按钮  和方形有一点不同
bool widgetCButton(ExMessage* mouse, Button* b, const wchar_t* str, int round) {
	//修改Button的值
	b->width = round;
	b->height = round;

	if (b->clicked == false) {
		setfillcolor(b->PColor);
	}
	else {
		setfillcolor(b->NColor);
	}
	if (b->reach) {
		setlinecolor(RGB(61, 243, 241));
		setlinestyle(PS_SOLID | PS_ENDCAP_ROUND, 2);
	}
	else {
		setlinecolor(NULL);
		setlinestyle(NULL);
	}
	setbkmode(TRANSPARENT);
	settextcolor(b->textColor);
	settextstyle(b->nHeight, b->nWidth, b->textSytle);
	//创建组件
	fillcircle(b->x, b->y, round);
	RECT position = {
		position.left = b->x - b->width,
		position.top = b->y - b->height,
		position.right = b->x + b->width,
		position.bottom = b->y + b->height,
	};
	drawtext(str, &position, DT_CENTER | DT_VCENTER | DT_WORD_ELLIPSIS | DT_SINGLELINE);//wcslen()用于处理宽字符的长度
	//鼠标交互事件
	//if (peekmessage(mouse, EX_MOUSE, true)) {
		//判断区域以及是否点击鼠标
	if (mouse->x > position.left && mouse->x<position.right && mouse->y>position.top && mouse->y < position.bottom) {
		//左键被点击
		if (mouse->message == WM_LBUTTONDOWN && b->clicked == false) {
			//更换背景颜色
			b->clicked = true;
			printf("左键被点击\n");
			//一定要记得重置
			mouse->message = NULL;
			return true;
		}
		else if (mouse->message == WM_LBUTTONUP) {
			//鼠标弹起
			b->clicked = false;
		}
		else {
			//鼠标到达
			b->reach = true;
		}
	}
	else {
		//离开按钮区域
		b->clicked = false;
		b->reach = false;
		//清空鼠标消息
		flushmessage(EX_MOUSE);
	}
	//}
	return false;
}
//刷新帧率
void setFPS(int fps) {
	static std::chrono::steady_clock::time_point lastUpdateTime = std::chrono::steady_clock::now();	// 上次更新时间点

	int millisecondsPerFrame = 1000 / fps;	// 每帧所需的毫秒数
	std::chrono::steady_clock::time_point currentTime = std::chrono::steady_clock::now();	// 当前时间点
	std::chrono::duration<int, std::milli> elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - lastUpdateTime);	// 计算已过去的时间

	if (elapsedTime.count() < millisecondsPerFrame) {	// 如果已过去的时间小于每帧所需的时间
		// 休眠以补足时间
		std::this_thread::sleep_for(std::chrono::milliseconds(millisecondsPerFrame - elapsedTime.count()));
	}
	lastUpdateTime = std::chrono::steady_clock::now();	// 更新上次更新时间点
}

//输入框组件
//创建输入框
Input_Box* Creat_InputBox(int width, int height) {
	Input_Box* box = (Input_Box*)malloc(sizeof(Input_Box));
	if (box == NULL) {
		printf("输入框创建失败!\n");
		return NULL;
	}
	*box = {
		box->pString = NULL,
		box->nMaxCount = 100,
		box->pPrompt = L"请输入数值",
		box->pTitle = L"输入框",
		box->pDefault = NULL,
		box->width = width,
		box->height = height,
		box->bHideCancelBtn = true,
	};
	return box;
}
//输入框设定(默认和高级)
wchar_t* widgetInputBox() {
	Input_Box* box = Creat_InputBox(InputBox_Width, InputBox_Height);
	wchar_t* str = (wchar_t*)malloc(sizeof(wchar_t) * box->nMaxCount);
	InputBox(str, box->nMaxCount, box->pPrompt, box->pTitle, box->pDefault, box->width, box->height, box->bHideCancelBtn);
	return str;
}
wchar_t* widgetInputBox(const wchar_t* pPrompt, const wchar_t* pTitle) {
	Input_Box* box = Creat_InputBox(100, 50);
	wchar_t* str = (wchar_t*)malloc(sizeof(wchar_t) * box->nMaxCount);
	InputBox(str, box->nMaxCount, pPrompt, pTitle, box->pDefault, box->width, box->height, box->bHideCancelBtn);
	return str;
}


//按钮输入框结合
wchar_t* ButtonInputRBox(ExMessage* mouse, Button* b, const wchar_t* str) {
	bool Isclick = widgetRButton(mouse, b, str);
	if (Isclick) {
		wchar_t* result = widgetInputBox();
		return result;
	}
	return NULL;
}
wchar_t* ButtonInputRBox(ExMessage* mouse, Button* b, const wchar_t* str, const wchar_t* pPrompt, const wchar_t* pTitle) {
	bool Isclick = widgetRButton(mouse, b, str);
	if (Isclick) {
		wchar_t* result = widgetInputBox(pPrompt, pTitle);
		return result;
	}
	return NULL;
}
wchar_t* ButtonInputCBox(ExMessage* mouse, Button* b, const wchar_t* str, int round) {
	bool Isclick = widgetCButton(mouse, b, str, round);
	if (Isclick) {
		wchar_t* result = widgetInputBox();
		return result;
	}
	return NULL;
}

//标签Lable
void widgetLable(int x, int y, int width, int height, const wchar_t* str, COLORREF BgColor) {
	//设定文体和方框
	settextstyle(height / 2, 0, NULL);
	setbkmode(TRANSPARENT);
	settextcolor(NULL);
	setlinestyle(PS_NULL);
	if (BgColor == NULL) {
		setfillcolor(WHITE);
	}
	else {
		setfillcolor(BgColor);
	}
	//逻辑关系
	fillrectangle(x, y, x + width, y + height);

	//文体居中
	RECT position = {
		position.left = x,
		position.top = y,
		position.right = x + width,
		position.bottom = y + height,
	};
	drawtext(str, &position, DT_CENTER | DT_VCENTER | DT_WORD_ELLIPSIS | DT_SINGLELINE);//wcslen()用于处理宽字符的长度
	//恢复默认设置
}


//图片组件(原生就好用,就不封装了
//getimage() 一般用于切割图片显示
//loadimage() 加载资源图片(建议定义在全局变量
//putimage()  绘制图片


//字符转数字
//int r = _wtoi(s);

//窗口关闭函数
bool CloseWindow(ExMessage* mouse) {
	//窗口句柄
	HWND hWnd = GetHWnd();
	int result = MessageBox(hWnd, L"是否关闭窗口", L"提示", MB_OKCANCEL | MB_ICONASTERISK | MB_APPLMODAL);
	if (result == IDOK) {
		return true;
	}
	return false;
}