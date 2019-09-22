#include "Parrot.h"
#include <iostream>
using namespace std;

Parrot::Parrot(string name, double weight, int lifeSpan, int wingspan, string family)
	: Pet(name, weight, lifeSpan)
{
	this->wingspan = wingspan;
	this->family = family;
}

string Parrot::Type() const
{
	return "�������";
}

string Parrot::Description() const
{
	return "������ �������: " + to_string(this->wingspan) + "; ���������: " + this->family;
}
