#include"SeqList.h"
#include"Contact.h"

void menu() {
	printf("****************通讯录*******************\n");
	printf("******1、添加联系人    2、删除联系人*******\n");
	printf("******3、修改联系人    4、查找联系人*******\n");
	printf("******5、查看通讯录    0、 退 出    *******\n");
	printf("****************************************\n");
}
int main() {
	int op = -1;
	//定义一个通讯录
	contact con;
	ContactInit(&con);
	do {
		menu();
		printf("请选择您的操作：\n");
		scanf("%d", &op);
		switch (op)
		{
		case 1:
			ContactAdd(&con);
			break;
		case 2:
			ContactDel(&con);
			break;
		case 3:
			ContactModify(&con);
			break;
		case 4:
			ContactFind(&con);
			break;
		case 5:
			ContactShow(&con);
			break;
		case 0:
			printf("goodbye~\n");
			break;
		default:
			printf("您的输入有误，请重新输入\n");
			break;
		}
	} while (op);

	ContactDestory(&con);
	return 0;
}