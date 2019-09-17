#pragma once
class IntegerSet
{
private:
	int* data;
	int size;
public:
	IntegerSet();
	IntegerSet(const IntegerSet& object);
	IntegerSet(int *data, int n);
	int GetSise();
	void Show();
	~IntegerSet();
};

