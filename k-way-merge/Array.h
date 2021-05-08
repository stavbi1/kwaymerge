#pragma once

using namespace std;

class Array
{
private:
	int* arr;
	int length;
public:
	~Array();

	void init(int length);
	int* getArray();
	int getLength();
};

