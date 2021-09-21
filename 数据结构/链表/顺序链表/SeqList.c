#include "SeqList.h"
//#include <stdio.h>

//��ʼ���б�
void InitSeqList(SeqList* list)
{
	list->base = (ElemType*)malloc(sizeof(ElemType) * SEQLIST_INIT_SIZE);
	assert(list->base != NULL);
	list->capacity = SEQLIST_INIT_SIZE;
	list->size = 0;
}

//β�巨
void push_back(SeqList* List, ElemType x)
{
	if (List->size >= List->capacity && !Inc(List) )
	{
		printf("˳���ռ�������%d�޷��ٲ���\n", x);
	}
	else
	{
		List->base[List->size] = x;
		List->size++;
	}
}

//ͷ�巨
void push_front(SeqList* List, ElemType x)
{
	if (List->size >= List->capacity && !Inc(List))
	{
		printf("˳���ռ��������޷��ٲ���\n");
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

//��ӡ�б�
void show_list(SeqList* List)
{
	for (int i = 0; i < List->size; ++i)
	{
		printf("%d ", List->base[i]);
	}
	printf("\n");
}

//β��ɾ��
void pop_back(SeqList* List)
{
	if (0 == List->size)
	{
		printf("����Ϊ��");
		return;
	}
	else
	{
		List->size--;
	}
}

//ͷ��ɾ��
void pop_front(SeqList* List)
{
	if (0 == List->size)
	{
		printf("����Ϊ��");
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

//��λ�ò���
void insert_pos(SeqList* List, int pos, ElemType x)
{
	if (pos < 0 || pos > List->size)
	{
		printf("����λ�ô���\n");
		return;
	}
	if (0 == pos)
		push_front(List, x);
	if (List->size == pos)
		push_back(List, x);
	if (List->capacity == List->size && !Inc(List))
	{
		printf("��ǰ���������޷�����");
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

//����λ��
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

//��ȡ���鳤��
int lengh(SeqList* List)
{
	return List->size;
}

//��λ��ɾ��
void delete_pos(SeqList* List, int pos)
{
	if (pos < 0 || pos > List->size)
		printf("�������");
	if (0 == List->size)
	{
		printf("������Ϊ�գ��޷�ɾ��");
		return;
	}
	for (int i = pos; i < List->size; i++)
	{
		List->base[i - 1] = List->base[i];
	}
	List->size--;
	return;
}

//��ֵɾ��
void delete_val(SeqList* List, int x)
{
	if (0 == List->size)
	{
		printf("������Ϊ�գ��޷�ɾ��");
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

//ð������
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

//����
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

//�����
void clear(SeqList* List)
{
	List->size = 0;
}

//���ٱ�
void destory(SeqList* List)
{
	free(List->base);
	List->base = NULL;
	List->capacity = 0;
	List->size = 0;
}

//���ӱ�ĳ���
bool Inc(SeqList* List)
{
	ElemType* newbase = (ElemType*)realloc(List->base, sizeof(ElemType) * (List->size + INC_SIZE));
	if (NULL == newbase)
	{
		printf("����ռ�ʧ�ܣ��ڴ治�㣡\n");
		return false;
	}
	List->base = newbase;
	List->capacity += INC_SIZE;
	return true;
}

//�ϲ�����
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