#include "Palindrome.h"
#include <math.h>

double Palindrome::getValue(double x)
{
	double rez = 0;
	for (int i = 0; i <= this->maxPow; i++)
	{
		rez += this->coeficients[i] * pow(x, i);
	}

	return rez;
}

double Palindrome::getValueForDerivative(double x)
{
	double rez = 0;
	for (int i = 1; i <= this->maxPow; i++)
	{
		rez += this->coeficients[i] * ((double) i) * pow(x, i - 1);
	}

	return rez;
}

Palindrome::Palindrome(int maxPow, double accuracy)
{
	this->accuracy = accuracy;
	this->maxPow = maxPow;
	this->coeficients = new double[maxPow + 1];
	for (int i = 0; i < maxPow; i++)
	{
		this->coeficients[i] = 0;
	}
}

double Palindrome::Calculate(double firstValue)
{
	double x = firstValue;
	double prev;
	do
	{
		prev = x;

		double xN = getValue(prev);
		double xND = getValueForDerivative(prev);

		x = prev - xN / xND;
	} while (abs(x - prev) > this->accuracy);

	return x;
}

double& Palindrome::operator[](const int index)
{
	return this->coeficients[index];
}

Palindrome::~Palindrome()
{
	delete[] this->coeficients;
}

ostream& operator<<(ostream& os, const Palindrome& dt)
{
	for (int i = dt.maxPow; i >= 0; i--)
	{
		os << (dt.coeficients[i]);
		if (i != 0)
		{
			os << "x^" << i << " + ";
		}
	}

	return os;
}
