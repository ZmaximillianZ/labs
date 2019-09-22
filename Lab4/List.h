#pragma once

template<typename T>
class List
{
	struct ListNode
	{
		T data;
		ListNode* next;
	};

	ListNode* begin;
	ListNode* end;
	int count;

public:
	List();
	List(const List<T>& obj);
	void Add(T item);
	T& operator[] (const int index);
	void Show();
	int Size();
	~List();
};