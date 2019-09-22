#pragma once
#include "Pet.h"
class Parrot : public Pet
{
protected:
	int wingspan;
	string family;
public:
	Parrot(string name, double weight, int lifeSpan, int wingspan, string family);
	string Type() const;
	string Description() const;
};

