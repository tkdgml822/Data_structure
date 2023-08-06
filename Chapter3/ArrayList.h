#include "NameCard.h"
#ifndef __ARRAY_LIST_H__
#define __ARRAY_LIST_H__

#define TRUE	1
#define FALSE	0

/*** ArrayList�� ���� ****/
#define LIST_LEN	100
// int를 LData로 재정의(전) -> Point 구조체로 변경 
typedef NameCard * LData;

typedef struct __ArrayList {
	// Point의 구고체 100개 생성
	LData arr[LIST_LEN];
	// 데이터 수
	int numOfData;
	// 현재 위치
	int curPosition;
} ArrayList;

/*** ArrayList 재 정의 추상화 ****/
typedef ArrayList List;

void ListInit(List * plist);
void LInsert(List * plist, LData data);

int LFirst(List * plist, LData * pdata);
int LNext(List * plist, LData * pdata);

LData LRemove(List * plist);
int LCount(List * plist);

#endif