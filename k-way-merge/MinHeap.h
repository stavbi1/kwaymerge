#pragma once

#include<iostream>
#include<climits>
#include "MinObject.h"

using namespace std;

// A class for Min Heap
class MinHeap
{
	MinObject** harr; // pointer to array of elements in heap
	int capacity; // maximum possible size of min heap
	int heap_size; // Current number of elements in min heap
public:
	// Constructor
	MinHeap(int capacity);

	~MinHeap();

	// to heapify a subtree with the root at given index
	void MinHeapify(int);

	int parent(int i);

	// to get index of left child of node at index i
	int left(int i);

	// to get index of right child of node at index i
	int right(int i);

	// to extract the root which is the minimum element
	MinObject* extractMin();

	// Returns the minimum key (key at root) from min heap
	MinObject* getMin();

	// Inserts a new key 'k'
	void insertKey(int key, int originArrayNum, int originArrayCellIndex);
};