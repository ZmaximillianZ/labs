#pragma once
#include <iostream>

using namespace std;
class Palindrome
{
private:
	int maxPow;
	double accuracy;
	double* coeficients;
	double getValue(double x);
	double getValueForDerivative(double x);
public:
	Palindrome(int maxPow, double accuracy);
	double Calculate(double firstValue);
	friend ostream& operator<<(ostream& os, const Palindrome& dt);
	double& operator[] (const int index);
	~Palindrome();
};
