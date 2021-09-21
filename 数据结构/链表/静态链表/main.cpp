#include"staticLink.h"

int main(void)
{
	staticList SL;
	InitList(SL);
	for (int i = 0; i < 5; ++i) { insert(SL, 'A'+i); }
	showList(SL);
	deleteSL(SL);
	showList(SL);
	getchar();
	return 0;
}