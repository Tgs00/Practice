#ifndef __SEQLIST_H__
#define __SEQLIST_H__

#include<stdio.h>
#include<malloc.h>
#include<assert.h>
#include<stdbool.h>

#define SEQLIST_INIT_SIZE 8
#define INC_SIZE          3
typedef int ElemType;

typedef struct SeqList
{
	ElemType* base;
	int capacity;
	int size;
}SeqList;

bool Inc(SeqList* List);
void InitSeqList(SeqList* list);
void push_back(SeqList* List, ElemType x);
void push_front(SeqList* List, ElemType x);
void show_list(SeqList* List);
void pop_back(SeqList* List);
void pop_front(SeqList* List);
void insert_pos(SeqList* List, int pos, ElemType x);
int find(SeqList* List, ElemType x);
int lengh(SeqList* List);
void delete_pos(SeqList* List, int pos);
void delete_val(SeqList* List, int x);
void sort(SeqList* List);
void resver(SeqList* List);
void clear(SeqList* List);
void destory(SeqList* List);
void merge(SeqList* Lt, SeqList* La, SeqList* Lb);

#endif //__SEQLIST_H__
