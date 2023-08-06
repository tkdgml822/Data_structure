// 총 3명의 전화번호 정보를, 앞서 우리가 구현한 리스트에 저장한다.
// 특정 이름을 대상으로 탐색으로 진행하여, 그 사람의 정보를 출력한다.
// 특정 이름을 대상으로 탐색으로 진행하여, 그 사람의 전화전호 정보를 변경한다.
// 특정 이름을 대상으로 탐색으로 진행하여, 그 사람의 정보를 삭제한다.
// 끝으로 남아있는 모든 사람의 전화번호 정보를 출력한다.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "NameCard.h"

// NameCard 구조체 변수의 동적 할당 및 초기화 후 주소 값 반환 
NameCard * MakeNameCard(char * name, char * phone) {
    NameCard * newCard = (NameCard*)malloc(sizeof(NameCard));
    // 매개변수로 넘어온 name을 newCard->name에 복사해서 넣는다.
    strcpy(newCard->name, name);
    strcpy(newCard->phone, phone);

    return newCard;
}

// NameCard 구조체 변수의 정보 출력
void ShowNamaeCardInfo(NameCard * pcard) {
    printf("[이름] %s \n", pcard->name);
    printf("[번호] %s \n\n", pcard->phone);
}

// 이름이 같으면 0, 다르면 0이 아닌 다른 값
int NameCompare(NameCard * pcard, char * name) {
    return strcmp(pcard->name, name);
}

// 전화번호 정보를 변경
void ChangePhoneNum(NameCard * pcard, char * phone) {
    strcpy(pcard->phone, phone);
}