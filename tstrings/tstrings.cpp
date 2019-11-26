#include <conio.h>
#include <string.h>
#include <iostream>
#include <Windows.h>
#include "TString.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	char buffer[1024];
	cout << "¬ведите начальную строку:" << endl;
	cin.getline(buffer, 1024);
	TString baseString(buffer);

	cout << "¬ведите строку дл€ поиска:" << endl;
	cin.clear();
	cin.getline(buffer, 1024);
	TString forFind(buffer);
	cout << "»ндекс начала строки:" << baseString.FindSubstring(forFind) << endl;

	cout << "¬ведите строку дл€ вствки по индексу:" << endl;
	cin.clear();
	cin.getline(buffer, 1024);
	TString forInsert(buffer);
	cout << "¬ведите индекс дл€ вставки:";
	int index; 
	cin >> index;
	cout << "»тоговоа€ строка:" << baseString.InsertSubstring(index, forInsert) << endl;

	cout << "¬ведите строку дл€ удалени€:" << endl;
	cin.clear();
	cin.ignore();
	cin.getline(buffer, 1024);
	TString forDelete(buffer);
	cout << "»ндекс начала строки:" << baseString.RemoveSubstring(forDelete) << endl;

	cout << "¬ведите строку дл€ склейки:" << endl;
	cin.clear();
	cin.getline(buffer, 1024);
	TString forAdd(buffer);
	cout << "»ндекс начала строки:" << baseString + forAdd << endl;
}