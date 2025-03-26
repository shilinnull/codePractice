#include"Contact.h"
#include"SeqList.h"

// 初始化和销毁
void ContactInit(contact* pcon)
{
	SLInit(pcon);
}
void ContactDestory(contact* pcon)
{
	SLDestroy(pcon);
}

//添加联系人
void ContactAdd(contact* pcon)
{
	CInfo info;
	printf("请输入联系人姓名：");
	scanf("%s", info.name);
	printf("请输入联系人性别：");
	scanf("%s", info.gender);
	printf("请输入联系人年龄：");
	scanf("%d", &info.age);
	printf("请输入联系人电话：");
	scanf("%s", info.tel);
	printf("请输入联系人地址：");
	scanf("%s", info.addr);

	//尾插数据
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

//修改联系人
void ContactModify(contact* pcon)
{
	char name[NAME_MAX];
	printf("请输入要修改的用户名：");
	scanf("%s", name);
	int find = FindByName(pcon, name);
	if (find < 0)
	{
		printf("要修改的用户不存在!\n");
		return;
	}

	printf("请输入新的用户名：");
	scanf("%s", pcon->a[find].name);
	printf("请输入新的性别：");
	scanf("%s", pcon->a[find].gender);
	printf("请输入新的年龄：");
	scanf("%d", &pcon->a[find].age);
	printf("请输入新的电话：");
	scanf("%s", pcon->a[find].tel);
	printf("请输入新的地址：");
	scanf("%s", pcon->a[find].addr);
	printf("修改成功！\n");
}

//查看通讯里
void ContactShow(contact* pcon)
{
	printf("%-4s %-4s %-4s %-4s %-4s \n", "姓名", "性别", "年龄", "电话", "住址");
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

//查找联系人
void ContactFind(contact* pcon)
{
	char name[NAME_MAX];
	printf("请输入要查找的用户名：");
	scanf("%s", name);
	int find = FindByName(pcon, name);
	if (find < 0)
	{
		printf("要查找的用户不存在!\n");
		return;
	}
	printf("-------------------------------\n");
	printf("%-4s %-4s %-4s %-4s %-4s \n", "姓名", "性别", "年龄", "电话", "住址");
	printf("%-4s %-4s %-4d %-4s %-4s \n",
		pcon->a[find].name,
		pcon->a[find].gender,
		pcon->a[find].age,
		pcon->a[find].tel,
		pcon->a[find].addr
		);
	
}

//删除联系人
void ContactDel(contact* pcon)
{
	char name[NAME_MAX];
	printf("请输入要删除的用户名：");
	scanf("%s", name);
	int find = FindByName(pcon, name);
	if (find < 0)
	{
		printf("要删除的用户不存在!\n");
		return;
	}

	SLErase(pcon, find);
}
