#include <iostream>
#include "MinHeap.h"
#include "Array.h"

using namespace std;

void printArray(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << ", ";
	}

	cout << "\n";
}

int compareInt(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}

void kWayMerge(int arr[], int n, int k) {
	
}

void kMergeSort(int arr[], int n, int k) {
	int quotient, remainder;
	int arrStartIndex = 0;

	if (n < k) {
		qsort((void*)arr, n, sizeof(int), compareInt);
		return;
	}

	MinHeap minHeap(k);
	Array* allArrays = new Array[k];
	quotient = ceil(float(n) / k);
	remainder = n % k;

	for (int i = 0; i < k; i++) {
		kMergeSort(arr + arrStartIndex, quotient, k);
		allArrays[i].init(quotient);
		memcpy(allArrays[i].getArray(), arr + arrStartIndex, quotient * sizeof(int));
		minHeap.insertKey(allArrays[i].getArray()[0]);

		arrStartIndex += quotient;

		remainder--;
		if (remainder == 0) {
			quotient--;
		}
	}

	kWayMerge(arr, n, k, allArrays, minHeap);
	delete[] allArrays;
}

int main()
{
    int arr[] = { 7, 4, 2, 8, 1, 9, 10, 5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int k = 4;

	kMergeSort(arr, n, k);
}