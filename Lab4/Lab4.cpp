#include <conio.h>
#include <string.h>
#include <iostream>
#include <Windows.h>
// это хак линковки шаблонного класса поэтому включаем .cpp
// https://www.codeproject.com/Articles/48575/How-to-define-a-template-class-in-a-h-file-and-imp
#include "List.cpp"

using namespace std;

template<class T>
bool compareLists(List<T> list1, List<T> list2) {
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

	List<char> list1;
	cout << "Введите элемент список 1" << endl;
	char item;
	for (int i = 0; i < n; i++)
	{
		cout << "Введите элемент " << i + 1 << ": " << endl;
		cin >> item;
		list1.Add(item);
	}

	List<char> list2;
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

	if (compareLists(list1, list2))
	{
		cout << endl << "Списки эквивалентны!" << endl;
	}
	else
	{
		cout << endl << "Списки не эквивалентны!" << endl;
	}

	return 0;
}