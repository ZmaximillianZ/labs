#include "List.h"
#include <cstddef>
#include <iostream>

using namespace std;

template<class T>
List<T>::List()
{
	this->count = 0;
	this->begin = NULL;
	this->end = NULL;
}

template<class T>
List<T>::List(const List<T>& obj)
{
	this->count = 0;
	this->begin = NULL;
	this->end = NULL;
	ListNode* selectedNode = obj.begin;
	while (selectedNode != NULL)
	{
		this->Add(selectedNode->data);
		selectedNode = selectedNode->next;
	}
}

template<class T>
void List<T>::Add(T item)
{
	ListNode* newNode = new ListNode();
	newNode->data = item;
	newNode->next = NULL;

	if (this->begin == NULL && this->end == NULL) {
		this->begin = newNode;
		this->end = newNode;
	}
	else
	{
		this->end->next = newNode;
		this->end = newNode;
	}

	this->count++;
}

template<class T>
T& List<T>::operator[](const int index)
{
	ListNode* selectedNode = this->begin;
	for (int i = 0; i < index; i++)
	{
		selectedNode = selectedNode->next;
	}
	return selectedNode->data;
}

template<class T>
void List<T>::Show()
{
	ListNode* selectedNode = this->begin;
	while (selectedNode != NULL)
	{
		cout << selectedNode->data;
		if (selectedNode->next != NULL) {
			cout << ", ";
		}
		selectedNode = selectedNode->next;
	}
}

template<class T>
int List<T>::Size()
{
	return this->count;
}

template<class T>
List<T>::~List()
{
	ListNode* selectedNode = this->begin;
	ListNode* tmp;
	while (selectedNode != NULL)
	{
		tmp = selectedNode;
		selectedNode = selectedNode->next;
		delete tmp;
	}
}
