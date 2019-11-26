#include "TString.h"
#include <iostream>
#include <cstring>

TString::TString()
{
	this->stringData = NULL;
}

// на вход принимаетьс€ cstring и преобразовываетьс€в tstring
TString::TString(char* stringData)
{
	int size = strlen(stringData);
	this->stringData = new char[size + 1];
	this->stringData[0] = (char)size;
	memcpy(this->stringData+1, stringData, size);
}

TString::TString(TString& srt)
{
	this->stringData = new char[srt.Lenght() + 1];
	memcpy(this->stringData, srt.stringData, srt.Lenght() + 1);
}

int TString::Lenght()
{
	if (this->stringData != NULL) {
		return (int)this->stringData[0];
	}
	return 0;
}

int TString::FindSubstring(TString str)
{
	char* s = this->stringData + 1;
	char* c = str.stringData + 1;
	int i, j, n = 1;
	int lenC = str.Lenght(), lenS = this->Lenght();

	for (i = 0; i <= lenS - lenC; i++)
	{
		for (j = 0; s[i + j] == c[j]; j++);
		if (j == lenC || i == lenS - lenC) {
			return i;
		}
	}

	return -1;
}

TString& TString::RemoveSubstring(TString str)
{
	int start = this->FindSubstring(str);
	if (start < 0) {
		return *this;
	}

	if (str.Lenght() < this->Lenght()) {
		TString* rez = new TString();
		rez->stringData = new char[this->Lenght() - str.Lenght() + 1];
		rez->stringData[0] = this->Lenght() - str.Lenght();
		memcpy(rez->stringData + 1, this->stringData + 1, start);
		int part2 = this->Lenght() - start - str.Lenght();
		memcpy(rez->stringData + 1 + start, this->stringData + start + 1 + str.Lenght(), part2);
		return *rez;
	}

	return *(new TString());
}

TString& TString::InsertSubstring(int index, TString str)
{
	TString* rezStr = new TString();
	rezStr->stringData = new char[this->Lenght() + str.Lenght() + 1];
	rezStr->stringData[0] = this->Lenght() + str.Lenght();
	memcpy(rezStr->stringData + 1, this->stringData + 1, index);
	memcpy(rezStr->stringData + 1 + index, str.stringData + 1, str.Lenght());
	memcpy(rezStr->stringData + 1 + index + str.Lenght(), this->stringData + 1 + index, this->Lenght() - index);
	return *rezStr;
}

TString& TString::operator+(TString str)
{
	TString* rezStr = new TString();
	rezStr->stringData = new char[this->Lenght() + str.Lenght() + 1];
	rezStr->stringData[0] = this->Lenght() + str.Lenght();
	memcpy(rezStr->stringData + 1, this->stringData + 1, this->Lenght());
	memcpy(rezStr->stringData + 1 + this->Lenght(), str.stringData + 1, str.Lenght());
	return *rezStr;
}

TString::~TString()
{
	if (this->stringData != NULL) {
		delete[] this->stringData;
	}
}

ostream& operator<<(ostream& os, TString& dt)
{
	if (dt.stringData != NULL) {
		for (int i = 1; i < dt.Lenght() + 1; i++)
		{
			os << dt.stringData[i];
		}
	}
	return os;
}
