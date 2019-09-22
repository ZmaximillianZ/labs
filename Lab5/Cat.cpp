#include "Cat.h"

Cat::Cat(string name, double weight, int lifeSpan, string breed)
	: Pet(name, weight, lifeSpan)
{
	this->breed = breed;
}

string Cat::Type() const
{
	return "���";
}

string Cat::Description() const
{
	return "������: " + this->breed;
}
