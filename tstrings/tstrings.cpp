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
	cout << "������� ��������� ������:" << endl;
	cin.getline(buffer, 1024);
	TString baseString(buffer);

	cout << "������� ������ ��� ������:" << endl;
	cin.clear();
	cin.getline(buffer, 1024);
	TString forFind(buffer);
	cout << "������ ������ ������:" << baseString.FindSubstring(forFind) << endl;

	cout << "������� ������ ��� ������ �� �������:" << endl;
	cin.clear();
	cin.getline(buffer, 1024);
	TString forInsert(buffer);
	cout << "������� ������ ��� �������:";
	int index; 
	cin >> index;
	cout << "��������� ������:" << baseString.InsertSubstring(index, forInsert) << endl;

	cout << "������� ������ ��� ��������:" << endl;
	cin.clear();
	cin.ignore();
	cin.getline(buffer, 1024);
	TString forDelete(buffer);
	cout << "������ ������ ������:" << baseString.RemoveSubstring(forDelete) << endl;

	cout << "������� ������ ��� �������:" << endl;
	cin.clear();
	cin.getline(buffer, 1024);
	TString forAdd(buffer);
	cout << "������ ������ ������:" << baseString + forAdd << endl;
}