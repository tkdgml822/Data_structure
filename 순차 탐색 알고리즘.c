#include <stdio.h>

// 배열, 크기, 배열의 크기, 찾는 목표
int Lsearch(int arr[], int len, int target) {
    int i;

    // 배열을 순서대로 돌면서 찾는 숫자가 나오면 그 숫자의 인덱스를 return
    for (i = 0; i < len; i++) {
        if (arr[i] == target) {
            return i; 
        }
    }

    return -1;

}

int main(void) {
    int idx;

    int arr[] = {4, 5, 6, 7, 3, 8};

    idx = Lsearch(arr, sizeof(arr)/sizeof(int), 7);

    // -1이 나올시 탐색 실패
    if (idx == -1) {
        printf("탐색 실패!\n");
    }
    else {
        printf("타겟 저장 인덱스 : %d\n", idx);
    }

    idx = Lsearch(arr, sizeof(arr)/sizeof(int), 10);

    if (idx == -1) {
        printf("탐색 실패!\n");
    }
    else {
        printf("타겟 저장 인덱스 : %d", idx);
    }
    
    return 0;
}