#pragma once
class IntegerSet
{
private:
	int* data;
	int size;
	bool Contins(int* array, int n, int item);
public:
	IntegerSet();
	IntegerSet(const IntegerSet& object);
	IntegerSet(int *data, int n);
	int GetSise();

	bool Include(int item);
	IntegerSet Intersect(const IntegerSet& object);
	IntegerSet Union(const IntegerSet& object);
	IntegerSet Difference(const IntegerSet& object);

	IntegerSet operator-(const IntegerSet& object);
	IntegerSet operator+(const IntegerSet& object);
	IntegerSet operator*(const IntegerSet& object);
	int& operator[] (const int index);

	void Show();
	~IntegerSet();
};

