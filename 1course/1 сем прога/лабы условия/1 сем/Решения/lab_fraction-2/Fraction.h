#include<iostream>
#pragma once

class Fraction {
private:
	long numerator;
	long denominator;
	void set();
public:
	Fraction(long = 1, long = 1);
	void setNumerator(long);
	long getNumerator();
	void setDenominator(long);
	long getDenominator();
	void check();
	Fraction operator * (Fraction);
	Fraction operator + (Fraction);
	Fraction operator - (Fraction);
	Fraction operator / (Fraction);
	Fraction operator * (long);
	Fraction operator + (long);
	Fraction operator - (long);
	Fraction operator / (long);
	Fraction operator - ();
	bool operator > (Fraction);
	bool operator < (Fraction);
	bool operator >= (Fraction);
	bool operator <= (Fraction);
	bool operator == (Fraction);
	bool operator != (Fraction);
	bool operator > (long);
	bool operator < (long);
	bool operator >= (long);
	bool operator <= (long);
	bool operator == (long);
	bool operator != (long);
	void print();
	double getDouble();
};
