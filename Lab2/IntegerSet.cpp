#include "IntegerSet.h"
#include <iostream>

using namespace std;


bool IntegerSet::Contins(int* array, int n, int item)
{
	for (int i = 0; i < n; i++)
	{
		if (array[i] == item)
		{
			return true;
		}
	}
	return false;
}

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

// проверка на вхождение елемента
bool IntegerSet::Include(int item)
{
	return Contins(this->data, this->size, item);
}

// пересечние
IntegerSet IntegerSet::Intersect(IntegerSet& object)
{
	return IntegerSet();
}

// Обедениение
IntegerSet IntegerSet::Union(IntegerSet& object)
{
	// вычисляям количество уникальных символов что бы выделить
	// память для нового массива
	int count = this->size;
	for (int i = 0; i < object.size; i++)
	{
		if (!Contins(this->data, this->size, object.data[i])) {
			count++;
		}
	}

	IntegerSet rez;
	rez.data = new int[count];
	rez.size = count;

	// копируем массив полность
	int i = 0;
	for (; i < this->size; i++)
	{
		rez.data[i] = this->data[i];
	}

	for (int j = 0; j < object.size; j++)
	{
		if (!Contins(this->data, this->size, object.data[j])) {
			rez.data[i] = object.data[j];
			i++;
		}
	}

	return rez;
}

// Разница
IntegerSet IntegerSet::Difference(IntegerSet& object)
{
	return IntegerSet();
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
