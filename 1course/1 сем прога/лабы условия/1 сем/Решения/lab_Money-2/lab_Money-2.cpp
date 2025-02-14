#include <iostream>
#include "Money.h"

int main() {
	Money firstMoney(4, 9, 4.5), secondMoney(2, 0, 0);
	firstMoney = -firstMoney;
	secondMoney = secondMoney;
	Money add;
	std::cout << "a = ";
	firstMoney.print();
	std::cout << std::endl;
	std::cout << "b = ";
	secondMoney.print();
	std::cout << std::endl;
	add = firstMoney + secondMoney;
	std::cout << "a + b = ";
	add.print();
	std::cout << std::endl;
	add = firstMoney - secondMoney;
	std::cout << "a - b = ";
	add.print();
	std::cout << std::endl;
	add += secondMoney;
	std::cout << "(a - b) += b.           a = ";
	add.print();
	std::cout << std::endl;
	add -= secondMoney;
	std::cout << "a -= b.                 a - b = ";
	add.print();
	std::cout << std::endl;
	add = -add;
	std::cout << "(a - b) = -(a - b).    -(a - b) = ";
	add.print();
	std::cout << std::endl;
	std::cout << "a > b -- " << (firstMoney > secondMoney) << std::endl;
	std::cout << "a < b -- " << (firstMoney < secondMoney) << std::endl;
	std::cout << "a >= b -- " << (firstMoney >= secondMoney) << std::endl;
	std::cout << "a <= b -- " << (firstMoney <= secondMoney) << std::endl;
	std::cout << "a == b -- " << (firstMoney == secondMoney) << std::endl;
	std::cout << "a != b -- " << (firstMoney != secondMoney) << std::endl;
	add += secondMoney;
	std::cout << (firstMoney > secondMoney);
	return 0;
}
