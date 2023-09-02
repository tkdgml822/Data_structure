#include <stdio.h>
#include <stdlib.h>

// 배열을 합치는 역할
void MergeTwoArea(int arr[], int left, int mid, int right) {
    int fIdx = left;
    int rIdx = mid + 1;
    int i;

    int * sortArr = (int*)malloc(sizeof(int)*(right + 1));
    int sIdx = left;

    while(fIdx <= mid && rIdx <= right) {
        if(arr[fIdx] <= arr[rIdx]) {
            sortArr[sIdx] = arr[fIdx++];
        }
        else {
            sortArr[sIdx] = arr[rIdx++];
        }

        sIdx++;
    }
}

// 나눠진 배열을 정렬하는 역할
void MergeSort(int arr[], int left, int right ) {
    int mid;

    if(left < right) {
        // 중간 지점 계산
        mid = (left + right) / 2;

        // 둘로 나눠서 각각을 정렬한다.
        MergeSort(arr, left, mid);
        MergeSort(arr, mid + 1, right);

        MergeTwoArea(arr, left, mid, right);
    }
}

int main(void) {
    int arr[7] = {3, 2, 4, 1, 7, 6, 5};
    int i;

    MergeSort(arr, 0, (sizeof(arr) / sizeof(int)));

    for(i=0; i<7; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
    return 0;
}