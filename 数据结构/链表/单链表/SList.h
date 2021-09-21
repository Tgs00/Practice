#ifndef __SLIST_H__
#define __SLIST_H__

#include<stdio.h>
#include<malloc.h>
#include<assert.h>

#define ElemType int

typedef struct Node
{
	ElemType data;
	struct Node* Next;
}Node, *PNode;

typedef struct List
{
	PNode first;
	PNode last;
	size_t size;
}List;

void InitList(List* list);
void push_back(List* list, ElemType data);
void push_front(List* list, ElemType data);
void show_list(List* list);
void pop_back(List* list);
void pop_front(List* list);
void insert_val(List* list, ElemType item);
Node* find(List* list, ElemType key);
int length(List* list);
void delete_val(List* list, ElemType item);
void sort(List* list);
void resver(List* list);
void clear(List* list);
void destory(List* list);
#endif