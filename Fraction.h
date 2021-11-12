#pragma once
// Tea Abuselidze 
// 11-10-21
// Lab 9

#include <iostream>
using namespace std;

class Fraction
{
	friend ostream& operator<< (ostream& output, const Fraction& fract);
	friend istream& operator>> (istream& input, Fraction& fract);
	friend bool operator==(Fraction& rhs, Fraction&lhs);
	// Add the variables and functions you need to. getGCD and reduce are 
	// provided for you.

public:
	void reduce();
	Fraction();
	const Fraction operator+(Fraction& rhs) const;
	const Fraction operator-(Fraction&rhs) const;
	const Fraction operator*(Fraction&rhs) const;
	const Fraction operator/(Fraction&rhs) const;
private:
	int getGCD(int num1, int num2);
	int numerator;
	int denominator;





};

