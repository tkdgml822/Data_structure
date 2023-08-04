#include <stdio.h>
#include "ArrayList_Me.h"

// 초기화 함수
void LInit(List *plist) {
    plist->currentLocation = -1;
    plist->numOfData = 0;
}

// 첫번째 데이터를 가져오는 함수
// data 같은 경우는 main.c 함수에서 쓰이는 data 변수의 주소를 받아서 그 변수랑 매개변수를 연결한다.
int LFirst(List *plist, LData *data) {

    // 값이 하나도 없을 때
    if (plist->numOfData == 0) {
        return FALSE;
    }
    
    // 현재 위치 0으로 지정
    plist->currentLocation = 0;
    *data = plist->arr[0];
    return TRUE;
};

// 다음 데이터를 가져오는 함수
int LNext(List *plist, LData *data) {
    if(plist->currentLocation >= (plist->numOfData) - 1) {
        return FALSE;
    }

    // 현재 index 1 증가 후 data에다가 대입
    (plist->currentLocation)++;
    *data = plist->arr[plist->currentLocation];
    return TRUE;
}

void LInsert(List *plist, LData *data) {
    // 정해둔 데이터를 넘어가면 False
    if(MAXLENGTH < plist->numOfData) {
        printf("용량 초과");

        return;
    }

    // arr[plist->currentLocation]을 하면 현재 위치에 있는 값을 덮어 써보리기 때문에
    // 배열의 맨 오른쪽에 넣기 위해서 arr[plist->numOfData]을 하면 맨 오른쪽 빈 곳에다가 대입한다.
    // 그리고 나서 numOfData를 +1을 해주면 된다.
    // 참고로 주의사항으로 numOfData - 1을 하면 안된다. 
    //-1을 하면 배열은 index 값이 0부터 시작하기 떄문에 맨 오르쪽에 값을 덮어쓴다.
    plist->arr[plist->numOfData] = *data;

    // 데이터를 넣으면 갯수가 늘어남
    (plist->numOfData)++;
}

// 데이터를 지우는 함수 (중요!)
int Remove(List *plist) {
    // 현재 지울려는 데이터의 위치
    int nowCur = plist->currentLocation;
    // 현재 데이터 수
    int dataCount = plist->numOfData;
    // 삭제할 변수
    LData data = plist->arr[nowCur];

    for(int i = nowCur; i < dataCount - 1; i++) {
        plist->arr[i] = plist->arr[i+1];
    }
    
    
    (plist->numOfData)-- ;
    (plist->currentLocation)--;
    // 삭제한 데이터를 알려준다.
    return data;
}

// 리스트의 데이터 수를 가져오는 함수
int LCount (List *plist) {
    return plist->currentLocation;
}