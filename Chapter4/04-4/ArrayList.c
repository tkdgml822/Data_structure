#include <stdio.h>
#include "ArrayList.h"

void ListInit(List * plist) {
	(plist->numOfData) = 0;
	(plist->curPosition) = -1;
}

void LInsert(List * plist, LData data)
{
	if(plist->numOfData > LIST_LEN) 
	{
		puts("������ �Ұ����մϴ�.");
		return;
	}

	plist->arr[plist->numOfData] = data;
	(plist->numOfData)++;
}

int LFirst(List * plist, LData * pdata)
{
	if(plist->numOfData == 0) {
		return FALSE;
	}

	(plist->curPosition) = 0;;
	*pdata = plist->arr[0];
	return TRUE;
}

int LNext(List * plist, LData * pdata) {
	// 현재 위치가 데이터의 수 보다 커지거나 같으면 FALSE return
	if(plist->curPosition >= (plist->numOfData)-1) {
		return FALSE;
	}

	// index plus
	(plist->curPosition)++;
	// +1이된 증간한 값을 pdata 대입
	*pdata = plist->arr[plist->curPosition];

	return TRUE;
}

LData LRemove(List * plist) {
	int rpos = plist->curPosition;
	int num = plist->numOfData;
	int i;
	LData rdata = plist->arr[rpos];

	// 없애진 숫자를 한 칸씩 뒤로 미룬다.
	for(i=rpos; i<num-1; i++) {
		plist->arr[i] = plist->arr[i+1];
	}
	
	// 없어지고 나서 데이터 수와 현재 위치를 하나 빼준다.
	(plist->numOfData)--;
	(plist->curPosition)--;
	return rdata;
}

int LCount(List * plist)
{
	return plist->numOfData;
}