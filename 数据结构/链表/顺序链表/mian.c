#define _CRT_SECURE_NO_WARNINGS
#include "SeqList.h"

int main()
{
	SeqList myList, youList, List;
	InitSeqList(&myList);
	InitSeqList(&youList);

	push_back(&myList, 1);
	push_back(&myList, 3);
	push_back(&myList, 5);
	push_back(&myList, 7);

	push_back(&youList, 1);
	push_back(&youList, 2);
	push_back(&youList, 4);
	merge(&List, &myList, &youList);
	show_list(&List);
	return 0;
}

/*
int main()
{
	SeqList myList;
	InitSeqList(&myList);

	ElemType Item;
	int pos;

	int select = 1;
	while (select)
	{
		printf("===========================\n");
		printf("[1]  push_back   [2] push_front\n");
		printf("[3]  show_list   [4] pop_back\n");
		printf("[5]  pop_front   [6] insert_pos\n");
		printf("[7]  find        [8] lengh\n");
		printf("[9]  delete_pos  [10] delete_val\n");
		printf("[11] sort        [12] resver\n");
		printf("[13] clear       [14*] destory\n");
		printf("[0]  quit_system\n");
		printf("===========================\n");
		printf("��ѡ��\n");
		scanf("%d", &select);
		if (select == 0)
			break;
		switch (select)
		{
		case 1:
			printf("������Ҫ���������(-1����)��\n");
			while (scanf("%d", &Item), Item != -1)
			{
				push_back(&myList, Item);
			}
			break;
		case 2:
			printf("������Ҫ���������(-1����)��\n");
			while (scanf("%d", &Item), Item != -1)
			{
				push_front(&myList, Item);
			}
			break;
		case 3:
			show_list(&myList);
			break;
		case 4:
			pop_back(&myList);
			break;
		case 5:
			pop_front(&myList);
			break;
		case 6:
			printf("��������Ҫ�����ֵ");
			scanf("%d", &Item);
			printf("��������Ҫ�����λ��");
			scanf("%d", &pos);
			insert_pos(&myList, pos, Item);
			break;
		case 7:
			printf("��������Ҫ���ҵ����ݣ�");
			scanf("%d", &Item);
			if (-1 == Item)
				printf("���ҵ����ݲ�����\n");
			else
			{
				pos = find(&myList, Item);
				printf("�����ݵ�λ���ǣ�%d\n", pos);
			}
			break;
		case 8:
			printf("����ĳ����ǣ�%d\n", lengh(&myList) );
			break;
		case 9:
			printf("������Ҫɾ����λ�ã�");
			scanf("%d", &pos);
			delete_pos(&myList, pos);
			break;
		case 10:
			printf("������Ҫɾ����ֵ��");
			scanf("%d", &Item);
			delete_val(&myList, Item);
			break;
		case 11:
			sort(&myList);
			break;
		case 12:
			resver(&myList);
			break;
		case 13:
			clear(&myList);
			break;
		һ�㲻�����û��ݻ٣�Ӧ�ڳ������ʱ�Զ��ݻ٣�
		case 14:
			destory(&myList);
			break;
		default:
			printf("�������!\n");
			break;
		}
	}
	destory(&myList);
	return 0;
}

*/