#pragma once
#include <iostream>
using namespace std;

class TString
{
private:
	char* stringData;
public:
	TString();
	TString(char* stringData);
	TString(TString& srt);
	int Lenght();
	int FindSubstring(TString str);
	TString& RemoveSubstring(TString str);
	TString& InsertSubstring(int index, TString str);
	TString& operator+ (TString str);
	friend ostream& operator<<(ostream& os, TString& dt);
	~TString();
};

