// 한번만 부르게 방지
#ifndef ArrayList_Me
#define ArrayList_Me

// 0, 1 이름
#define FALSE 0   
#define TRUE 1

// 최대 길이
#define MAXLENGTH 100

// int 재 정의
typedef int LData;

// 구조체 생성
typedef struct _ArrayList {
    //
    LData arr[MAXLENGTH];
    // 현재 위치
    int currentLocation;
    // 데이터 수
    int numOfData;
} ArratList;

// ArrayList를 다시 추상화
typedef ArratList List;

// 데이터를 초기화 하는 함수
void LInit(List *plist);
// 첫번 째 데이터를 가져오는 함수
int LFirst(List *plist, LData *data);
// 다음 데이터를 가져오는 함수
int LNext(List *plist, LData *data);
// 데이터를 넣을 함수
void LInsert(List *plist, LData *data);
// 데이터를 지우는 함수
int LRemove(List *plist, LData *data);
// 리스트의 데이터 수를 가져오는 함수
int LCount (List *plist);



#endif