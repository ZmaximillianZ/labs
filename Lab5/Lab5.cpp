#include <conio.h>
#include <string.h>
#include <iostream>
#include <Windows.h>
#include "Pet.h"
#include "Cat.h"
#include "Dog.h"
#include "Parrot.h"

using namespace std;

Cat* CreateCat()
{
	string name;
	cout << endl << "Имя:";
	getline(cin.ignore(), name);

	double weight;
	cout << "Вес:";
	cin >> weight;

	int lifeSpan;
	cout << "Продолительность жизни:";
	cin >> lifeSpan;

	string breed;
	cout << "Порода:";
	getline(cin.ignore(), breed);

	return new Cat(name, weight, lifeSpan, breed);
}

Dog* CreateDog()
{
	string name;
	cout << endl << "Имя:";
	getline(cin.ignore(), name);

	double weight;
	cout << "Вес:";
	cin >> weight;

	int lifeSpan;
	cout << "Продолительность жизни:";
	cin >> lifeSpan;

	string breed;
	cout << "Порода:";
	getline(cin.ignore(), breed);

	int aggressiveness;
	cout << "Агрессивность (1 - да; 0 - нет):";
	cin >> aggressiveness;

	return new Dog(name, weight, lifeSpan, breed, (bool)aggressiveness);
}

Parrot* CreateParrot()
{
	string name;
	cout << endl << "Имя:";
	getline(cin.ignore(), name);

	double weight;
	cout << "Вес:";
	cin >> weight;

	int lifeSpan;
	cout << "Продолительность жизни:";
	cin >> lifeSpan;

	int wingspan;
	cout << "Размаъ крыльев:";
	cin >> wingspan;

	string family;
	cout << "Семмейтво:";
	getline(cin.ignore(), family);

	return new Parrot(name, weight, lifeSpan, wingspan, family);
}

int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int n;
	cout << "Введите количество животных:" << endl;
	cin >> n;

	Pet** pets = new Pet*[n];
	for (int i = 0; i < n; i++)
	{
		bool correct;
		int type;
		do
		{
			correct = true;
			cout << endl << "Выберите вид животного:" << endl;
			cout << "1 - Кот" << endl;
			cout << "2 - Собака" << endl;
			cout << "3 - Папугай" << endl;
			cin >> type;
			switch (type)
			{
			case 1:
				pets[i] = CreateCat();
				break;
			case 2:
				pets[i] = CreateDog();
				break;
			case 3:
				pets[i] = CreateParrot();
				break;
			default:
				correct = false;
				cout << "Введен неправильный тип животного. попробуйте еще раз." << endl;
				break;
			}

		} while (!correct);
	}



	cout << "Тип" << '\t' << '\t';
	cout << "|Имя" << '\t' << '\t';
	cout << "|Вес" << '\t' << '\t';
	cout << "|Продолжительность жизни" << '\t' << '\t';
	cout << "|Дополнительное описание" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << (*pets[i]) << endl;
	}

	for (int i = 0; i < n; i++)
	{
		delete pets[i];
	}
	delete pets;

	return 0;
}