#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.c"
#include "NameCard.c"

int main(void) {
    List list;
    NameCard * pcard;
    ListInit(&list);

    pcard = MakeNameCard("이진수", "010-1111-2222");
    LInsert(&list, pcard);

    pcard = MakeNameCard("한지영", "010-2222-5555");
    LInsert(&list, pcard);

    pcard = MakeNameCard("조수진", "010-3333-7777");
    LInsert(&list, pcard);

    // 한지영의 정보를 조회하여 출력
    if(LFirst(&list, &pcard)) {
        // NameCompare가 실패시 아래 코드 실행
        // 즉 이름이 같으면 0이 나오기 때문에 ! 때문에 주어진 데이터가 존재하면 아래에 있는 코드가 실행이된다.
        if(!NameCompare(pcard, "한지영")) {
            ShowNamaeCardInfo(pcard);
        }
        // "한지영"이라는 이름이 없으면 다음 코드를 진행시켜 한지영을 찾아낸다.
        else {
            while(LNext(&list, &pcard)) {
                if(!NameCompare(pcard, "한지영")) {
                    ShowNamaeCardInfo(pcard);
                    break;
                }
            }
        }
    }

    // 이진수의 정보를 조회하여 변경
    if(LFirst(&list, &pcard)) {
        if(!NameCompare(pcard, "이진수")) {
            ChangePhoneNum(pcard, "010-9999-9999");
        }
        else {
            while(LNext(&list, &pcard)) {
                if(!NameCompare(pcard, "이진수")) {
                    ChangePhoneNum(pcard, "010-9999-9999");
                    break;
                }
            }
        }
    }

    // 조수진의 정보를 조회하여 삭제
    if(LFirst(&list, &pcard)) {
        if(!NameCompare(pcard, "조수진")) {
            pcard = LRemove(&list);
            free(pcard);
        }
        else {
            while(LNext(&list, &pcard)) {
                if(!NameCompare(pcard, "조수진")) {
                    pcard = LRemove(&list);
                    free(pcard);
                    break;
                }
            }
        }
    }

    // 모든 사람의 정보 출력
    printf("현재 데이터의 수 : %d \n", LCount(&list));

    if(LFirst(&list, &pcard)) {
        ShowNamaeCardInfo(pcard);

        while(LNext(&list, &pcard)) {
            ShowNamaeCardInfo(pcard);
        }
    }

    return 0; 
}
