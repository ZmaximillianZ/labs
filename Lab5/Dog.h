#pragma once
#include "Pet.h"
class Dog : public Pet
{
protected:
	string breed;
	bool aggressiveness;
public:
	Dog(string name, double weight, int lifeSpan, string breed, bool aggressiveness);
	string Type() const;
	string Description() const;
};

