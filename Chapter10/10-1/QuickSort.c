#include <stdio.h>

void Swap(int arr[], int idx1, int idx2)
{
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}

int middleData(int arr[], int left, int right) {
	// 3개의 데이터
	int threeData[3] = {left, ((left + right) / 2), right};

	if(arr[threeData[0]] > arr[threeData[1]]) {
		Swap(arr, 0, 1);
	}

	if(arr[threeData[0]] > arr[threeData[2]]) {
		Swap(arr, 1, 2);
	}

	if(arr[threeData[0]] > arr[threeData[1]]) {
		Swap(arr, 0, 1);
	}

	return threeData[1];
}

int Partition(int arr[], int left, int right) {
	int pIdx = middleData(arr, left, right);
	int pivot = arr[pIdx];

	int low = left+1;
	int high = right;

	Swap(arr, left, pIdx);

	printf("피벗 : %d\n", pivot);

	while(low <= high) {	
		// while(pivot > arr[low])
		// 	low++;

		// while(pivot < arr[high])
		// 	high--;

		while(pivot >= arr[low] && low <= right) {
			low++;
		}

		while(pivot <= arr[high] && high >= (left+1)) {
			high--;
		}

		if(low <= high) {
			Swap(arr, low, high);    
		}
	}

	Swap(arr, left, high);    
	return high;
}

void QuickSort(int arr[], int left, int right) {
	if(left <= right) {
		int pivot = Partition(arr, left, right);   
		QuickSort(arr, left, pivot-1);    
		QuickSort(arr, pivot+1, right); 
	}
}

int main(void) {
	int arr[7] = {3, 2, 4, 1, 7, 6, 5};
	// int arr[3] = {3, 3, 3};

	int len = sizeof(arr) / sizeof(int);
	int i;

	QuickSort(arr, 0, sizeof(arr)/sizeof(int)-1);

	for(i=0; i<len; i++) {
		printf("%d ", arr[i]);
	}

	printf("\n");
	return 0;
}