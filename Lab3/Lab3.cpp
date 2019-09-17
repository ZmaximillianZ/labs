#include <conio.h>
#include <string.h>
#include <iostream>
#include <Windows.h>
#include "IntegerList.h"

using namespace std;

bool compareLists(IntegerList list1, IntegerList list2) {
	int n = list1.Size();

	int i = 0;
	for (; i < n; i++)
	{
		if (list1[i] != list2[i]) {
			break;
		}
	}

	return i == n;
}

int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n;

	cout << "Введите n:" << endl;
	cin >> n;

	IntegerList list1;
	cout << "Введите элемент список 1" << endl;
	int item;
	for (int i = 0; i < n; i++)
	{
		cout << "Введите элемент " << i + 1 << ": " << endl;
		cin >> item;
		list1.Add(item);
	}

	IntegerList list2;
	cout << "Введите элемент список 2" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "Введите элемент " << i + 1 << ": " << endl;
		cin >> item;
		list2.Add(item);
	}

	cout << endl << "Список 1:" << endl;
	list1.Show();

	cout << endl << "Список 2:" << endl;
	list2.Show();

	if (compareLists(list1, list2)) {
		cout << endl << "Списки эквивалентны!" << endl;
	}
	else
	{
		cout << endl << "Списки не эквивалентны!" << endl;
	}

	return 0;
}

