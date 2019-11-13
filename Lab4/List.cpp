#include "List.h"
#include <cstddef>
#include <iostream>

using namespace std;

template<typename T>
typename List<T>::ListNode* List<T>::CreateNode(T item)
{
	ListNode* newNode = new ListNode();
	newNode->data = item;
	newNode->next = NULL;
	return newNode;
}

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
	ListNode* newNode = CreateNode(item);

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
	if (this->count < 1) {
		cout << "Пусто";
	}

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

template<typename T>
void List<T>::Insert(int index, T item)
{
	ListNode* newNode = CreateNode(item);

	ListNode* prevNode = NULL;
	ListNode* current = this->begin;
	for (int i = 0; i < index; i++)
	{
		prevNode = current;
		current = current->next;
	}

	if (current == this->begin) {
		newNode->next = this->begin;
		this->begin = newNode;
		if (this->end == NULL) {
			this->end = newNode;
		}
		return;
	}

	newNode->next = current;
	prevNode->next = newNode;

	if (current == NULL) {
		this->end = newNode;
	}

	this->count++;
}

template<typename T>
void List<T>::Remove(int index)
{
	if (this->count < 1) {
		return;
	}

	ListNode* prevNode = NULL;
	ListNode* current = this->begin;
	for (int i = 0; i < index; i++)
	{
		prevNode = current;
		current = current->next;
	}

	this->count--;
	if (current == this->begin)
	{
		if (this->begin == this->end) {
			this->end = NULL;
		}

		this->begin = current->next;
	}
	else if (current == this->end) {
		this->end = prevNode;
		prevNode->next = NULL;
	}
	else
	{
		prevNode->next = current->next;
	}

	delete current;
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
