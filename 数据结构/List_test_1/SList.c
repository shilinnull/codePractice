
#include"SList.h"


//打印
void SLTPrint(SLNode* phead)
{
	//将头节点的地址保存到cur中
	SLNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d-> ", cur->val);
		//cur是保存下一个节点的地址
		cur = cur->next;
	}
	printf("NULL\n");
}


//开辟空间
SLNode* CreateNode(SLNDataType x)
{
	//malloc一个新的空间
	SLNode* newnode = (SLNode*)malloc(sizeof(SLNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	//申请出来的空间直接赋值
	newnode->val = x;
	//下一个next赋值为空
	newnode->next = NULL;
	//返回一个新的空间
	return newnode;
}



//尾插
void SLTPushBack(SLNode** pphead, SLNDataType x)
{
	//这里申请空间
	SLNode* newnode = CreateNode(x);
	//判断头是否为空，如果为空，就将新开辟的空间赋给头
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		//将头指向变量尾
		SLNode* tail = *pphead;
		//找尾
		while (tail->next != NULL)
		{
			//找到了尾然后继续
			tail = tail->next;
		}
		//把那个返回的空间赋值给尾的next
		tail->next = newnode;
	}
}

//头插
void SLTPushFront(SLNode** pphead, SLNDataType x)
{
	//申请节点
	SLNode* newnode = CreateNode(x);
	//让新节点跟头节点连接起来
	newnode->next = *pphead;
	//让新的节点成为头节点
	*pphead = newnode;	
}


//尾删
void SLTPopBack(SLNode** pphead)
{
	assert(pphead);
	assert(*pphead);
	//当前链表只有一个节点的时候
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		//定义一个快慢指针
		SLNode* ptail = *pphead;
		SLNode* prev = NULL;
		//ptail的next不等于NULL就一直找
		while (ptail->next != NULL)
		{
			//将ptail的地址赋给慢指针prev
			prev = ptail;
			//ptail继续往下找
			ptail = ptail->next;
		}
		prev->next = ptail->next;
		free(ptail);
		ptail = NULL;
	}
}

//头删
void SLTPopFront(SLNode** pphead)
{
	assert(pphead);
	assert(*pphead);
	//定义一个临时指针，将第二个节点赋值给临时指针
	SLNode* next = (*pphead)->next;
	//释放头节点
	free(*pphead);
	//将临时节点变成头节点
	*pphead = next;
}

//查找
SLNode* SListFind(SLNode** phead, SLNDataType x)
{
	assert(phead);
	SLNode* pcur = *phead;
	while (pcur != NULL)
	{
		if (pcur->val == x)
		{
			return pcur;
		}
		pcur = pcur->next;
	}
	return NULL;
}


//在指定位置之前插入数据
void SLTInsert(SLNode** pphead, SLNode* pos, SLNDataType x)
{
	assert(pphead);
	//链表不能为空，pos也不能为空
	assert(pos);
	assert(*pphead);
	SLNode* node = CreateNode(x);
	//处理只有一个节点和只有一个节点的情况下，直接将新申请下来的节点赋给头
	if ((*pphead)->next == NULL || pos == *pphead)
	{
		node->next = *pphead;
		*pphead = node;
		return;
	}
	SLNode* prev = *pphead;
	//找pos的前一个节点
	while (prev->next != pos)
	{
		prev = prev->next;
	}
	//连接
	node->next = pos;
	prev->next = node;
}

//在指定位置之后插入数据
void SLTInsertAfter(SLNode* pos, SLNDataType x)
{
	assert(pos);
	SLNode* node = CreateNode(x);
	//连接
	node->next = pos->next;
	pos->next = node;
}




//删除pos节点
void SLTErase(SLNode** pphead, SLNode* pos)
{
	assert(pphead);
	assert(*pphead);
	assert(pos);
	//判断pos是不是头
	if (pos == *pphead)
	{
		*pphead = (*pphead)->next;
		free(pos);
		return;
	}
	//找pos的前一个节点
	SLNode* prev = *pphead;
	while (prev->next != pos)
	{
		prev = prev->next;
	}
	prev->next = pos->next;
	free(pos);
	pos = NULL;
}



//删除pos之后的节点
void SLTEraseAfter(SLNode* pos)
{
	assert(pos && pos->next);
	SLNode* del = pos->next;
	pos->next = del->next;
	free(del);
	del = NULL;

}

//销毁链表
void SListDesTroy(SLNode** pphead)
{
	assert(pphead);
	SLNode* pcur = *pphead;

	while (pcur != NULL)
	{
		SLNode* next = pcur->next;
		free(pcur);
		pcur = next;
	}
	*pphead = NULL;
}

