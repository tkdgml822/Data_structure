#include <stdio.h>
#include <stdlib.h>
#include "CLLinkedList.h"

// Stack 만들기 및 초기화
void StackInit(Stack * pstack) {
    pstack->plist = (List*)malloc(sizeof(List)); 
    ListInit(pstack->plist);
}

// 데이터가 있는지 확인
int SIsEmpty(Stack * pstack) {
    if(LCount(pstack->plist) == 0) {
        return TRUE;
    }
    else {
        return FALSE;
    }
}

// 데이터 넣기
void SPush(Stack * pstack, Data data) {
    LInsertFront(pstack->plist, data);
}

// 데이터 조회 및 삭제
Data SPop(Stack * pstack) {
    if(SIsEmpty(pstack)) {
        printf("Stack Memory Error!");
        exit(-1);
    }

    Data data = pstack->plist->tail->data;
    LFirst(pstack->plist, &data);
    LRemove(pstack->plist);

    return data;
}

Data SPeek(Stack * pstack) {
    if(SIsEmpty(pstack)) {
        printf("Stack Memory Error!");
        exit(-1);
    }

    return pstack->plist->numOfData;
}