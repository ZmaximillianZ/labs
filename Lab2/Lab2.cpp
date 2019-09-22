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
	int n1, n2;
	
	cout << "Введите n для первого можества :" << endl;
	cin >> n1;

	cout << endl << endl << "Введите первое множество :" << endl;
	int* array1 = inputArray(n1);

	cout << "Введите n для второго можества :" << endl;
	cin >> n2;

	cout << endl << endl << "Введите второе множество :" << endl;
	int* array2 = inputArray(n2);

	IntegerSet* set1 = new IntegerSet(array1, n1);
	IntegerSet* set2 = new IntegerSet(array2, n2);

	delete array1;
	delete array2;

	cout << endl << endl << "Первое множество :" << endl;
	set1->Show();

	cout << endl << endl << "Второе множество :" << endl;
	set2->Show();

	cout << endl << endl << "Обьеденние множеств :" << endl;

	IntegerSet unionSet = (*set1) + (*set2);
	unionSet.Show();

	cout << endl << endl << "Разница множеств :" << endl;

	IntegerSet differenceSet = (*set1) - (*set2);
	differenceSet.Show();

	cout << endl << endl << "Пересечение множеств :" << endl;

	IntegerSet intersectSet = (*set1) * (*set2);
	intersectSet.Show();


	delete set1;
	delete set2;
}
