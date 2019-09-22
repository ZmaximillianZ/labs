#pragma once
#include <iostream>
#include <string>

using namespace std;

class Pet
{
protected:
	string name;
	double weight;
	int lifeSpan;
public:
	Pet(string name, double weight, int lifeSpan);
	virtual string Type() const = 0;
	virtual string Description() const = 0;
	friend ostream& operator<<(ostream& os, const Pet& dt);
};

