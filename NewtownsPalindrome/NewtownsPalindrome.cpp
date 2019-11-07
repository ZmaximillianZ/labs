#include <conio.h>
#include <iostream>
#include <Windows.h>
#include "Palindrome.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int n;
	cout << "������� ������������ ������� �����������:" << endl;
	cin >> n;

	double accuracy;
	cout << "������� ��������:" << endl;
	cin >> accuracy;

	Palindrome* poli = new Palindrome(n, accuracy);

	double tmp;
	for (int i = n; i >= 0; i--)
	{
		cout << "������� ��������� ��� x^" << i << ":";
		cin >> tmp;
		(*poli)[i] = tmp;
	}

	cout << (*poli) << endl;
	cout << "������ ��������� �����������:";
	cin >> tmp;

	cout << "�����:" << poli->Calculate(tmp);

	delete poli;
}