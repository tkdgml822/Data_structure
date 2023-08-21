#include <stdio.h>
#include <stdlib.h>
#include "ListBaseQueue.h"

// 큐 초기화
void QueueInit(Queue * pq) {
    pq->front = NULL;
    pq->rear = NULL;
}

// 데이터가 들어있는지 검사
int QIsEmpty(Queue * pq) {
    if(pq->front == NULL) {
        return TRUE;
    }
    else {
        return FALSE;
    }
}

// 데이터 넣기
void Enqueue(Queue * pq, Data data) {
    Node * newNode = (Node*)malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->data = data;

    if(pq->front == NULL) {
        pq->front = newNode;
        pq->rear = newNode;
    }
    else {
        pq->rear->next = newNode;
        pq->rear = newNode;
    }
}

// 데이터 빼기
Data Dequeue(Queue * pq) {
    Node * delNode;
    Data retData;

    if(QIsEmpty(pq)) {
        printf("Queue Memory Error!");
        exit(-1);
    }

    delNode = pq->front;
    retData = delNode->data;
    pq->front = pq->front->next;

    free(delNode);
    return retData;
}

Data QPeek(Queue * pq) {
    if(QIsEmpty(pq)) {
        printf("Queue Memory Error!");
        exit(-1);
    }

    return pq->front->data;
}