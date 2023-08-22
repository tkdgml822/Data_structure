#include <stdio.h>
#include <stdlib.h>
#include "Deque.h"


void DequeInit(Deque * pdeq) {
    pdeq->head = NULL;
    pdeq->tail = NULL;
}

int DQIsEmpty(Deque * pdeq) {
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

    newNode->next = pdeq->head;

    // 데이터가 하나도 없을 때
    if(DQIsEmpty(pdeq)) {  
        pdeq->tail= newNode;
    }
    // 데이터가 한개이상 있을 때
    else {
        pdeq->head->prev = newNode;
    }

    newNode->prev = NULL;
    pdeq->head = newNode;
}

// 덱의 꼬리에 데이터 추가
void DQAddLast(Deque * pdeq, Data data) {
    Node * newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    newNode->prev = pdeq->tail;

    // 데이터가 하나도 없을 때
    if(DQIsEmpty(pdeq)) {
        pdeq->head = newNode;
    }
    else {
        pdeq->tail->next = newNode;
    }

    newNode->next = NULL;
    pdeq->tail = newNode;
}

// 덱의 머리에서 데이터 삭제
Data DQRemoveFirst(Deque * pdeq) {
    // 삭제될 데이터
    Data data;
    Node * rpos = pdeq->head;

    if(DQIsEmpty(pdeq)) {
        printf("Deque Memory Error!");
        exit(-1);
    }
    data = pdeq->head->data;

    // 머리 오른쪽으로 옮기기
    pdeq->head = pdeq->head->next;
    // 메모리 해제
    free(rpos);

    // 데이터가 전부 없을때
    if(pdeq->head == NULL) {
        pdeq->tail = NULL;
    }
    // 머리에 있는 노드 삭제후 전 노드를 가르키고 있는 prev을 NULL로 초기화 해줌
    else {
        pdeq->head->prev = NULL;
    }
    
    // 삭제된 데이터 반환    
    return data;
}

// 덱의 꼬리에서 데이터 삭제
Data DQRemoveLast(Deque * pdeq) {
    Data data;
    Node * rpos = pdeq->tail;

    if(DQIsEmpty(pdeq)) {
        printf("Deque Memory Error!");
        exit(-1);
    }
    data = pdeq->tail->data;

    // 꼬리 원쪽으로 옮기기
    pdeq->tail = pdeq->tail->prev;
    free(rpos);

    if(pdeq->tail == NULL) {
        pdeq->head = NULL;
    }
    else {
        pdeq->tail->next = NULL;  
    }
    
    return data;
}

// 덱의 머리에서 데이터 참조
Data DQGetFirst(Deque * pdeq) {
     if(DQIsEmpty(pdeq)) {
        printf("Deque Memory Error!");
        exit(-1);
    }

    return pdeq->head->data;
}

// 덱의 꼬리에서 데이터 참조
Data DQGetLast(Deque * pdeq) {
    if(DQIsEmpty(pdeq)) {
        printf("Deque Memory Error!");
        exit(-1);
    }

    return pdeq->tail->data;
}