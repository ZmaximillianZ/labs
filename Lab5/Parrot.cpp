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
	return "Попугай";
}

string Parrot::Description() const
{
	return "Размаъ крыльев: " + to_string(this->wingspan) + "; Семмейтво: " + this->family;
}
