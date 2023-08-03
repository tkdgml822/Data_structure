#include <stdio.h>
#include "ArrayList.h"
#include "ArrayList.c"

// 리스트를 생성 및 초기화 한 다음, 정수 1부터 9까지 리스트에 저장한다.
// 리스트에 저장된 값을 순차적으로 참조하여 그 합을 계산하여 출력한다.
// 리스트에 저장된 값들 중 2의 배수와 3의 배수에 해당하는 값을 모두 삭제한다.
// 마지막으로 리스트에 저장된 데이터를 순서대로 출력한다. 
int main(void) {
    List list;
    int data;
    int sum;
    
    // 초기화
    ListInit(&list);
    // 값 넣기 (1 ~ 9)
    LInsert(&list, 1);
    LInsert(&list, 2);
    LInsert(&list, 3);
    LInsert(&list, 4);
    LInsert(&list, 5);
    LInsert(&list, 6);
    LInsert(&list, 7);
    LInsert(&list, 8);
    LInsert(&list, 9);

    // 리스트 합
    if(LFirst(&list, &data)) {
        while(LNext(&list, &data)) {
            sum += data;
        }
    };

    // 합 출력하기
    printf("%d \n", sum);

    // 2와 3의 배수 삭제하기
    if(LFirst(&list, &data)) {
        if (((data % 2) == 0) && ((data % 3) == 0)) {
                
        }
        while(LNext(&list, &data)) {
            sum += data;
        }
    };


    return 0;
}
