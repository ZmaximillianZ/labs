#pragma once
#include "Pet.h"
class Cat : public Pet
{
protected:
	string breed;
public:
	Cat(string name, double weight, int lifeSpan, string breed);
	string Type() const;
	string Description() const;
};

