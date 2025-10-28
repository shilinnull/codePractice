#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef char ElemType;

typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LinkNode;

void CreateListF(LinkNode **L, ElemType a[], int n){
	LinkNode *s;
	*L = (LinkNode *)malloc(sizeof(LinkNode));
	(*L)->next = NULL;
	int i;
	for(i = 0; i < n; i++){
		s = (LinkNode *)malloc(sizeof(LinkNode));
		s->data = a[i];
		s->next = (*L)->next;
		(*L)->next = s;
	}
}

void CreateListR(LinkNode **L, ElemType a[], int n){
	LinkNode *s, *r;
	*L = (LinkNode *)malloc(sizeof(LinkNode));
	(*L)->next = NULL;
	r = *L;
	int i;
	for(i = 0; i < n; i++){
		s = (LinkNode *)malloc(sizeof(LinkNode));
		s->data = a[i];
		s->next = NULL;
		r->next = s;
		r = s;
	}
}

void InitList(LinkNode **L){
	*L = (LinkNode *)malloc(sizeof(LinkNode));
	(*L)->next = NULL;
}

void DestroyList(LinkNode **L){
	LinkNode *pre = *L, *p = pre->next;
	while(p != NULL){
		free(pre);
		pre = p;
		p = pre->next;
	}
	free(pre);
	*L = NULL;
}

int ListEmpty(LinkNode *L){
	return(L->next == NULL);
}

int ListLength(LinkNode *L){
	int i = 0;
	LinkNode *p = L;
	while(p->next != NULL){
		i++;
		p = p->next;
	}
	return (i);
}

void DispList(LinkNode *L){
	LinkNode *p = L->next;
	while(p != NULL){
		printf("%c ", p->data);
		p = p->next;
	}
	printf("\n");
}

int GetElem(LinkNode *L, int i, ElemType *e){
	int j = 0;
	if(i <= 0)return 0;
	LinkNode *p = L;
	while(j < i && p != NULL){
		j++;
		p = p->next;
	}
	if(p == NULL){
		return 0;
	}else{
		*e = p->data;
		return 1;
	}
}

int LocateElem(LinkNode *L, ElemType e){
	int i = 1;
	LinkNode *p = L->next;
	while(p != NULL && p->data != e){
		p = p->next;
		i++;
	}
	if(p == NULL)
		return (0);
	else
		return (i);
}

int ListInsert(LinkNode **L, int i, ElemType e){
	int j = 0;
	if(i <= 0) return 0;
	LinkNode *p = *L, *s;
	while(j < i - 1 && p != NULL){
		j++;
		p = p->next;
	}
	if(p == NULL)
		return 0;
	else{
		s = (LinkNode *)malloc(sizeof(LinkNode));
		s->data = e;
		s->next = p->next;
		p->next = s;
		return 1;
	}
}

int ListDelete(LinkNode **L, int i, ElemType *e){
	int j = 0;
	if(i <= 0) return 0;
	LinkNode *p = *L, *q;
	while(j < i - 1 && p != NULL){
		j++;
		p = p->next;
	}
	if(p == NULL)
		return 0;
	else{
		q = p->next;
		if(q == NULL)
			return 0;
		*e = q->data;
		p->next = q->next;
		free(q);
		return 1;
	}
}

void SplitList(LinkNode *src, LinkNode **L1, LinkNode **L2) {
	if (src == NULL || L1 == NULL || L2 == NULL) return;

	// 初始化两个带头结点的新链表
	*L1 = (LinkNode *)malloc(sizeof(LinkNode));  // L1的头结点
	(*L1)->next = NULL;
	*L2 = (LinkNode *)malloc(sizeof(LinkNode));  // L2的头结点
	(*L2)->next = NULL;

	LinkNode *p = src->next;  // 指向原链表第一个元素
	LinkNode *r1 = *L1;       // L1的尾指针（始终指向L1的最后一个节点）
	LinkNode *r2 = *L2;       // L2的尾指针（始终指向L2的最后一个节点）
	int len = ListLength(src);
	int mid = len / 2;        // 按中间位置拆分
	int i = 0;

	while (p != NULL) {
		// 创建新节点存储当前元素
		LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
		s->data = p->data;
		s->next = NULL;

		// 前半部分放入L1，后半部分放入L2
		if (i < mid) {
			r1->next = s;  // 链接到L1尾部
			r1 = s;        // 更新L1尾指针
		} else {
			r2->next = s;  // 链接到L2尾部
			r2 = s;        // 更新L2尾指针
		}

		p = p->next;  // 移动到原链表下一个节点
		i++;
	}

	// 清空原链表（保留头结点，仅释放数据节点）
	LinkNode *q = src->next, *temp;
	while (q != NULL) {
		temp = q;
		q = q->next;
		free(temp);
	}
	src->next = NULL;
}

int main() {
	LinkNode *h;
	ElemType e;
	printf("单链表的基本运算如下：\n");
	printf("(1)初始化单链表h\n");
	InitList(&h);
	printf("(2)依次采用尾插法插入a,b,c,d,e元素\n");
	ListInsert(&h, 1, 'a');
	ListInsert(&h, 2, 'b');
	ListInsert(&h, 3, 'c');
	ListInsert(&h, 4, 'd');
	ListInsert(&h, 5, 'e');
	printf("(3)输出单链表\n");
	DispList(h);
	printf("(4)单链表h长度为:%d\n",ListLength(h));
	printf("(5)单链表h为:%s\n",(ListEmpty(h) ? "空" : "非空"));
	GetElem(h, 3, &e);
	printf("(6)单链表h的第3个元素:%c\n",e);
	printf("(7)元素a的位置:%d\n",LocateElem(h,'a'));
	printf("(8)在第4个元素位置上插入f元素\n");
	ListInsert(&h, 4, 'f');
	printf("(9)输出化单链表h\n");
	DispList(h);
	printf("(10)删除h的第3个元素\n");
	ListDelete(&h, 3, &e);
	printf("(11)输出单链表h:");
	DispList(h);
	printf("(12)释放单链表h\n");
	DestroyList(&h);
	return 1;
}