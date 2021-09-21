#ifndef __STATICLINK_H__
#define __STATICLINK_H__

#include<stdio.h>
#include"staticLink.h"

#define MAX_SIZE 20
#define ElemType char

typedef struct ListNode
{
	ElemType data;
	int cur;
}ListNode;

typedef ListNode staticList[MAX_SIZE];

int malloc_SL(staticList& space);

void InitList(staticList& space);
void insert(staticList& space, char);
void showList(staticList& space);
void deleteSL(staticList& space);
void freeSL(staticList& space, int k);
#endif