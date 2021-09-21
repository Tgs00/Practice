#include "SList.h"

void InitList(List* list)
{
	list->first = list->last = (Node*)malloc(sizeof(Node));
	assert(list->first != NULL);
	list->first->Next = list->last->Next = NULL;
	list->size = 0;
}

//β�巨
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
//ͷ�巨
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
//��ʾ����
void show_list(List* list)
{
	if (list->last== NULL)
	{
		printf("�������ڣ�\n");
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
//β��ɾ��
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
//ͷ��ɾ��
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
//��ֵ����
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
//����
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
		printf("���ݵ�λ��������ĵ�%d���ڵ�\n", pos);
	return tmpNode;
}
//����
int length(List* list)
{
	return list->size;
}
//ɾ��
void delete_val(List* list, ElemType item)
{
	if (list->size == 0)
		return;
	Node* tmpNode = find(list, item);
	if (tmpNode == NULL)
	{
		printf("Ҫɾ�������ݲ�����!\n");
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

//����
/*������ӵ�һ���ӽڵ�Ͽ�����lastָ���һ���ڵ㣬pָ��ָ�����
*Ȼ��һ�ν�pָ��ָ��Ķβ𿪣�����insert_val��˼·���������ǰ��Σ�ʵ�ֽڵ��������Ǽ򵥵�ֵ������
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
//����
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

//����
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
//���
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
//�ݻ�
void destory(List* list)
{
	clear(list);
	free(list->first);
	list->first = list->last = NULL;

}