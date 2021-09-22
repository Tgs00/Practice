#include "SList.h"

Node* _buyNode(ElemType x)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	assert(newNode != NULL);
	newNode->data = x;
	newNode->Next = NULL;
	return newNode;
}

void InitList(List* list)
{
	list->first = list->last = (Node*)malloc(sizeof(Node));
	assert(list->first != NULL);
	list->first->Next = list->last->Next = NULL;
	list->last->Next = list->first;
	list->size = 0;
}

//β�巨
void push_back(List* list, ElemType data)
{
	Node* newNode = _buyNode(data);
	list->last->Next = newNode;
	list->last = newNode;
	list->last->Next = list->first;
	list->size++;

}
//ͷ�巨
void push_front(List* list, ElemType data)
{
	Node* newNode = _buyNode(data);

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
	if (NULL == list->first) { printf("��������\n"); return; }
	Node* showList = list->first->Next;
	if (list->size != 0)
	{
		while (showList != list->first)
		{
			printf("%d-->", showList->data);
			showList = showList->Next;
		}
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

	Node* newNode = list->first;

	while (newNode->Next != list->last)
	{
		newNode = newNode->Next;
	}
	free(list->last);
	list->last = newNode;
	list->last->Next = list->first;
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
//6��ֵ����
void insert_val(List* list, ElemType item)
{
	Node* newNode = _buyNode(item);
	
	Node* tmpNode = list->first;
	while (tmpNode->Next != list->first && newNode->data > tmpNode->Next->data)
	{
		tmpNode = tmpNode->Next;
	}
	if (tmpNode->Next == list->first)
	{
		list->last = newNode;
	}
	newNode->Next = tmpNode->Next;
	tmpNode->Next = newNode;
	list->size++;
}
//7����
Node* find(List* list, ElemType key)
{
	if (0 == list->size) { return NULL; }

	int pos = 1;
	Node* tmpNode = list->first->Next;
	while (tmpNode != list->first && key != tmpNode->data)
	{
		tmpNode = tmpNode->Next;
		pos++;
	}

	if (tmpNode != list->first) { printf("���ݵ�λ��������ĵ�%d���ڵ�\n", pos); }
	if (tmpNode == list->first) { return NULL; }

	return tmpNode;
}
//8����
int length(List* list)
{
	return list->size;
}
//9ɾ��
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

//==================����=======================
void sort(List* list)
{
	if (list->size == 0 || list->size == 1) { return; }

	Node* p1 = list->first->Next;
	Node* p2 = p1->Next;

	list->last = p1;
	p1->Next = list->first;

	while (p2 != list->first)
	{
		p1 = p2;
		p2 = p2->Next;

		Node* tmpNode = list->first;

		while (tmpNode->Next != list->first && p1->data < tmpNode->Next->data)
		{
			tmpNode = tmpNode->Next;
		}
		if (tmpNode->Next == list->first) { list->last = p1; }
		p1->Next = tmpNode->Next;
		tmpNode->Next = p1;
	}


	return;
}

//==================== 11 ���� ========================
void resever(List* list)
{

	if (list->size == 0 || list->size == 1) { return; }

	Node* p1 = list->first->Next;
	Node* p2 = p1->Next;

	list->last = p1;
	p1->Next = list->first;

	while (p2 != list->first)
	{
		p1 = p2;
		p2 = p2->Next;
		Node* tmpNode = list->first;

		p1->Next = list->first->Next;
		list->first->Next = p1;
	}
	return;
}
//======================���========================
void clear(List* list)
{
	if (list->size == 0) { return; }

	Node* tmpNode = list->first->Next;
	while (list->first->Next != list->first)
	{
		list->first->Next = tmpNode->Next;
		free(tmpNode);
		tmpNode = list->first->Next;
	}

	list->last = list->first;
	list->size = 0;

	return;
}
void destory(List* list)
{
	clear(list);
	free(list->first);
	list->last = list->first = NULL;
	return;
}
