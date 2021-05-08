#include <iostream>
#include "MinHeap.h"
#include "Array.h"

#define FIRST_CELL 0

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

void kWayMerge(int arr[], int n, int k, Array* allArrays, MinHeap* allMins) {
	MinObject* minObject;

	for (int i = 0; i < n; i++) {
		minObject = (*allMins).extractMin();
		arr[i] = minObject->key;
		(minObject->originArrayCellIndex)++;

		if (minObject->originArrayCellIndex < allArrays[minObject->originArrayNum].getLength()) {
			(*allMins).insertKey(
				allArrays[minObject->originArrayNum].getArray()[minObject->originArrayCellIndex],
				minObject->originArrayNum,
				minObject->originArrayCellIndex
			);
		}
	}
	
}

void kMergeSort(int arr[], int n, int k) {
	int quotient, remainder;
	int arrStartIndex = 0;

	if (n < k) {
		qsort((void*)arr, n, sizeof(int), compareInt);
		return;
	}

	MinHeap allMins(k);
	Array* allArrays = new Array[k];
	quotient = ceil(float(n) / k);
	remainder = n % k;

	for (int i = 0; i < k; i++) {
		kMergeSort(arr + arrStartIndex, quotient, k);
		allArrays[i].init(quotient);
		memcpy(allArrays[i].getArray(), arr + arrStartIndex, quotient * sizeof(int));
		allMins.insertKey(allArrays[i].getArray()[0], i, FIRST_CELL);

		arrStartIndex += quotient;

		remainder--;
		if (remainder == 0) {
			quotient--;
		}
	}

	kWayMerge(arr, n, k, allArrays, &allMins);
	delete[] allArrays;
}

int main()
{
    int arr[] = { 7, 4, 2, 8, 66, -6, 70, 1, 9, 10, 5, 20, 6, 25, 77 ,236 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int k = 10;

	kMergeSort(arr, n, k);
	printArray(arr, n);
}