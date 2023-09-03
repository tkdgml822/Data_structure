#include <stdio.h>

void Swap(int arr[], int idx1, int idx2) {
    int temp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = temp;
}

int Partitition(int arr[], int left, int right) {
    int pivot = arr[left];
    int low = left + 1; 
    int high = right;

    while(low <= high) {
        // 피벗보다 큰 값을 찾는 과정
        while(pivot > arr[low]) {
            low++;
        }

        // 피벗보다 작은 값을 찾는 과정
        while(pivot < arr[high]) {
            high--;
        }

        // 교차되지 않을 상태라면 swap 실행
        if(low <= high) {
            Swap(arr, low, high); 
        }   
    }

    Swap(arr, left, high);
    return high;
}

void QuickSort(int arr[], int left, int right) {
    if(left <= right) {
        int pivot = Partitition(arr, left, right);
        QuickSort(arr, left, pivot-1);
        QuickSort(arr, pivot+1, right);
    }
}

int main(void) {
    int arr[7] = {3, 2, 4, 1, 7, 6, 5};
    // int arr[3] = {3, 3, 3};

    int len = sizeof(arr) / sizeof(int);
    int i;

    QuickSort(arr, 0, sizeof(arr)/sizeof(int) - 1);

    for(i = 0; i < len; i++) { 
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}