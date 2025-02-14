#include "Fraction.h"
#include <iostream>

long gcd(long m_numerator, long m_denominator) {
	m_numerator = abs(m_numerator);
	while (m_numerator && m_denominator) {
		if (m_numerator > m_denominator) {
			m_numerator %= m_denominator;
		}
		else {
			m_denominator %= m_numerator;
		}
	}
	return m_numerator + m_denominator;
}

void Fraction::set() {
	if (denominator < 0) {
		denominator = abs(denominator);
		numerator *= -1;
	}
	if (numerator == 0) {
		denominator = 1;
	}
	long m_gcd = gcd(numerator, denominator);
	numerator /= m_gcd;
	denominator /= m_gcd;
}

Fraction::Fraction(long m_numerator, long m_denominator) {
	numerator = m_numerator;
	denominator = m_denominator;
	if (denominator < 0) {
		denominator = abs(denominator);
		numerator *= -1;
	}
	if (numerator == 0) {
		denominator = 1;
	}
	long m_gcd = gcd(numerator, denominator);
	numerator /= m_gcd;
	denominator /= m_gcd;
}

void Fraction::check() {
	if (denominator == 0) {
		throw 1;
	}
}

void Fraction::setNumerator(long m_numerator) {
	numerator = m_numerator;
	set();
}
long Fraction::getNumerator() {
	return numerator;
}

void Fraction::setDenominator(long m_denominator) {
	denominator = m_denominator;
	set();
}
long Fraction::getDenominator() {
	return denominator;
}

double Fraction::getDouble() {
	return (double)numerator / (double)denominator;
}
void Fraction::print() {
	if (denominator != 1) {
		std::cout << numerator << "/" << denominator;
	}
	else
		std::cout << numerator;
}
Fraction Fraction::operator * (Fraction  secondfraction) {
	long long comp_numerator = numerator * secondfraction.getNumerator();
	long long comp_denominator = denominator * secondfraction.getDenominator();
	return Fraction(comp_numerator, comp_denominator);
}
Fraction Fraction::operator + (Fraction  secondfraction) {
	long long addition_num = numerator * secondfraction.getDenominator() + secondfraction.getNumerator() * denominator;
	long long addition_den = denominator * secondfraction.getDenominator();
	return Fraction(addition_num, addition_den);
}
Fraction Fraction::operator - (Fraction  secondfraction) {
	long long difference_num = numerator * secondfraction.getDenominator() - secondfraction.getNumerator() * denominator;
	long long difference_den = denominator * secondfraction.getDenominator();
	return Fraction(difference_num, difference_den);
}
Fraction Fraction::operator / (Fraction  secondfraction) {
	if (secondfraction.getNumerator() != 0) {
		long long divisor_num = numerator * secondfraction.getDenominator();
		long long divisor_den = denominator * secondfraction.getNumerator();
		return Fraction(divisor_num, divisor_den);
	}
}
Fraction Fraction::operator * (long a) {
	long long comp_numerator = numerator * a;
	return Fraction(comp_numerator, denominator);
}
Fraction Fraction::operator + (long a) {
	long long addition_num = numerator + a * denominator;

	return Fraction(addition_num, denominator);
}
Fraction Fraction::operator - (long a) {
	long long difference_num = numerator - a * denominator;
	return Fraction(difference_num, denominator);
}
Fraction Fraction::operator / (long a) {
	if (a != 0) {
		long long divisor_dem = denominator * a;
		return Fraction(numerator, divisor_dem);
	}
}
Fraction Fraction::operator - () {
	long change_num = numerator * (-1);
	return Fraction(change_num, denominator);
}
bool Fraction::operator > (Fraction secondfraction) {
	if ((double)numerator / (double)denominator > secondfraction.getDouble())
		return true;
	return false;
}
bool Fraction::operator < (Fraction secondfraction) {
	if ((double)numerator / (double)denominator < secondfraction.getDouble())
		return true;
	return false;
}
bool Fraction::operator >= (Fraction secondfraction) {
	if ((double)numerator / (double)denominator >= secondfraction.getDouble())
		return true;
	return false;
}
bool Fraction::operator <= (Fraction secondfraction) {
	if ((double)numerator / (double)denominator <= secondfraction.getDouble())
		return true;
	return false;
}
bool Fraction::operator == (Fraction secondfraction) {
	if ((double)numerator / (double)denominator == secondfraction.getDouble())
		return true;
	return false;
}
bool Fraction::operator != (Fraction secondfraction) {
	if ((double)numerator / (double)denominator != secondfraction.getDouble())
		return true;
	return false;
}
bool Fraction::operator > (long a) {
	if ((double)numerator / (double)denominator > a)
		return true;
	return false;
}
bool Fraction::operator < (long a) {
	if ((double)numerator / (double)denominator < a)
		return true;
	return false;
}
bool Fraction::operator >= (long a) {
	if ((double)numerator / (double)denominator >= a)
		return true;
	return false;
}
bool Fraction::operator <= (long a) {
	if ((double)numerator / (double)denominator <= a)
		return true;
	return false;
}
bool Fraction::operator == (long a) {
	if ((double)numerator / (double)denominator == a)
		return true;
	return false;
}
bool Fraction::operator != (long a) {
	if ((double)numerator / (double)denominator != a)
		return true;
	return false;
}