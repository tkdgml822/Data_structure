#include <stdio.h>
#include "DBDLinkedList.c"

int main(void) {
	List list;
	int data;
	ListInit(&list);

    // 8개 데이터 추가
	LInsert(&list, 1);  LInsert(&list, 2);
	LInsert(&list, 3);  LInsert(&list, 4);
	LInsert(&list, 5);  LInsert(&list, 6);
	LInsert(&list, 7);  LInsert(&list, 8);

	// 데이터 출력
	if(LFirst(&list, &data)) {
		printf("%d ", data);

		while(LNext(&list, &data)) 
			printf("%d ", data);
		
		printf("\n");
	}

	// 2의 배수 삭제
	if(LFirst(&list, &data)) {
		if(data%2 == 0)
			LRemove(&list);

		while(LNext(&list, &data)) 
		{		
			if(data%2 == 0) {
				LRemove(&list);
			}
		}
	}

    // 다시 출력
	if(LFirst(&list, &data)) {
		printf("%d ", data);

		while(LNext(&list, &data)) 
			printf("%d ", data);
		
		printf("\n\n");
	}

	return 0;
}