#include <conio.h>
#include <string.h>
#include <iostream>
#include <Windows.h>
#include "IntegerSet.h"

using namespace std;

int* inputArray(int n)
{
	int* array = new int[n];
	for (int i = 0; i < n; i++)
	{
		bool isNotUnique = false;
		do {
			cout << "Введите элемент " << i + 1 << ": " << endl;
			cin >> array[i];
			for (int j = 0; j < i; j++)
			{
				// проверяем число на уникальность так как множество не может содержать одинаковых символов
				if (array[j] == array[i]) {
					isNotUnique = true;
					cout << "Число " << array[i] << " уже есть во множестве пожалуйста повторите ввод" << endl;
					break;
				}
			}
		} while (isNotUnique);
	}
	return array;
}

int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n;
	
	cout << "Введите n:" << endl;
	cin >> n;

	cout << endl << endl << "Введите первое множество :" << endl;
	int* array1 = inputArray(n);

	cout << endl << endl << "Введите второе множество :" << endl;
	int* array2 = inputArray(n);

	IntegerSet* set1 = new IntegerSet(array1, n);
	IntegerSet* set2 = new IntegerSet(array2, n);

	delete array1;
	delete array2;

	cout << endl << endl << "Первое множество :" << endl;
	set1->Show();

	cout << endl << endl << "Второе множество множество :" << endl;
	set2->Show();

	cout << endl << endl << "Обьеденние множеста 1 и 2:" << endl;

	IntegerSet interс = set1->Union(*set2);
	interс.Show();


	delete set1;
	delete set2;
}
