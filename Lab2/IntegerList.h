#pragma once
class IntegerList
{
private:
	struct ListNode
	{
		int data;
		ListNode* next;
	};

	ListNode* begin;
	ListNode* end;
	int count;

public:
	IntegerList();
	void Add(int item);
	int& operator[] (const int index);
	void Show();
	int Size();
	~IntegerList();
};

