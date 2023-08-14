#include "Worker.h"
#ifndef __C_LIKED_LIST_H
#define __C_LIKED_LIST_H

#define TRUE 1;
#define FALSE 0;

typedef Worker Data;

typedef struct _node {
    Data data;
    struct _node * next;
} Node;

typedef struct _CLL {
    Node * tail;
    Node * cur;
    Node * before;
    int numOfData;
} CList;

typedef CList List;

void ListInit(List * plist);
void LInsert(List * plist, Data * data);
void LInsertFront(List * plist, Data data);
void SetWorkerInfo(Worker * info, char name, int num);

int LFirst(List * plist, Data * pdata);   // 정수형 return
int LNext(List * plist, Data * pdata);    // 정수형 return
Data Remove(List * plist);
int LCount(List * plist);

#endif