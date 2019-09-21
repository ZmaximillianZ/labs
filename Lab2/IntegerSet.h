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
	IntegerSet Intersect(IntegerSet& object);
	IntegerSet Union(IntegerSet& object);
	IntegerSet Difference(IntegerSet& object);
	void Show();
	~IntegerSet();
};

