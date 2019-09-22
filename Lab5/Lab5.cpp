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
	cout << endl << "���:";
	getline(cin.ignore(), name);

	double weight;
	cout << "���:";
	cin >> weight;

	int lifeSpan;
	cout << "���������������� �����:";
	cin >> lifeSpan;

	string breed;
	cout << "������:";
	getline(cin.ignore(), breed);

	return new Cat(name, weight, lifeSpan, breed);
}

Dog* CreateDog()
{
	string name;
	cout << endl << "���:";
	getline(cin.ignore(), name);

	double weight;
	cout << "���:";
	cin >> weight;

	int lifeSpan;
	cout << "���������������� �����:";
	cin >> lifeSpan;

	string breed;
	cout << "������:";
	getline(cin.ignore(), breed);

	int aggressiveness;
	cout << "������������� (1 - ��; 0 - ���):";
	cin >> aggressiveness;

	return new Dog(name, weight, lifeSpan, breed, (bool)aggressiveness);
}

Parrot* CreateParrot()
{
	string name;
	cout << endl << "���:";
	getline(cin.ignore(), name);

	double weight;
	cout << "���:";
	cin >> weight;

	int lifeSpan;
	cout << "���������������� �����:";
	cin >> lifeSpan;

	int wingspan;
	cout << "������ �������:";
	cin >> wingspan;

	string family;
	cout << "���������:";
	getline(cin.ignore(), family);

	return new Parrot(name, weight, lifeSpan, wingspan, family);
}

int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int n;
	cout << "������� ���������� ��������:" << endl;
	cin >> n;

	Pet** pets = new Pet*[n];
	for (int i = 0; i < n; i++)
	{
		bool correct;
		int type;
		do
		{
			correct = true;
			cout << endl << "�������� ��� ���������:" << endl;
			cout << "1 - ���" << endl;
			cout << "2 - ������" << endl;
			cout << "3 - �������" << endl;
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
				cout << "������ ������������ ��� ���������. ���������� ��� ���." << endl;
				break;
			}

		} while (!correct);
	}



	cout << "���" << '\t' << '\t';
	cout << "|���" << '\t' << '\t';
	cout << "|���" << '\t' << '\t';
	cout << "|����������������� �����" << '\t' << '\t';
	cout << "|�������������� ��������" << endl;
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