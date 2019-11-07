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
	cout << "¬ведите максимальную степерь паплиндрома:" << endl;
	cin >> n;

	double accuracy;
	cout << "¬ведите точность:" << endl;
	cin >> accuracy;

	Palindrome* poli = new Palindrome(n, accuracy);

	double tmp;
	for (int i = n; i >= 0; i--)
	{
		cout << "¬ведите кофициент при x^" << i << ":";
		cin >> tmp;
		(*poli)[i] = tmp;
	}

	cout << (*poli) << endl;
	cout << "¬веите начальное приблежение:";
	cin >> tmp;

	cout << "ќтвет:" << poli->Calculate(tmp);

	delete poli;
}