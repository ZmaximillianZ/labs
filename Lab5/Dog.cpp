#include "Dog.h"

Dog::Dog(string name, double weight, int lifeSpan, string breed, bool aggressiveness)
	: Pet(name, weight, lifeSpan)
{
	this->breed = breed;
	this->aggressiveness = aggressiveness;
}

string Dog::Type() const
{
	return "Собака";
}

string Dog::Description() const
{
	string rez = "Порода " + this->breed;
	if (this->aggressiveness) {
		rez = rez + "; Агресиивна";
	}

	return rez;
}
