#include"DList.h"

//初始化链表
void InitList(List* list)
{
	list->last = list->first = (Node*)malloc(sizeof(Node));
	assert(list->first != NULL);
	list->first->prior = NULL;
	list->last->next = NULL;
	list->size = 0;
}

//获取节点
Node* _buyNode(ElemType x)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	assert(newNode);
	newNode->data = x;
	newNode->next = NULL;
	newNode->prior = NULL;
	return newNode;
}

//============== 1 尾插法
void push_back(List* list, ElemType data)
{
	Node* newNode = _buyNode(data);

	list->last->next = newNode;
	newNode->prior = list->last;
	list->last = newNode;
	list->size++;

	return;
}
//============== 2 头插法
void push_front(List* list, ElemType data)
{
	Node* newNode = _buyNode(data);

	newNode->next = list->first->next;
	newNode->prior = list->first;
	list->first->next = newNode;
	list->size++;

	return;
}

//============== 3 显示链表
void show_list(List* list)
{
	Node* p = list->first->next;
	while (p != NULL)
	{
		printf("%d->", p->data);
		p = p->next;
	}
	printf("NULL\n");
	return;
}
//============== 4 尾删法
void pop_back(List* list)
{
	if (list->size == 0) { return; }

	Node* p = list->last;

	list->last = p->prior;
	list->last->next = NULL;
	free(p);
	list->size--;

	return;
}
//============== 5 头删法
void pop_front(List* list)
{
	if (list->size == 0) { return; }
	if (list->size == 1)
	{
		Node* p = list->first->next;
		list->first->next = p->next;
		list->last = list->first;
		free(p);
		list->size--;
		return;
	}

	Node* p = list->first->next;
	list->first->next = p->next;
	p->next->prior = list->first;
	free(p);
	list->size--;

	return;
}
//============== 6 按值插入
void insert_val(List* list, ElemType item)
{
	Node* p = list->first;

	while (p->next != NULL && p->next->data < item) { p = p->next; }
	if (p->next == NULL) { 
		push_back(list, item); 
		return; 
	}

	Node* newNode = _buyNode(item);
	newNode->next = p->next;
	newNode->next->prior = newNode;
	newNode->prior = p;
	p->next = newNode;

	list->size++;

	return;
}
//============== 7 查找
Node* find(List* list, ElemType key)
{
	Node* p = list->first->next;
	while (p != NULL && p->data != key) { p = p->next; }
	return p;
}
//============== 8 按值插入
int length(List* list)
{
	return list->size;
}
//============== 9 按值删除
void delete_val(List* list, ElemType item)
{
	Node* p = find(list, item);
	if (list->size == 0) { return; }
	if (p == NULL) { return; }
	if (p == list->last) 
	{ 
		list->last = p->prior;
		list->last->next = NULL;
	}
	else
	{
		p->prior->next = p->next;
		p->next->prior = p->prior;
	}
	free(p);
	list->size--;
	return;
}
//============== 10 排序
void sort(List* list)
{
	if (list->size == 0 || list->size == 1) { return; }

	Node* p1 = list->first->next;
	Node* p2 = p1->next;
	list->last = p1;
	list->last->next = NULL;

	while (p2 != NULL)
	{
		p1 = p2;
		p2 = p2->next;
		
		Node* p = list->first;
		while (p->next != NULL && p->next->data < p1->data) { p = p->next; }

		if (p->next == NULL) {
			p->next = p1;
			p1->prior = p;
			p1->next = NULL;
			list->last = p1;
		}
		else {
			p1->next = p->next;
			p->next->prior = p1;
			p->next = p1;
			p1->prior = p;
		}
	}
	return;
}

//============== 11 逆置
void resever(List* list)
{
	if (list->size == 0 || list->size == 1) { return; }

	Node* p1 = list->first->next;
	Node* p2 = p1->next;
	list->last = p1;
	list->last->next = NULL;

	while (p2 != NULL)
	{
		p1 = p2;
		p2 = p2->next;
		
		p1->next = list->first->next;
		p1->prior = list->first;
		p1->next->prior = p1;
		list->first->next = p1;
	}

	return;
}
//============== 12 清除
void clear(List* list)
{
	if (list->size == 0) { return; }

	Node* p = list->first->next;
	while (p != NULL)
	{
		if (p == list->last)
		{
			list->last = list->first;
			list->last->next = NULL;
		}
		else
		{
			p->next->prior = list->first;
			list->first->next = p->next;
		}
		free(p);
		p = list->first->next;
	}
	list->size = 0;
}

//============== 13 摧毁
void destory(List* list)
{
	clear(list);
	free(list->first);
	list->last = list->first = NULL;
}