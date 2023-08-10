#include <stdio.h>
#include <stdlib.h>
#include "Point.c"
#include "DLinkedList.c"

// 정렬 규칙
int pointSort(LData d1, LData d2) {
    int x1 = d1->xpos, x2 = d2->xpos;
    int y1 = d1->xpos, y2 = d2->ypos;

    if (x1 > x2) {
        return 0;
    }
    else if (x1 == x2){
        // x가 같을 경우 y로 판단
        if (y1 > y2) {
            return 0;
        }
        else {
            return 1;
        }
    }
    else {
        return 1;
    }
    
}

int main(void) {
    List list;
    Point compPos;
    Point * ppos;

    // 초기화 
    ListInit(&list);

    SetSortRule(&list, pointSort);

    // 4개의 데이터 저장
    ppos = (Point*)malloc(sizeof(Point));
    SetPointPos(ppos, 2, 1);
    LInsert(&list, ppos);

    ppos = (Point*)malloc(sizeof(Point));
    SetPointPos(ppos, 2, 2);
    LInsert(&list, ppos);

    ppos = (Point*)malloc(sizeof(Point));
    SetPointPos(ppos, 3, 1);
    LInsert(&list, ppos);

    ppos = (Point*)malloc(sizeof(Point));
    SetPointPos(ppos, 3, 2);
    LInsert(&list, ppos);

    // 저장된 데이터의 출력
    printf("현재 데이터의 수 %d\n", LCount(&list));

    if(LFirst(&list, &ppos)) {
        ShowPointPos(ppos);

        while(LNext(&list, &ppos)) {
            ShowPointPos(ppos);
        }
    }
    printf("\n");

    // xpos가 2인 모든 데이터 삭제
    compPos.xpos = 2;
    compPos.ypos = 0;

    if(LFirst(&list, &ppos)) {
        if(PointComp(ppos, &compPos) == 1) {
            ppos = LRemove(&list);
            free(ppos);
        }

        while(LNext(&list, &ppos)) {
            if(PointComp(ppos, &compPos) == 1) {
            ppos = LRemove(&list);
            free(ppos);
        }
        }
    }

    printf("현재 데이터의 수 %d\n", LCount(&list));

    if(LFirst(&list, &ppos)) {
        ShowPointPos(ppos);

        while(LNext(&list, &ppos)) {
            ShowPointPos(ppos);
        }
    }
    printf("\n");

    return 0;
}