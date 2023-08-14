#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CLinkedList.c"
#include "Worker.h"

Worker * NightWorker(List * list, char * name, int day);
void ShowWorkerInfo(Worker * num);

int main(void) {
    // 리스트 생성 및 초기화
    List list;
    ListInit(&list);
    
    Worker * workerInfo;

    // 네명의 직원 정보 입력
    workerInfo = (Worker*)malloc(sizeof(Worker));
    workerInfo->empNum = 11111;
    strcpy(workerInfo->name, "김지수");
    LInsert(&list, workerInfo);

    workerInfo = (Worker*)malloc(sizeof(Worker));
    workerInfo->empNum = 12345;
    strcpy(workerInfo->name, "이기자");
    LInsert(&list, workerInfo);

    workerInfo = (Worker*)malloc(sizeof(Worker));
    workerInfo->empNum = 45678;
    strcpy(workerInfo->name, "김아영");
    LInsert(&list, workerInfo);

    workerInfo = (Worker*)malloc(sizeof(Worker));
    workerInfo->empNum = 98772;
    strcpy(workerInfo->name, "이지은");
    LInsert(&list, workerInfo);

    // 메모리 소멸
    if(LFirst(&list, workerInfo)) {
        Remove(&list);
        for (int i = 0; i < LCount(&list)- 1; i++) {
            if(LNext(&list, workerInfo)) {
                Remove(&list);
            }
        }
    }

    // 나이트워커 (야근좌)
    workerInfo = NightWorker(&list, "이지은", 3);
    ShowWorkerInfo(workerInfo);

    workerInfo = NightWorker(&list, "김아영", 15);
    ShowWorkerInfo(workerInfo);

    // 숫자로 당직 정보 반환
    return 0;
}

Worker * NightWorker(List * plist, char * name, int day) {
    int i, num;
    Worker * nightWorker;

    num = LCount(plist);

    LFirst(plist, nightWorker);

    if(strcmp(nightWorker->name, name) != 0) {
        for(i = 0; i < num - 1; i++) {
            LNext(plist, nightWorker);

            if(strcmp(nightWorker->name, name) == 0) {
                break;
            }
        }

        if(i >= num - 1) {
            return NULL;
        }
    }

    for(i = 0; i < day; i++) {
        LNext(plist, nightWorker);
    }

    return nightWorker;
}

void ShowWorkerInfo(Worker * num) {
    printf("이름 : %s \n", num->name);
    printf("번호 : %d \n\n", num->empNum);
}