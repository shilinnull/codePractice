#include"SeqList.h"
#include"Contact.h"

void menu() {
	printf("****************ͨѶ¼*******************\n");
	printf("******1�������ϵ��    2��ɾ����ϵ��*******\n");
	printf("******3���޸���ϵ��    4��������ϵ��*******\n");
	printf("******5���鿴ͨѶ¼    0�� �� ��    *******\n");
	printf("****************************************\n");
}
int main() {
	int op = -1;
	//����һ��ͨѶ¼
	contact con;
	ContactInit(&con);
	do {
		menu();
		printf("��ѡ�����Ĳ�����\n");
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
			printf("����������������������\n");
			break;
		}
	} while (op);

	ContactDestory(&con);
	return 0;
}