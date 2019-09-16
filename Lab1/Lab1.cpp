#include <conio.h>
#include <string.h>
#include <iostream>
#include <Windows.h>
#include "IntegerSet.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n;
	
	cout << "Введите n:" << endl;
	cin >> n;
	
	int* array = new int[n];
	for (int i = 0; i < n; i++)
	{
		cout << "Введите элемент " << i + 1 <<  ": " << endl;
		cin >> array[i];
	}

	cout << endl << endl << "Введeнное множество :" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << array[i];
		if (i + 1 != n) {
			cout << ", ";
		}
		else
		{
			cout << endl;
		}
	}

	IntegerSet* set = new IntegerSet();
}
