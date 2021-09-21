#include "SList.h"

void InitList(List* list)
{
	list->first = list->last = (Node*)malloc(sizeof(Node));
	assert(list->first != NULL);
	list->first->Next = list->last->Next = NULL;
	list->size = 0;
}

//尾插法
void push_back(List* list, ElemType data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	assert(newNode != NULL);
	newNode->data = data;
	newNode->Next = NULL;
	list->last->Next = newNode;
	list->last = newNode;
	list->size++;
}
//头插法
void push_front(List* list, ElemType data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	assert(NULL != newNode);
	newNode->data = data;
	newNode->Next = list->first->Next;

	list->first->Next = newNode;
	if (list->size == 0)
	{
		list->last = newNode;
	}
	list->size++;
}
//显示链表
void show_list(List* list)
{
	if (list->last== NULL)
	{
		printf("链表不存在！\n");
		return;
	}
	Node* showList = (Node*)malloc(sizeof(Node));
	showList = list->first->Next;
	while (showList != NULL)
	{
		printf("%d-->", showList->data);
		showList = showList->Next;
	}
	printf("NULL\n");
}
//尾部删除
void pop_back(List* list)
{
	if (list->size == 0)
	{
		return;
	}
	//Node* newNode = (Node*)malloc(sizeof(Node));
	Node* newNode = list->first;
	//while (newNode->Next->Next != NULL)
	//{
	//	newNode = newNode->Next;
	//}
	while (newNode->Next != list->last)
	{
		newNode = newNode->Next;
	}
	free(list->last);
	list->last = newNode;
	list->last->Next = NULL;
	list->size--;
}
//头部删除
void pop_front(List* list)
{
	if (list->size == 0)
	{
		return;
	}
	Node* tmpNode = list->first->Next;
	list->first->Next = tmpNode->Next;
	free(tmpNode);
	if (list->size == 1)
	{
		list->last = list->first;
	}
	list->size--;
}
//按值插入
void insert_val(List* list, ElemType item)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	assert(newNode != NULL);
	newNode->data = item;
	newNode->Next = NULL;
	
	Node* tmpNode = list->first;
	while (tmpNode->Next != NULL && newNode->data > tmpNode->Next->data)
	{
		tmpNode = tmpNode->Next;
	}
	if (tmpNode->Next == NULL)
	{
		list->last = newNode;
	}
	newNode->Next = tmpNode->Next;
	tmpNode->Next = newNode;
	list->size++;
}
//查找
Node* find(List* list, ElemType key)
{
	int pos = 1;
	Node* tmpNode = list->first->Next;
	while (tmpNode != NULL && key != tmpNode->data)
	{
		tmpNode = tmpNode->Next;
		pos++;
	}
	if(tmpNode != NULL)
		printf("数据的位置在链表的第%d个节点\n", pos);
	return tmpNode;
}
//长度
int length(List* list)
{
	return list->size;
}
//删除
void delete_val(List* list, ElemType item)
{
	if (list->size == 0)
		return;
	Node* tmpNode = find(list, item);
	if (tmpNode == NULL)
	{
		printf("要删除的数据不纯在!\n");
		return;
	}
	else if (tmpNode == list->last)
	{
		pop_back(list);
	}
	else
	{
		Node* tmp2Node = tmpNode->Next;
		tmpNode->data = tmpNode->Next->data;
		tmpNode->Next = tmpNode->Next->Next;
		free(tmp2Node);
		list->size--;
	}
}

//排序
/*将链表从第一个接节点断开，让last指向第一个节点，p指针指向后半段
*然后一次将p指针指向的段拆开，依照insert_val的思路，将其插入前半段，实现节点的排序而非简单的值的排序
*/
void sort(List* list)
{
	if (list->size == 0 || list->size == 1)
		return;
	Node* s = list->first->Next;
	Node* p = s->Next;

	list->last = s;
	list->last->Next = NULL;

	while (p != NULL)
	{
		s = p;
		p = p->Next;

		Node* tmpNode = list->first;
		while (tmpNode->Next != NULL && s->data > tmpNode->Next->data)
		{
			tmpNode = tmpNode->Next;
		}
		if (tmpNode->Next == NULL)
		{
			list->last = s;
		}
		s->Next = tmpNode->Next;
		tmpNode->Next = s;
	}
}
//逆置
//void resver(List* list)
//{
//	if (list->size == 0 || list->size == 1)
//		return;
//
//	Node* tmpNode1 = list->first->Next;
//	Node* tmpNode2 = tmpNode1->Next;
//
//	list->last = tmpNode1;
//	list->last->Next = NULL;
//
//	while (tmpNode2 != NULL)
//	{
//		tmpNode1 = tmpNode2;
//		tmpNode2 = tmpNode2->Next;
//
//		tmpNode1->Next = list->first->Next;
//		list->first->Next = tmpNode1;
//
//	}
//}

//逆置
void resver(List* list)
{
	if (list->size == 0 || list->size == 1)
		return;
	Node* tmpNode1 = list->first->Next;
	Node* tmpNode2 = tmpNode1->Next;

	list->last = tmpNode1;
	tmpNode1->Next = NULL;

	while (tmpNode2 != NULL)
	{
		tmpNode1 = tmpNode2;
		tmpNode2 = tmpNode2->Next;

		tmpNode1->Next = list->first->Next;
		list->first->Next = tmpNode1;
	}
}
//清除
void clear(List* list)
{
	if (list->size == 0)
		return;

	Node* tmpNode = list->first->Next;

	while (tmpNode != NULL)
	{
		list->first->Next = tmpNode->Next;
		free(tmpNode);
		tmpNode = list->first->Next;
	}
	list->last = list->first;
	list->size = 0;
}
//摧毁
void destory(List* list)
{
	clear(list);
	free(list->first);
	list->first = list->last = NULL;

}