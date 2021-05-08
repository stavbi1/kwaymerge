#include "MinHeap.h"

using namespace std;

// A utility function to swap two elements
void swap(MinObject** x, MinObject** y)
{
	MinObject* temp = *x;
	*x = *y;
	*y = temp;
}

// Constructor: Builds a heap from a given array a[] of given size
MinHeap::MinHeap(int cap)
{
	heap_size = 0;
	capacity = cap;
	harr = new MinObject*[cap];
}

MinHeap::~MinHeap()
{
	/*for (int i = 0; i < capacity; i++) {
		delete harr[i];
	}

	delete[] harr;*/
}

// Inserts a new key 'k'
void MinHeap::insertKey(int key, int originArrayNum, int originArrayCellIndex)
{
	if (heap_size == capacity)
	{
		cout << "\nOverflow: Could not insertKey\n";
		return;
	}

	// First insert the new key at the end
	heap_size++;
	int i = heap_size - 1;
	harr[i] = new MinObject();
	harr[i]->key = key;
	harr[i]->originArrayNum = originArrayNum;
	harr[i]->originArrayCellIndex = originArrayCellIndex;

	// Fix the min heap property if it is violated
	while (i != 0 && harr[parent(i)]->key > harr[i]->key)
	{
		swap(&(harr[i]), &(harr[parent(i)]));
		i = parent(i);
	}
}

// Method to remove minimum element (or root) from min heap
MinObject* MinHeap::extractMin()
{
	if (heap_size <= 0)
		return NULL;
	if (heap_size == 1)
	{
		heap_size--;
		return harr[0];
	}

	// Store the minimum value, and remove it from heap
	MinObject* root = harr[0];
	harr[0] = harr[heap_size - 1];
	heap_size--;
	MinHeapify(0);

	return root;
}


MinObject* MinHeap::getMin() { return harr[0]; }

// A recursive method to heapify a subtree with the root at given index
// This method assumes that the subtrees are already heapified
void MinHeap::MinHeapify(int i)
{
	int l = left(i);
	int r = right(i);
	int smallest = i;
	if (l < heap_size && harr[l]->key < harr[i]->key)
		smallest = l;
	if (r < heap_size && harr[r]->key < harr[smallest]->key)
		smallest = r;
	if (smallest != i)
	{
		swap(&(harr[i]), &(harr[smallest]));
		MinHeapify(smallest);
	}
}

int MinHeap::parent(int i) { return (i - 1) / 2; }

// to get index of left child of node at index i
int MinHeap::left(int i) { return (2 * i + 1); }

// to get index of right child of node at index i
int MinHeap::right(int i) { return (2 * i + 2); }