#include <stdio.h>
#include "ArrayList.c"

int main(void) {
    List list;
    int data;
    ListInit(&list);

    // data Insert
    LInsert(&list, 11);
    LInsert(&list, 11);
    LInsert(&list, 22);
    LInsert(&list, 22);
    LInsert(&list, 33);

    // data_count print
    printf("현재 리스트에 저장된 데이터 수 : %d \n", LCount(&list));

    // first_data check
    if(LFirst(&list, &data)) {
        printf("%d ", data);

        while(LNext(&list, &data)) {
            printf("%d ", data);
        }
    };
    printf("\n\n");
    
    //quest number "22"
    if(LFirst(&list, &data)) {
        // 첫 번째로 가져온 값이 22이면 삭제한다.
        if(data == 22) {
            LRemove(&list);
        }

        // 반복문을 써서 List에 있는 22를 찾는다.
        while(LNext(&list, &data)) {
            if (data == 22) {
                LRemove(&list);
            }
        }
    }

    // Remove data and print All Data counts
    printf("현재 데이터 수: %d \n", LCount(&list));

    if(LFirst(&list, &data)) {
        printf("%d ", data);

        while(LNext(&list, &data)) {
            printf("%d ", data);
        }
        printf("\n");
    }

    printf("\n\n");
    return 0;
}