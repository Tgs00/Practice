#define _CRT_SECURE_NO_WARNINGS
#include"DList.h"

int main(void)
{
	List myList;
	InitList(&myList);

	int select = 1;
	ElemType Item;

	while (select)
	{
		printf("===========================\n");
		printf("[1]  push_back    [2] push_front\n");
		printf("[3]  show_list    [4] pop_back\n");
		printf("[5]  pop_front    [6] insert_val\n");
		printf("[7]  find         [8] lengh\n");
		printf("                  [9] delete_val\n");
		printf("[10] sort         [11] resver\n");
		printf("[12] clear        [13*] destory\n");
		printf("[0]  quit_system\n");
		printf("===========================\n");
		printf("请选择；\n");
		scanf("%d", &select);
		if (select == 0)
			break;
		switch (select)
		{
		case 1:
			printf("请输入需要插入的数据：（-1结束）");
			while (scanf("%d", &Item), Item != -1)
			{
				push_back(&myList, Item);
			}
			break;
		case 2:
			printf("请输入需要插入的数据：（-1结束）");
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
		case 5:
			pop_front(&myList);
			break;
		case 6:
			printf("请输入需要插入的值：");
			scanf("%d", &Item);
			insert_val(&myList, Item);
			break;
		case 7:
			printf("请输入需要查找的值：");
			scanf("%d", &Item);
			Node* address = find(&myList, Item);
			if (address == NULL)
				printf("数据不存在\n");
			break;
		case 8:
			printf("单链表的长度为：%d\n", length(&myList));
			break;
		case 9:
			printf("请输入需要删除的值：");
			scanf("%d", &Item);
			delete_val(&myList, Item);
			break;
		case 10:
			sort(&myList);
			break;
		case 11:
			resever(&myList);
			break;
		case 12:
			clear(&myList);
			break;
		case 13:
			destory(&myList);
			break;
		default:
			break;
		}
	}

	return 0;
}