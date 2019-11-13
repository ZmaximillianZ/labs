#pragma once

template<typename T>
class List
{
private:
	struct ListNode
	{
		T data;
		ListNode* next;
	};

	ListNode* begin;
	ListNode* end;
	int count;
	ListNode* CreateNode(T item);
public:
	List();
	List(const List<T>& obj);
	void Add(T item);
	T& operator[] (const int index);
	void Show();
	int Size();
	void Insert(int index, T item);
	void Remove(int index);
	~List();
};