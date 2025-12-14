#include "app.h"
#include "widget.h"

const int ScreenFPS = 120;

//初始化双向链表
DLNode* InitDLink() {
	DLNode* head = (DLNode*)malloc(sizeof(DLNode));
	if (head == NULL) {
		printf("head 空间申请失败!\n");
		return NULL;
	}
	head->data = NULL;
	head->next = head;
	head->prev = head;

	return head;
}
//新建节点
DLNode* CreatDLNode(Message* data) {
	DLNode* node = (DLNode*)malloc(sizeof(DLNode));
	if (node == NULL) {
		printf("node 空间申请失败!\n");
		return NULL;
	}
	node->data = data;
	node->next = NULL;
	node->prev = NULL;

	return node;
}
//销毁链表
void DestoryDLink(DLNode* head) {
	DLNode* cur = head->next;
	DLNode* next = cur;
	while (cur != head) {
		next = cur->next;
		free(cur);
		cur = next;
	}
}
//输入信息
void enter(DLNode* head, Message* data) {
	DLNode* node = CreatDLNode(data);

	//拼接到head的后面
	DLNode* head_Prev = head->prev;

	//连接
	head->prev = node;
	node->next = head;
	node->prev = head_Prev;
	head_Prev->next = node;
}
//查找信息(名字是key
DLNode** search(DLNode* node, const wchar_t* key) {
	//初始化数组
	const int maxNum = 20;
	DLNode** Arrbtn = (DLNode**)malloc(sizeof(DLNode*)* maxNum);
	for (int i = 0; i < maxNum; i++) {
		Arrbtn[i] = nullptr;
	}
	DLNode* cur = node->next;
	int count = 0;

	while (cur != node) {
		if (wcscmp(cur->data->NAME, key) == 0) {	// wcscmp用于比较宽字节字符串
			Arrbtn[count] = cur;
			count++;
		}
		cur = cur->next;
	}
	return Arrbtn;
}
//删除信息
void Delete(DLNode* cur) {

	cur->prev->next = cur->next;
	cur->next->prev = cur->prev;

	free(cur);
	*&cur = NULL;
}
//信息存盘
void save(DLNode* head) {
	FILE* fp;
	wchar_t filename[] = L"Info.txt";
	wchar_t mode[] = L"w,ccs=UTF-16LE"; // 指定UTF-16小端字节序

	fp = _wfopen(filename, mode);
	if (fp == NULL) {
		fwprintf(stderr, L"无法打开文件!\n");
		exit(-1);
	}

	DLNode* cur = head->next; // 跳过头节点

	while (cur != head) {
		if (fwprintf(fp, L"%ls\t%ls\t%ls\t%ls\t%ls\n", cur->data->NAME, cur->data->STREET, cur->data->CITY, cur->data->STATE, cur->data->EIP) < 0) {
			printf("无法写入数据!\n");
			exit(-1);
		}
		cur = cur->next;
	}

	fclose(fp); // 关闭文件
}
//信息装入
void load(DLNode* head) {
	FILE* fp = NULL;
	wchar_t filename[] = L"Info.txt";
	wchar_t mode[] = L"r,ccs=UTF-16LE"; // 指定UTF-16小端字节序

	fp = _wfopen(filename, mode);	// _wfopen用于打开宽字符文件
	if (fp == NULL) {
		fwprintf(stderr, L"无法打开文件!\n");		// 写入到标准错误输出
		exit(-1);
	}

	DLNode* cur = head;

	// 读取文件内容并创建链表节点
	while (!feof(fp)) {
		Message* Newnode = (Message*)malloc(sizeof(Message));
		if (Newnode == NULL) {
			printf("创建新节点失败!\n");
			exit(-1);
		}

		if (fwscanf(fp, L"%ls\t%ls\t%ls\t%ls\t%ls\n", Newnode->NAME, Newnode->STREET, Newnode->CITY, Newnode->STATE, Newnode->EIP) != 5) {
			printf("读取数据错误!\n");
			continue;
		}
		
		Message* mes = CreatMessage(Newnode->NAME, Newnode->STREET, Newnode->CITY, Newnode->STATE, Newnode->EIP);
		DLNode* newnode = CreatDLNode(mes);

		cur->next = newnode;
		newnode->prev = cur;
		cur = newnode;
	}

	// 连接首尾节点
	cur->next = head;
	head->prev = cur;

	fclose(fp); // 关闭文件
}

//获取链表头部(包括信息装入....
DLNode* GetDLinkHead() {
	DLNode*head =  InitDLink();
	return head;
}

//信息结点存储
Message* CreatMessage(const wchar_t* name, const wchar_t* street, const wchar_t* city, const wchar_t* state, const wchar_t* tel) {
	Message* MesNode = (Message*)malloc(sizeof(Message));
	if (MesNode == NULL) {
		printf("MesNode 申请失败!\n");
		return NULL;
	}

	// wcscpy用于复制宽字节字符串
	wcscpy(MesNode->NAME,name);
	wcscpy(MesNode->STREET,street);
	wcscpy(MesNode->CITY,city);
	wcscpy(MesNode->STATE,state);
	wcscpy(MesNode->EIP,tel);

	return MesNode;
}

//屏幕初始化
void InitScreen(ScreenWindow* Screen){
	initgraph(Screen->width,Screen->height, EX_DBLCLKS);
}

//屏幕线条布局
void DrawLines(ScreenWindow* Screen) {
	setlinecolor(BLACK);
	setlinestyle(PS_SOLID | PS_ENDCAP_ROUND,5);
	line(0,0,Screen->width,0);
	line(Screen->width,0,Screen->width,Screen->height);
	line(0,0,0, Screen->height);
	line(0, Screen->height, Screen->width, Screen->height);
}


//信息录入
Message* enterMessage(ScreenWindow* Screen, ExMessage*mouse) {
	Button* name = Creat_Button(100, 130, 245, 30);
	Button* street = Creat_Button(100, 190, 245, 30);
	Button* city = Creat_Button(100, 250, 245, 30);
	Button* state = Creat_Button(100, 310, 245, 30);
	Button* tel = Creat_Button(100, 370, 245, 30);
	Button* submit = Creat_Button(170, 440, 60, 30);
	wchar_t str_name[100] = L"";
	wchar_t str_street[100] = L"";
	wchar_t str_city[100] = L"";
	wchar_t str_state[100] = L"";
	wchar_t str_tel[100] = L"";
	wchar_t str_submit[100] = L"提交";
	//返回按钮
	Button* backbtn = Creat_Button(3, 3, 70, 30);
	//逻辑判断存储
	const wchar_t** newData = (const wchar_t**)malloc(sizeof(const wchar_t*)*5);
	for (int i = 0; i < 5; i++) {
		newData[i] = NULL;
	}
	bool IsAllNull = false;
	while (1) {
		//基本绘制
		enterDrawBG(Screen);
		getmessage(mouse, EX_MOUSE);
		//姓名
		widgetLable(60, 130, 50, 30,L"姓名: ",NULL);
		wchar_t* newname = ButtonInputRBox(mouse, name, str_name);
		if (newname != NULL) {
			newData[0] = newname;
			wcscpy(str_name, newname);//专门复制宽字节的
		}
		//街道
		widgetLable(60, 190, 50, 30, L"街道: ", NULL);
		wchar_t* newstreet = ButtonInputRBox(mouse, street, str_street);
		if (newstreet != NULL) {
			newData[1] = newstreet;
			wcscpy(str_street, newstreet);//专门复制宽字节的
		}
		//城市
		widgetLable(60, 250, 50, 30, L"城市: ", NULL);
		wchar_t* newcity = ButtonInputRBox(mouse, city, str_city);
		if (newcity != NULL) {
			newData[2] = newcity;
			wcscpy(str_city, newcity);//专门复制宽字节的
		}
		//国家
		widgetLable(60, 310, 50, 30, L"国家: ", NULL);
		wchar_t* newstate = ButtonInputRBox(mouse, state, str_state);
		if (newstate != NULL) {
			newData[3] = newstate;
			wcscpy(str_state, newstate);//专门复制宽字节的
		}
		//邮编
		widgetLable(60, 370, 50, 30, L"邮编: ", NULL);
		wchar_t* newtel = ButtonInputRBox(mouse, tel, str_tel);
		if (newtel != NULL) {
			newData[4] = newtel;
			wcscpy(str_tel, newtel);//专门复制宽字节的
		}
		//提交按键
		bool Issubmit = widgetRButton(mouse, submit, str_submit);
		if (Issubmit) {
			//提交逻辑
			/*
			* 1.全有数据    正常
			* 2.部分有数据  部分空默认设置为"未知"
			* 3.没有数据    NULL
			*/
			if (newData[0] != NULL || newData[1] != NULL || newData[2] != NULL || newData[3] != NULL || newData[4] != NULL) {
				for (int i = 0; i < 5; i++) {
					if (newData[i] == NULL) {
						newData[i] = L"UnKnow";
					}
				}
			}
			else if(newData[0] == NULL && newData[1] == NULL && newData[2] == NULL && newData[3] == NULL && newData[4] == NULL){
				IsAllNull = true;
			}
			break;
		}
		//返回按钮
		bool IsClick = widgetRButton(mouse, backbtn, L"返回");
		if (IsClick) {
			return NULL;
		}
		FlushBatchDraw();
		setFPS(ScreenFPS);
	}
	//释放掉按钮
	free(name);
	free(street);
	free(city);
	free(state);
	free(submit);
	//信息录入
	if (IsAllNull == true) {
		return NULL;
	}
	Message*people =  CreatMessage(newData[0], newData[1], newData[2], newData[3], newData[4]);
	return people;
}

//信息录入背景绘制
void enterDrawBG(ScreenWindow* Screen) {
	//背景色
	// setbkcolor(RGB(40, 255, 249));
	setbkcolor(RGB(77, 152, 210));
	cleardevice();
	//线条
	setlinecolor(BLACK);
	setlinestyle(PS_SOLID | PS_ENDCAP_ROUND, 5);
	line(0, 0, Screen->width, 0);
	line(Screen->width, 0, Screen->width, Screen->height);
	line(0, 0, 0, Screen->height);
	line(0, Screen->height, Screen->width, Screen->height);
	
	//绘制一个方框(300,400)
	setlinecolor(BLACK);
	setlinestyle(PS_SOLID | PS_ENDCAP_ROUND | PS_JOIN_ROUND, 5);
	fillrectangle(25,100,375,500);

	//文字定位
	settextcolor(BLACK);
	settextstyle(28,0,L"黑体");
	outtextxy(140,40,L"信息录入");
}
//信息显示背景绘制
void displayDrawBG(ScreenWindow* Screen) {
	//背景色
	//setbkcolor(RGB(40, 255, 249));
	setbkcolor(RGB(77, 152, 210));
	BeginBatchDraw();
	cleardevice();
	//线条
	setlinecolor(BLACK);
	setlinestyle(PS_SOLID | PS_ENDCAP_ROUND, 5);
	line(0, 0, Screen->width, 0);
	line(Screen->width, 0, Screen->width, Screen->height);
	line(0, 0, 0, Screen->height);
	line(0, Screen->height, Screen->width, Screen->height);

	//绘制一个方框(300,400)
	setlinecolor(BLACK);
	setlinestyle(PS_SOLID | PS_ENDCAP_ROUND | PS_JOIN_ROUND, 5);
	fillrectangle(50, 100, 350, 500);

	//文字定位
	settextcolor(BLACK);
	settextstyle(28, 0, L"黑体");
	outtextxy(140, 40, L"信息显示");
}


//个人信息展示
int displayAllMessage(ScreenWindow* Screen, ExMessage* mouse, DLNode* cur) {
	Button* name = Creat_Button(100, 130, 245, 30);
	Button* street = Creat_Button(100, 190, 245, 30);
	Button* city = Creat_Button(100, 250, 245, 30);
	Button* state = Creat_Button(100, 310, 245, 30);
	Button* tel = Creat_Button(100, 370, 245, 30);
	Button* submit = Creat_Button(120, 440, 60, 30);
	Button* delect = Creat_Button(250, 440, 60, 30);
	wchar_t* str_name = cur->data->NAME;
	wchar_t* str_street = cur->data->STREET;
	wchar_t* str_city = cur->data->CITY;
	wchar_t* str_state = cur->data->STATE;
	wchar_t* str_tel = cur->data->EIP;
	wchar_t str_submit[100] = L"返回";
	wchar_t str_delect[100] = L"删除";
	//逻辑判断存储
	const wchar_t** newData = (const wchar_t**)malloc(sizeof(const wchar_t*) * 5);
	for (int i = 0; i < 5; i++) {
		newData[i] = NULL;
	}
	bool IsAllNull = false;
	//窗口句柄
	HWND hWnd = GetHWnd();
	//结果返回值
	int resultcode = 0;

	while (1) {
		BeginBatchDraw();
		//基本绘制
		enterDrawBG(Screen);
		getmessage(mouse, EX_MOUSE);
		//姓名
		widgetLable(60, 130, 50, 30, L"姓名: ", NULL);
		wchar_t* newname = ButtonInputRBox(mouse, name, str_name);
		if (newname != NULL) {
			newData[0] = newname;
			wcscpy(str_name, newname);//专门复制宽字节的
		}
		//街道
		widgetLable(60, 190, 50, 30, L"街道: ", NULL);
		wchar_t* newstreet = ButtonInputRBox(mouse, street, str_street);
		if (newstreet != NULL) {
			newData[1] = newstreet;
			wcscpy(str_street, newstreet);//专门复制宽字节的
		}
		//城市
		widgetLable(60, 250, 50, 30, L"城市: ", NULL);
		wchar_t* newcity = ButtonInputRBox(mouse, city, str_city);
		if (newcity != NULL) {
			newData[2] = newcity;
			wcscpy(str_city, newcity);//专门复制宽字节的
		}
		//国家
		widgetLable(60, 310, 50, 30, L"国家: ", NULL);
		wchar_t* newstate = ButtonInputRBox(mouse, state, str_state);
		if (newstate != NULL) {
			newData[3] = newstate;
			wcscpy(str_state, newstate);//专门复制宽字节的
		}
		//邮编
		widgetLable(60, 370, 50, 30, L"邮编: ", NULL);
		wchar_t* newtel = ButtonInputRBox(mouse, tel, str_tel);
		if (newtel != NULL) {
			newData[4] = newtel;
			wcscpy(str_tel, newtel);//专门复制宽字节的
		}
		//返回按键
		bool Issubmit = widgetRButton(mouse, submit, str_submit);
		if (Issubmit) {
			//提交逻辑
			/*
			* 1.全有数据    正常
			* 2.部分有数据  部分空默认设置为"未知"
			* 3.没有数据    NULL
			*/
			if (newData[0] != NULL || newData[1] != NULL || newData[2] != NULL || newData[3] != NULL || newData[4] != NULL) {
				for (int i = 0; i < 5; i++) {
					if (newData[i] == NULL) {
						newData[i] = L"Unknown";
					}
				}
			}
			else if (newData[0] == NULL && newData[1] == NULL && newData[2] == NULL && newData[3] == NULL && newData[4] == NULL) {
				IsAllNull = true;
			}
			resultcode = 0;
			break;
		}
		//删除按键
		bool Isdelect = widgetRButton(mouse, delect, str_delect);
		if (Isdelect) {
			/*
			* 1.给出删除警告
			* 2.删除
			*/
			//删除警告
			int result = MessageBox(hWnd, L"是否要删除元素!", L"警告", MB_OKCANCEL | MB_ICONQUESTION | MB_APPLMODAL);
			if (result == IDOK) {
				//删除操作
				Delete(cur);
				MessageBox(hWnd, L"删除成功!", L"提示", MB_OK | MB_ICONASTERISK | MB_APPLMODAL);
				resultcode = 1;
				break;
			}
		}
		FlushBatchDraw();
		setFPS(ScreenFPS);
	}
	//释放掉按钮
	free(name);
	free(street);
	free(city);
	free(state);
	free(submit);

	return resultcode;
}



//信息显示
void displayMessage(ScreenWindow* Screen, ExMessage* mouse,DLNode*head) {
	//按钮显示起始位置
	const int btn_x = 90;
	const int btn_y = 130;
	const int btn_w = 225;
	const int btn_h = 30;
	//按钮显示的个数
	const int btnNum = 10;
	//按钮显示的起始位置
	DLNode* cur = head->next;
	//按钮个数用数组存储
	Button** Arrbtn = (Button**)malloc(sizeof(Button*)*btnNum);
	//返回按钮
	Button* backbtn = Creat_Button(3, 3, 70, 30);
	//初始化按钮
	int num = -1;
	while (cur != head && num++ < btnNum) {
		//创建按钮
		Arrbtn[num] = Creat_Button(btn_x, btn_y+(btn_h*num), btn_w, btn_h);
		cur = cur->next;
	}
	//初始化cur
	cur = head->next;
	//绘制框的左上角和右下角
	RECT position = {
		position.left = 50,
		position.top = 100,
		position.right = 350,
		position.bottom = 500,
	};
	//记录值
	DLNode* nowCur = head->next;
	//延时值
	static int lastWheelEventTime = 0;
	static const int wheelEventDelay = 50;
	//删除触发需要记录前值
	DLNode* targetPrev = NULL;

start:
	while (1) {
		//基本绘制
		displayDrawBG(Screen);
		//获取单个信息(好用
		getmessage(mouse, EX_MOUSE);

		//主要功能
		/*
		* 1.按钮显示框中显示信息(只显示姓名
		* 2.获取滚轮实现下滑效果(循环绘制显示的名字
		* 3.点击按钮跳转画面显示所有信息
		*/
		//数组显示个数
		int count = -1;
		//绘制内容
		while (cur != head&&count++ < btnNum) {
			//绘制按钮
			bool IsClick = widgetRButton(mouse, Arrbtn[count], cur->data->NAME);
			//处理鼠标点击事件
			if (IsClick) {
				targetPrev = cur->prev;
				int result = displayAllMessage(Screen,mouse,cur);
				//触发删除
				if (result == 1) {
					cur = targetPrev;
					cur = cur->next;
					break;
				}
				cur = nowCur;
				goto start;
			}
			cur = cur->next;
		}
		//返回按钮
		bool IsClick = widgetRButton(mouse, backbtn, L"返回");
		if (IsClick) {
			break;
		}
		//恢复cur初值
		cur = nowCur;
		//滚轮滑动效果
		if (mouse->x > position.left && mouse->x<position.right && mouse->y>position.top && mouse->y < position.bottom) {
			if (mouse->message == WM_MOUSEWHEEL) {
				//延时操作
				int currentTime = GetTickCount(); // 获取当前时间
				if (currentTime - lastWheelEventTime >= wheelEventDelay) {
					lastWheelEventTime = currentTime;
					if (mouse->wheel > 0) {
						if (cur->prev != head) {
							cur = cur->prev;
							nowCur = cur;
						}
					}
					else if (mouse->wheel < 0) {
						if(cur->next!=head){
							cur = cur->next;
							nowCur = cur;
						}
					}
				}
			}
		}
		//存在鼠标滚轮下滑则修改cur的值
		cur = nowCur;
		//直接跳出循环证明没有数据

		//画面显示
		FlushBatchDraw();
		setFPS(ScreenFPS);
	}
}

//信息查询背景绘制
void searchDrawBG(ScreenWindow* Screen) {
	//背景色
	//setbkcolor(RGB(40, 255, 249));
	setbkcolor(RGB(77, 152, 210));
	BeginBatchDraw();
	cleardevice();
	//线条
	setlinecolor(BLACK);
	setlinestyle(PS_SOLID | PS_ENDCAP_ROUND, 5);
	line(0, 0, Screen->width, 0);
	line(Screen->width, 0, Screen->width, Screen->height);
	line(0, 0, 0, Screen->height);
	line(0, Screen->height, Screen->width, Screen->height);

	//绘制一个方框(300,400)
	setlinecolor(BLACK);
	setlinestyle(PS_SOLID | PS_ENDCAP_ROUND | PS_JOIN_ROUND, 5);
	fillrectangle(50, 100, 350, 500);

	//绘制线条
	line(50, 180, 350, 180);

	//文字定位
	settextcolor(BLACK);
	settextstyle(28, 0, L"黑体");
	outtextxy(140, 40, L"信息查询");
}

//信息查询
void searchMessage(ScreenWindow* Screen, ExMessage* mouse, DLNode* head) {
	//初始化
	//搜索按钮
	Button* searchbtn = Creat_Button(85, 130, 235, 30);
	Button* backbtn = Creat_Button(3, 3, 70, 30);
	//窗口句柄
	HWND hWnd = GetHWnd();
	//按钮显示起始位置
	const int btn_x = 90;
	const int btn_y = 220;
	const int btn_w = 225;
	const int btn_h = 30;
	//按钮显示的个数
	const int btnNum = 5;
	//按钮个数用数组存储
	Button** Arrbtn = (Button**)malloc(sizeof(Button*) * btnNum);
	//初始化按钮
	int num = -1;
	while (num++ < btnNum) {
		//创建按钮
		Arrbtn[num] = Creat_Button(btn_x, btn_y + (btn_h * num), btn_w, btn_h);
	}
	//结果存储
	DLNode** results = NULL;
	//搜索结果显示
	int count = 0;
	//显示框坐标
	RECT position = {
		position.left = 50,
		position.top = 100,
		position.right = 350,
		position.bottom = 500,
	};
	//延时值
	static int lastWheelEventTime = 0;
	static const int wheelEventDelay = 50;
	//数组起始下标
	int startIndex = 0;

	//循环主题
start:
	while (1) {
		//基本绘制
		searchDrawBG(Screen);
		//获取单个信息(好用
		getmessage(mouse, EX_MOUSE);
		//主要功能
		/*
		* 1.搜索功能
		* 2.搜索结果显示
		* 3.搜索结果可点击查看主题
		*/
		//搜素功能
		wchar_t* target = ButtonInputRBox(mouse, searchbtn, L"点击搜索",L"填入Name进行搜索",L"搜索框");
		if (target != NULL) {
			//初始化count
			count = 0;
			//查找信息(名字是key
			results = search(head, target);
			while (results[count] != NULL) count++;
			//结果汇报
			if (count == 0) {
				MessageBox(hWnd, L"没有搜索到任何结果", L"提示", MB_OK | MB_ICONASTERISK| MB_APPLMODAL);
			}
			else {
				wchar_t result[50]; // 创建足够大的结果数组
				// 将整数count转换为字符串
				char count_str[50];
				sprintf(count_str, "%d", count);
				// 将字符串count_str转换为宽字符字符串
				size_t len = strlen(count_str) + 1;
				mbstowcs(result, count_str, len);
				//前缀提示词
				wchar_t prev[50] = L"找到结果数量为: ";
				//字符串拼接
				wcscat(prev,result);
				MessageBox(hWnd, prev, L"提示", MB_OK | MB_ICONASTERISK| MB_APPLMODAL);
			}
		}
		//搜索结果显示(result
		int num = 0;
		//绘制内容
		while (num < count && count > 0&& num < btnNum) 
		{
			if (startIndex + num >= count) break;
			//绘制按钮
			bool IsClick = widgetRButton(mouse, Arrbtn[num], results[startIndex + num]->data->NAME);
			//处理鼠标点击事件
			if (IsClick) {
				//点击查看主题
				int result = displayAllMessage(Screen, mouse, results[startIndex + num]);
				//触发删除
				if (result == 1) {
					//找寻空处
					for (int i = 0; i < count; i++) {
						/*bug*/
						//free掉的结果如何筛选掉?
						if (results[i] == NULL) {
							//往前填
							for (int j = i; j < count; j++) {
								results[j] = results[j + 1];
							}
							goto bk;
						}
					}
				bk:
					count--;
					goto start;
				}
			}
			num++;
		}
		//返回按钮
		bool IsClick = widgetRButton(mouse, backbtn, L"返回");
		if (IsClick) {
			break;
		}
		//滚轮滑动效果
		if (mouse->x > position.left && mouse->x<position.right && mouse->y>position.top && mouse->y < position.bottom) {
			if (mouse->message == WM_MOUSEWHEEL) {
				//延时操作
				int currentTime = GetTickCount(); // 获取当前时间
				if (currentTime - lastWheelEventTime >= wheelEventDelay) {
					lastWheelEventTime = currentTime;
					if (mouse->wheel > 0) {
						if (startIndex > 0) {
							startIndex--;
						}
					}
					else if (mouse->wheel < 0) {
						if (startIndex + 1 < count) {
							startIndex++;
						}
					}
				}
			}
		}
		//画面显示
		FlushBatchDraw();
		setFPS(ScreenFPS);
	}
}