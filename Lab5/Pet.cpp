#include "Pet.h"

ostream& operator<<(ostream& os, const Pet& pet)
{
	os << pet.Type() << '\t' << '\t';
	os << pet.name << '\t' << '\t';
	os << pet.weight << '\t' << '\t';
	os << pet.lifeSpan << '\t' << '\t';
	os << pet.Description();
	return os;
}

Pet::Pet(string name, double weight, int lifeSpan)
{
	this->name = name;
	this->weight = weight;
	this->lifeSpan = lifeSpan;
}