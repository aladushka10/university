#include <iostream>
#include "Fraction.h"
void print_operations(Fraction firstfraction, Fraction secondfraction, Fraction operation, char sign) {
	firstfraction.print();
	std::cout << " " << sign << " ";
	secondfraction.print();
	std::cout << " = ";
	operation.print();
	std::cout << std::endl;
}
void print_comparisons(Fraction firstfraction, Fraction secondfraction, bool comparison, char sign, char sign2) {
	firstfraction.print();
	std::cout << " " << sign << sign2 << " ";
	secondfraction.print();
	if (comparison) {
		std::cout << " -- " << "true\n";
	}
	else {
		std::cout << " -- " << "false\n";
	}
}
void test_operations(Fraction firstfraction, Fraction secondfraction) {
	Fraction composition = firstfraction * secondfraction;
	print_operations(firstfraction, secondfraction, composition, '*');
	Fraction addition = firstfraction + secondfraction;
	print_operations(firstfraction, secondfraction, addition, '+');
	Fraction difference = firstfraction - secondfraction;
	print_operations(firstfraction, secondfraction, difference, '-');
	Fraction divisor = firstfraction / secondfraction;
	if (secondfraction.getNumerator() != 0) {
		print_operations(firstfraction, secondfraction, divisor, '/');
	}
	else std::cout << "Error\n";
	bool comp = firstfraction > secondfraction;
	print_comparisons(firstfraction, secondfraction, comp, '>', ' ');
	bool comp2 = firstfraction < secondfraction;
	print_comparisons(firstfraction, secondfraction, comp2, '<', ' ');
	bool comp3 = firstfraction >= secondfraction;
	print_comparisons(firstfraction, secondfraction, comp3, '>', '=');
	bool comp4 = firstfraction <= secondfraction;
	print_comparisons(firstfraction, secondfraction, comp4, '<', '=');
	bool comp5 = firstfraction == secondfraction;
	print_comparisons(firstfraction, secondfraction, comp5, '=', '=');
	bool comp6 = firstfraction != secondfraction;
	print_comparisons(firstfraction, secondfraction, comp6, '!', '=');
}
void print_operations(Fraction firstfraction, long a, Fraction operation, char sign) {
	firstfraction.print();
	std::cout << " " << sign << " " << a << " = ";
	operation.print();
	std::cout << std::endl;
}
void print_comparisons(Fraction firstfraction, long a, bool comparison, char sign, char sign2) {
	firstfraction.print();
	std::cout << " " << sign << sign2 << " " << a;
	if (comparison) {
		std::cout << " -- " << "true\n";
	}
	else {
		std::cout << " -- " << "false\n";
	}
}
void test_operations_long(Fraction firstfraction, long a) {
	Fraction composition = firstfraction * a;
	print_operations(firstfraction, a, composition, '*');
	Fraction addition = firstfraction + a;
	print_operations(firstfraction, a, addition, '+');
	Fraction difference = firstfraction - a;
	print_operations(firstfraction, a, difference, '-');
	Fraction divisor = firstfraction / a;
	if (a != 0) {
		print_operations(firstfraction, a, divisor, '/');
	}
	else std::cout << "Error\n";
	bool comp = firstfraction > a;
	print_comparisons(firstfraction, a, comp, '>', ' ');
	bool comp2 = firstfraction < a;
	print_comparisons(firstfraction, a, comp2, '<', ' ');
	bool comp3 = firstfraction >= a;
	print_comparisons(firstfraction, a, comp3, '>', '=');
	bool comp4 = firstfraction <= a;
	print_comparisons(firstfraction, a, comp4, '<', '=');
	bool comp5 = firstfraction == a;
	print_comparisons(firstfraction, a, comp5, '=', '=');
	bool comp6 = firstfraction != a;
	print_comparisons(firstfraction, a, comp6, '!', '=');
}
void test_getDouble(Fraction firstfraction, Fraction secondfraction) {
	std::cout << "firstfraction.getDouble() = " << firstfraction.getDouble() << std::endl;
	std::cout << "secondfraction.getDouble() = " << secondfraction.getDouble() << std::endl;
}
void change_the_sign(Fraction firstfraction) {
	Fraction change_sign = -firstfraction;
	firstfraction.print();
	std::cout << " = ";
	change_sign.print();
	std::cout << std::endl;
}
int main() {
	setlocale(LC_ALL, "ru");
	Fraction firstfraction(-100, 2);
	/*	Fraction firstfraction;
		firstfraction.setNumerator(0);
		firstfraction.setDenominator(-2);
		std::cout << "firstfraction.getDenominator() = " << firstfraction.getDenominator() << std::endl;
	*/
	try {
		firstfraction.check();
	}
	catch (...) {
		std::cout << "Error";
		return 1;
	}

	Fraction secondfraction(11,-10);

	try {
		secondfraction.check();
	}
	catch (...) {
		std::cout << "Error";
		return 1;
	}
	test_operations(firstfraction, secondfraction);
	test_operations_long(firstfraction, -10);
	test_getDouble(firstfraction, secondfraction);
	change_the_sign(firstfraction);
	return 0;
}
