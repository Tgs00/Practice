#include"staticLink.h"

int malloc_SL(staticList& space)
{
	int i = space[1].cur;
	if (i != 0)
	{
		space[1].cur = space[i].cur;
	}
	return i;
}

void InitList(staticList& space)
{
	for (int i = 1; i < MAX_SIZE - 1; ++i)	{ space[i].cur = i+1; }
	space[0].cur = -1;
	space[MAX_SIZE - 1].cur = 0;
}

void insert(staticList& space, char t)
{
	int i = malloc_SL(space);
	if (i == 0)
	{
		printf("申请节点失败！\n");
		return;
	}
	space[i].data = t;

	if (space[0].cur == -1)
	{
		space[i].cur = -1;
	}
	else
	{
		space[i].cur = space[0].cur;
	}
	space[0].cur = i;
	return;
}

void showList(staticList& space)
{
	int i = space[0].cur;
	while (i != -1)
	{
		printf("%c-->", space[i].data);
		i = space[i].cur;
	}
	printf("NULL\n");
	return;
}

void deleteSL(staticList& space)
{
	if (space[0].cur == -1)
	{
		printf("链表为空！\n");
		return;
	}
	int i = space[0].cur;
	space[0].cur = space[i].cur;

	freeSL(space, i);
}

void freeSL(staticList& space, int k)
{
	space[k].cur = space[1].cur;
	space[1].cur = k;
}