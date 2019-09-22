#include "Dog.h"

Dog::Dog(string name, double weight, int lifeSpan, string breed, bool aggressiveness)
	: Pet(name, weight, lifeSpan)
{
	this->breed = breed;
	this->aggressiveness = aggressiveness;
}

string Dog::Type() const
{
	return "������";
}

string Dog::Description() const
{
	string rez = "������ " + this->breed;
	if (this->aggressiveness) {
		rez = rez + "; ����������";
	}

	return rez;
}
