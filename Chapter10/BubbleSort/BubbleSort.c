#include <stdio.h>

void BubbleSort(int arr[], int n) {
    int i, j;
    int temp;
    
    // 데이터가 4개니깐 4번 반복
    for(i = 0; i < n-1; i++) {
        // 하나의 데이터가 각각 돌아다니면서 비교
        for (j = 0; j < (n - i) - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                // 데이터의 교환
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main(void) {
    int arr[4] = {3, 2, 4, 1};
    int i;

    BubbleSort(arr, sizeof(arr)/sizeof(int));

    for(i = 0; i < 4; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}