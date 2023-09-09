#include <stdio.h>
#include "ListBaseQueue.c"

#define BUCKET_NUM 10

void RadixSort(int arr[], int num, int maxLen) {
    Queue buckets[BUCKET_NUM];
    int bi;
    int pos;
    int di;
    int divfac = 1;
    int radix;

    // 10개 버킷 초기화
    for (bi = 0; bi < BUCKET_NUM; bi++) {
        QueueInit(&buckets[bi]);
    }

    // 가장 긴 데이터수 기준으로 반복 설정
    for (pos = 0; pos < maxLen; pos++){
        // 정렬 대상의 수만큼 반복
        for (di = 0; di < num; di++) {
            // N번째 자리 추출
            radix = (arr[di] / divfac) % 10;

            // 추출한 자리 큐에 넣기
            Enqueue(&buckets[radix], arr[di]);
        }

        for (bi = 0, di = 0; bi < BUCKET_NUM; bi++) {
            while(!QIsEmpty(&buckets[bi])) {
                arr[di++] = Dequeue(&buckets[bi]);
            }
        }

        divfac *= 10;
    }

}

int main(void) {
    int arr[7] = {13, 212, 14, 7141, 10987, 6, 151};
    
    int len = sizeof(arr) / sizeof(int);
    int i;

    RadixSort(arr, len, 5);

    for (i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}