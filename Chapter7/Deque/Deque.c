#include <stdio.h>
#include <stdlib.h>
#include "Deque.h"


void DequeInit(Deque * pdeq) {
    pdeq->head = NULL;
    pdeq->tail = NULL;
}

int DISEmpty(Deque * pdeq) {
    if(pdeq->head == NULL) {
        return TRUE;
    }
    else {
        return FALSE;
    }
}

// 덱의 머리에 데이터 추가
void DQAddFirst(Deque * pdeq, Data data) {
    Node * newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    // 데이터가 하나도 없을 때
    if(pdeq->head == NULL) {
        newNode->next = NULL;
        newNode->prev = NULL;
        
        newNode = pdeq->head;
        newNode = pdeq->tail;
    }
    // 데이터가 한개이상 있을 때
    else {
        newNode->prev = NULL;
        newNode->next = pdeq->head;
        pdeq->head->prev = newNode;
        newNode = pdeq->head;
    }
}

// 덱의 꼬리에 데이터 추가
void DQAddLast(Deque * pdeq, Data data) {
    Node * newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    // 데이터가 하나도 없을 때
    // 데이터가 하나도 없을 때
    if(pdeq->head == NULL) {
        newNode->next = NULL;
        newNode->prev = NULL;
        
        newNode = pdeq->head;
        newNode = pdeq->tail;
    }
    else {
        newNode->next = NULL;
        newNode->prev = pdeq->tail;
        pdeq->tail->next = newNode;
        newNode = pdeq->tail;
    }
}

// 덱의 머리에서 데이터 삭제
Data DQRemoveFirst(Deque * pdeq) {
    // 삭제될 데이터
    Data data = pdeq->head->data;
    Node * rpos = pdeq->head;
    
    // 머리 다음에 있는거 NULL로 해주기
    pdeq->head->next->prev = NULL;
    // 머리 오른쪽으로 옮기기
    pdeq->head->next = pdeq->head;

    // 메모리 해제
    free(rpos);
    
    // 삭제된 데이터 반환    
    return data;
}

// 덱의 꼬리에서 데이터 삭제
Data DQRemoveLast(Deque * pdeq) {
    Data data = pdeq->tail->data;
    Node * rpos = pdeq->tail;

    pdeq->tail->prev->next = NULL;  
    // 꼬리 원쪽으로 옮기기
    pdeq->tail->prev = pdeq->tail;

    free(rpos);

    return data;
}

// 덱의 머리에서 데이터 참조
Data DQGetFirst(Deque * pdeq) {
    Data data = pdeq->head->data;
    
    return data;
}

// 덱의 꼬리에서 데이터 참조
Data DQGetLast(Deque * pdeq) {
    Data data = pdeq->tail->data;

    return data;
}