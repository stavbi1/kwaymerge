#include "Array.h"


void Array::init(int length) {
	arr = new int[length];
	this->length = length;
}

Array::~Array() {
	delete[] arr;
};

int* Array::getArray() {
	return arr;
};

int Array::getLength() {
	return length;
}