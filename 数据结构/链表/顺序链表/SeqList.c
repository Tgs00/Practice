#include "SeqList.h"
//#include <stdio.h>

//初始化列表
void InitSeqList(SeqList* list)
{
	list->base = (ElemType*)malloc(sizeof(ElemType) * SEQLIST_INIT_SIZE);
	assert(list->base != NULL);
	list->capacity = SEQLIST_INIT_SIZE;
	list->size = 0;
}

//尾插法
void push_back(SeqList* List, ElemType x)
{
	if (List->size >= List->capacity && !Inc(List) )
	{
		printf("顺序表空间已满，%d无法再插入\n", x);
	}
	else
	{
		List->base[List->size] = x;
		List->size++;
	}
}

//头插法
void push_front(SeqList* List, ElemType x)
{
	if (List->size >= List->capacity && !Inc(List))
	{
		printf("顺序表空间已满，无法再插入\n");
	}
	else
	{
		for (int i = List->size; i>0; i--)
		{
			List->base[i] = List->base[i-1];
		}
		List->base[0] = x;
		List->size++;
	}
}

//打印列表
void show_list(SeqList* List)
{
	for (int i = 0; i < List->size; ++i)
	{
		printf("%d ", List->base[i]);
	}
	printf("\n");
}

//尾部删除
void pop_back(SeqList* List)
{
	if (0 == List->size)
	{
		printf("链表为空");
		return;
	}
	else
	{
		List->size--;
	}
}

//头部删除
void pop_front(SeqList* List)
{
	if (0 == List->size)
	{
		printf("链表为空");
		return;
	}
	else
	{
		for (int i = 0; i < List->size-1; i++)
		{
			List->base[i] = List->base[i + 1];
		}
		List->size--;
	}
}

//按位置插入
void insert_pos(SeqList* List, int pos, ElemType x)
{
	if (pos < 0 || pos > List->size)
	{
		printf("插入位置错误\n");
		return;
	}
	if (0 == pos)
		push_front(List, x);
	if (List->size == pos)
		push_back(List, x);
	if (List->capacity == List->size && !Inc(List))
	{
		printf("当前表已满，无法插入");
		return;
	}
	else
	{
		for (int i = List->size; i > pos-1; --i)
		{
			List->base[i] = List->base[i - 1];
		}
		List->base[pos-1] = x;
	}
	List->size++;
}

//查找位置
int find(SeqList* List, ElemType x)
{
	int pos;
	for (int i = 0; i < List->size; i++)
	{
		if (x == List->base[i])
		{
			pos = i + 1;
			return pos;
		}
	}
	return -1;
}

//求取数组长度
int lengh(SeqList* List)
{
	return List->size;
}

//按位置删除
void delete_pos(SeqList* List, int pos)
{
	if (pos < 0 || pos > List->size)
		printf("输入错误");
	if (0 == List->size)
	{
		printf("该链表为空，无法删除");
		return;
	}
	for (int i = pos; i < List->size; i++)
	{
		List->base[i - 1] = List->base[i];
	}
	List->size--;
	return;
}

//按值删除
void delete_val(SeqList* List, int x)
{
	if (0 == List->size)
	{
		printf("该链表为空，无法删除");
		return;
	}
	for (int i = 0; i < List->size; i++)
	{
		if (x == List->base[i])
		{
			for (int j = i; j < List->size-1; j++)
			{
				List->base[j] = List->base[j + 1];
			}
			List->size--;
			return;
		}
	}
}

//冒泡排序
void sort(SeqList* List)
{
	ElemType tmp;
	for (int i = 0; i < List->size; i++)
	{
		for (int j = i + 1; j < List->size; j++)
		{
			if (List->base[i] > List->base[j])
			{
				tmp = List->base[i];
				List->base[i] = List->base[j];
				List->base[j] = tmp;
			}
		}
	}
}

//逆置
void resver(SeqList* List)
{
	if (0 == List->size || 1 == List->size)
		return;
	ElemType tmp;
	for (int i = 0; i < List->size / 2; i++)
	{
		tmp = List->base[i];
		List->base[i] = List->base[List->size - i - 1];
		List->base[List->size - i - 1] = tmp;
	}
}

//清除表
void clear(SeqList* List)
{
	List->size = 0;
}

//销毁表
void destory(SeqList* List)
{
	free(List->base);
	List->base = NULL;
	List->capacity = 0;
	List->size = 0;
}

//增加表的长度
bool Inc(SeqList* List)
{
	ElemType* newbase = (ElemType*)realloc(List->base, sizeof(ElemType) * (List->size + INC_SIZE));
	if (NULL == newbase)
	{
		printf("增配空间失败，内存不足！\n");
		return false;
	}
	List->base = newbase;
	List->capacity += INC_SIZE;
	return true;
}

//合并数组
void merge(SeqList* Lt, SeqList* La, SeqList* Lb)
{
	Lt->capacity = La->size + Lb->size;
	Lt->base = (ElemType*)malloc(sizeof(ElemType) * (Lt->capacity));
	assert(NULL != Lt->base);
	int ia = 0;
	int ib = 0;
	int ic = 0;
	while (ia < La->size && ib < Lb->size)
	{
		if (La->base[ia] < Lb->base[ib])
			Lt->base[ic++] = La->base[ia++];
		else
			Lt->base[ic++] = Lb->base[ib++];
	}
	while (ia < La->size)
	{
			Lt->base[ic++] = La->base[ia++];
	}
	while (ib < Lb->size)
	{
			Lt->base[ic++] = Lb->base[ib++];
	}
	Lt->size = La->size + Lb->size;
}