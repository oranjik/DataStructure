#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"

int main(void)
{
	// List의 생성 및 초기화 /////////////////////////////
	List list;
	int data, bb[20], i;

	for (i = 0; i < 20; i++) bb[i] = (int)((double)rand() / RAND_MAX*5.0 + 1.0);

	for (i = 0; i < 20; i++) printf("%d\n", bb[i]);
	ListInit(&list);
	//SetSortRule(&list, compare);

	LRemoveD(&list);
	qsort(bb, 20, sizeof(int), compAsc);
	for (i = 0; i<20; i++) LInsert(&list, bb[i]);

	// 삭제 후 남아있는 데이터 전체 출력 ////////////////////////
	printf("현재 데이터의 수: %d \n-내림차순-\n", LCount(&list));

	if (LFirst(&list, &data))
	{
		printf("%d ", data);

		while (LNext(&list, &data))
			printf("%d ", data);
	}
	printf("\n\n");


	return 0;
}
