#pragma once
class IntegerList
{
private:
	struct ListNode
	{
		int data;
		int count;
		ListNode* next;
	};

	ListNode* begin, end;
	int count;

public:
	IntegerList();
	void Add(int item);
	~IntegerList();
};

