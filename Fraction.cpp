// Tea Abuselidze
// 11-9-21
// Lab 10

#include "Fraction.h"
#include <iostream>
#include <string>
using namespace std;

// Find the greatest common denominator (GCD)
// For reducing
Fraction::Fraction()
{
	numerator=0;
	denominator=0;
}
int Fraction::getGCD(int num1, int num2)
{
	int remainder = num2 % num1;
	if (remainder != 0)
		return getGCD(remainder, num1);
	return num1;
}

// Reduce/simplify a fraction
void Fraction::reduce()
{
	// Alter this function later to adjust for negative values
	int gcd = getGCD(numerator, denominator);
	numerator /= gcd;
	denominator /= gcd;
}

istream& operator>> (istream& input, Fraction& fract)
{
	char slash;
	input >> fract.numerator;
	input >> slash;
	input >> fract.denominator;
	return input;
}
ostream& operator<< (ostream& output, const Fraction& fract)
{
	output << fract.numerator << '/' << fract.denominator;
	return output;
}

bool operator==(Fraction& rhs, Fraction& lhs)
{
	rhs.reduce();
	lhs.reduce();
	return((rhs.numerator == lhs.numerator) && ( rhs.denominator == lhs.denominator));
}

const Fraction Fraction::operator+(Fraction &rhs) const
{
	Fraction temp;
	temp.numerator=	temp.numerator=((this->numerator*rhs.denominator)+(rhs.numerator*this->denominator));
	temp.denominator=this->denominator*rhs.denominator;
	temp.reduce();
	return temp;

}
const Fraction Fraction::operator-(Fraction&rhs) const
{
	Fraction temp;
	temp.numerator=((this->numerator*rhs.denominator)-(rhs.numerator*this->denominator));
	temp.denominator=this->denominator*rhs.denominator;
	temp.reduce();
	return temp;
}
const Fraction Fraction::operator*(Fraction&rhs) const
{
	Fraction temp;
	temp.numerator=this->numerator*rhs.numerator;
	temp.denominator=this->denominator*rhs.denominator;
	temp.reduce();
	return temp;
}
const Fraction Fraction::operator/(Fraction&rhs) const
{
	Fraction temp;
	temp.numerator=this->numerator/rhs.numerator;
	temp.denominator=this->denominator/rhs.denominator;
	temp.reduce();
	return temp;
}




/* 
General pattern for overloaded operators: 
   1. Declare new object as local variable 
   2. Assign values as needed--in this case, to numerator & denominator
   3. return new object
Note that for most operators, the return type is a const object or const reference to object. 
That's so this: 

A + B = C; 

isn't legal, but 

C = A + B; 

is. 
*/ 
