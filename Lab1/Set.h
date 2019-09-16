#pragma once

class Set
{
private:
	int* data;
	int size;

public:
	Set(int size);
	Set(const Set& obj);
	void Add(int item);
	bool Include(int item);
	~Set();
};
