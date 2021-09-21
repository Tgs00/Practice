#include<stdio.h>
#include<assert.h>
#include<malloc.h>

#define ElemType int
#define Length   3

typedef struct ListNode
{
	ElemType data;
	struct ListNode* Next;
}ListNode;

typedef ListNode* List;

void InitList(List* head);

//CreateList(List* head)
//{
//	*head = (ListNode*)malloc(sizeof(ListNode));
//	assert(head != NULL);
//	(*head)->data = 1;
//	(*head)->Next = NULL;
//
//	ListNode* p = *head;
//	for (int i = 2; i <= 10; i++)
//	{
//		ListNode* s = (ListNode*)malloc(sizeof(ListNode));
//		s->data = i;
//		s->Next = NULL;
//
//		p->Next = s;
//		p = s;
//	}
//}

void CreateList(List* head)
{
	//*head = (ListNode*)malloc(sizeof(ListNode));
	//assert(head != NULL);
	//(*head)->data = 1;
	//(*head)->Next = NULL;

	//ListNode* p = *head;
	//for (int i = 2; i < 10; i++)
	//{
	//	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	//	assert(newNode != NULL);
	//	newNode->data = i;
	//	newNode->Next = *head;
	//	*head = newNode;
	//}

	//for (int i = 1; i < 10; ++i)
	//{
	//	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	//	newNode->Next = (*head)->Next;
	//	newNode->data = i;
	//	(*head)->Next = newNode;
	//}

	ListNode* p = *head;
	for (int i = 1; i < 10; ++i)
	{
		p = p->Next = (ListNode*)malloc(sizeof(ListNode));
		assert(p != NULL);
		p->data = i;
		p->Next = NULL;
	}
}

void ShowList(List head)
{
	ListNode* p = head->Next;
	while (p != NULL)
	{
		printf("%d-->", p->data);
		p = p->Next;
	}
	printf("NULL");
}

int main()
{
	List myList;
	InitList(&myList);
	CreateList(&myList);
	ShowList(myList);
	return 0;
}

void InitList(List* head)
{
	(*head) = (ListNode*)malloc(sizeof(ListNode));
	assert(NULL != *head);
	(*head)->Next = NULL;


}