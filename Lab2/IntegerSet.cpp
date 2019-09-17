#include "IntegerSet.h"
#include <iostream>

using namespace std;


IntegerSet::IntegerSet()
{
	this->size = 0;
	this->data = new int[0];
}

IntegerSet::IntegerSet(const IntegerSet& object)
{
	this->size = object.size;
	this->data = new int[this->size];
	for (int i = 0; i < this->size; i++)
	{
		this->data[i] = object.data[i];
	}
}

IntegerSet::IntegerSet(int* data, int n)
{
	this->size = n;
	this->data = new int[this->size];
	for (int i = 0; i < this->size; i++)
	{
		this->data[i] = data[i];
	}
}

int IntegerSet::GetSise()
{
	return this->size;
}

void IntegerSet::Show()
{
	if (this->size == 0) {
		cout << "Пустое множество";
	}

	for (int i = 0; i < this->size; i++)
	{
		cout << this->data[i];
		if (i + 1 != this->size) {
			cout << ", ";
		}
		else
		{
			cout << endl;
		}
	}
}

IntegerSet::~IntegerSet()
{
	delete this->data;
}
