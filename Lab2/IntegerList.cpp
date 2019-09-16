#include "IntegerList.h"
#include <cstddef>
#include <iostream>

using namespace std;

IntegerList::IntegerList()
{
	this->count = 0;
	this->begin = NULL;
	this->end = NULL;
}

void IntegerList::Add(int item)
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
