#include "Set.h"
#include <iterator>
#include <iostream>

Set::Set(int size)
{
	this->size = 0;
	this->data = new int[size];
}

Set::Set(const Set& obj)
{
	this->size = obj.size;
	int size = sizeof(obj.data) / sizeof(int);
	this->data = new int[size];
	for (int i = 0; i < size; i++)
	{
		this->data[i] = obj.data[i];
	}
}

void Set::Add(int item)
{

}

bool Set::Include(int item)
{
	return false;
}

Set::~Set()
{
	delete this->data;
}