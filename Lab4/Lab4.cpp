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

void UsingChar()
{
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
}


void UsingInt()
{
	int n;

	cout << "Введите n:" << endl;
	cin >> n;

	List<int> list1;
	cout << "Введите элемент список 1" << endl;
	int item;
	for (int i = 0; i < n; i++)
	{
		cout << "Введите элемент " << i + 1 << ": " << endl;
		cin >> item;
		list1.Add(item);
	}

	List<int> list2;
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
}


void UsingDouble()
{
	int n;

	cout << "Введите n:" << endl;
	cin >> n;

	List<double> list1;
	cout << "Введите элемент список 1" << endl;
	double item;
	for (int i = 0; i < n; i++)
	{
		cout << "Введите элемент " << i + 1 << ": " << endl;
		cin >> item;
		list1.Add(item);
	}

	List<double> list2;
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
}

int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "Выберите тип данных:" << endl;
	cout << "1 - int" << endl;
	cout << "2 - char" << endl;
	cout << "3 - double" << endl;
	int type = 0;
	cin >> type;
	switch (type)
	{
	case 1:
		UsingInt();
		break;
	case 2:
		UsingChar();
		break;
	case 3:
		UsingDouble();
		break;
	}

	return 0;
}