#include"Contact.h"
#include"SeqList.h"

// ��ʼ��������
void ContactInit(contact* pcon)
{
	SLInit(pcon);
}
void ContactDestory(contact* pcon)
{
	SLDestroy(pcon);
}

//�����ϵ��
void ContactAdd(contact* pcon)
{
	CInfo info;
	printf("��������ϵ��������");
	scanf("%s", info.name);
	printf("��������ϵ���Ա�");
	scanf("%s", info.gender);
	printf("��������ϵ�����䣺");
	scanf("%d", &info.age);
	printf("��������ϵ�˵绰��");
	scanf("%s", info.tel);
	printf("��������ϵ�˵�ַ��");
	scanf("%s", info.addr);

	//β������
	SLPushBack(pcon, info);
}


static int FindByName(contact* pcon,char name[])
{
	for (int i = 0; i < pcon->size; i++)
	{
		if (strcmp(pcon->a[i].name,name) == 0)
		{
			return i;
		}
	}
	return -1;
}

//�޸���ϵ��
void ContactModify(contact* pcon)
{
	char name[NAME_MAX];
	printf("������Ҫ�޸ĵ��û�����");
	scanf("%s", name);
	int find = FindByName(pcon, name);
	if (find < 0)
	{
		printf("Ҫ�޸ĵ��û�������!\n");
		return;
	}

	printf("�������µ��û�����");
	scanf("%s", pcon->a[find].name);
	printf("�������µ��Ա�");
	scanf("%s", pcon->a[find].gender);
	printf("�������µ����䣺");
	scanf("%d", &pcon->a[find].age);
	printf("�������µĵ绰��");
	scanf("%s", pcon->a[find].tel);
	printf("�������µĵ�ַ��");
	scanf("%s", pcon->a[find].addr);
	printf("�޸ĳɹ���\n");
}

//�鿴ͨѶ��
void ContactShow(contact* pcon)
{
	printf("%-4s %-4s %-4s %-4s %-4s \n", "����", "�Ա�", "����", "�绰", "סַ");
	for (int i = 0; i < pcon->size; i++)
	{
		printf("%-4s %-4s %-4d %-4s %-4s \n",
			pcon->a[i].name,
			pcon->a[i].gender,
			pcon->a[i].age,
			pcon->a[i].tel,
			pcon->a[i].addr
			);
	}
}

//������ϵ��
void ContactFind(contact* pcon)
{
	char name[NAME_MAX];
	printf("������Ҫ���ҵ��û�����");
	scanf("%s", name);
	int find = FindByName(pcon, name);
	if (find < 0)
	{
		printf("Ҫ���ҵ��û�������!\n");
		return;
	}
	printf("-------------------------------\n");
	printf("%-4s %-4s %-4s %-4s %-4s \n", "����", "�Ա�", "����", "�绰", "סַ");
	printf("%-4s %-4s %-4d %-4s %-4s \n",
		pcon->a[find].name,
		pcon->a[find].gender,
		pcon->a[find].age,
		pcon->a[find].tel,
		pcon->a[find].addr
		);
	
}

//ɾ����ϵ��
void ContactDel(contact* pcon)
{
	char name[NAME_MAX];
	printf("������Ҫɾ�����û�����");
	scanf("%s", name);
	int find = FindByName(pcon, name);
	if (find < 0)
	{
		printf("Ҫɾ�����û�������!\n");
		return;
	}

	SLErase(pcon, find);
}
