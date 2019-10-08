#include "IntegerList.h"
#include <cstddef>
#include <iostream>

using namespace std;

IntegerList::ListNode* IntegerList::CreateNode(int item)
{
	ListNode* newNode = new ListNode();
	newNode->data = item;
	newNode->next = NULL;
	return newNode;
}

IntegerList::IntegerList()
{
	this->count = 0;
	this->begin = NULL;
	this->end = NULL;
}

IntegerList::IntegerList(const IntegerList& obj)
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

void IntegerList::Add(int item)
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

int& IntegerList::operator[](const int index)
{
	ListNode* selectedNode = this->begin;
	for (int i = 0; i < index; i++)
	{
		selectedNode = selectedNode->next;
	}
	return selectedNode->data;
}

void IntegerList::Show()
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

int IntegerList::Size()
{
	return this->count;
}

void IntegerList::Insert(int index, int item)
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

void IntegerList::Remove(int index)
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

IntegerList::~IntegerList()
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
