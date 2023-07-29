#include <stdio.h>

int bSearch(int ar[], int len, int target) {
    int first = 0;
    int end = (len - 1);
    int mid;

    // fisrt == end도 포함
    while (first <= end) {
        // 중간 값 구하기
        mid = (first + end) / 2;

        if (target == ar[mid]) {
            return mid;
        }
        else {
            if (target < ar[mid]) {
                end = mid - 1;
            }
            else {
                first = mid + 1;
            }
        }
    }

    return -1;
}

int main(void) {

    int idx;
    int ar[] = {1, 3, 5, 7, 9};

    idx = bSearch(ar, sizeof(ar)/sizeof(int), 7);
    if (idx == -1) {
        printf("탐색 실패\n");
    }
    else {
        printf("타겟 저장 인덱스 :%d\n", idx);
    }

    idx = bSearch(ar, sizeof(ar)/sizeof(int), 10);
    if (idx == -1) {
        printf("탐색 실패");
    }
    else {
        printf("타겟 저장 인덱스 :%d", idx);
    }

    return 0;
}