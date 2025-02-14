#include "Money.h" 
#include <iostream>
#include <cmath>
void Money::transform() {
	if ((getPennies()) >= 0) {
		while (pence >= 12) {
			++shilling;
			pence -= 12;
		}
		while (pence < 0) {
			--shilling;
			pence += 12;
		}
		while (shilling >= 20) {
			++pound;
			shilling -= 20;
		}
		while (shilling < 0) {
			--pound;
			shilling += 20;
		}
	}
	else {
		while (pence > 0) { // (-3,-4,-6)
			++shilling;
			pence -= 12;
		}
		while (pence <= -12) {
			--shilling;
			pence += 12;
		}
		while (shilling > 0) {
			++pound;
			shilling -= 20;
		}
		while (shilling <= -20) {
			--pound;
			shilling += 20;
		}
	}
	if (pound < 0 || shilling < 0 || pence < 0) {
		pound = std::abs(pound);
		shilling = std::abs(shilling);
		pence = std::abs(pence);
		positive_amount = false;
	}
	else {
		positive_amount = true;
	}
}
Money::Money() {
	pound = 0;
	shilling = 0;
	pence = 0;
	positive_amount = true;
}
Money::Money(int m_pound, int m_shilling, double m_pence) {
	pound = m_pound;
	shilling = m_shilling;
	pence = m_pence;
	const int max_pound = 1000000000;
	if (pound >= max_pound || pound < 0) {
		throw std::logic_error("Wrong amount of pounds");
	}
	if (shilling >= 20 || shilling < 0) {
		throw std::logic_error("wrong amount of shillings");
	}
	if (pence >= 12 || pence < 0) {
		throw std::logic_error("wrong amount of pences");
	}
	double int_pence;
	if (modf(pence, &int_pence) != 0.5 && modf(pence, &int_pence) != 0) {
		throw std::logic_error("wrong amount of pences");
	}
}
Money::Money(int m_pound, int m_shilling, double m_pence, bool m_positive_amount) {
	pound = m_pound;
	shilling = m_shilling;
	pence = m_pence;
	positive_amount = m_positive_amount;
}
void Money::setPound(int m_pound) {
	pound = m_pound;
}
void Money::setShilling(int m_shilling) {
	shilling = m_shilling;
}
void Money::setPence(double m_pence) {
	pence = m_pence;
}
int Money::getPound() {
	if (positive_amount == false)
		return -pound;
	return pound;

}
double Money::getPence() {
	if (positive_amount == false)
		return -pence;
	return pence;
}
int Money::getShilling() {
	if (positive_amount == false)
		return -shilling;
	return shilling;
}
double Money::getPennies() {
	if (positive_amount) {
		return pence + shilling * 12 + pound * 240;
	}
	else {
		return -pence - shilling * 12 - pound * 240;
	}
}
void Money::print() {
	if (positive_amount == false) {
		std::cout << "-";
	}
	if (pound != 0) {
		std::cout << pound << "p. ";
	}
	if (shilling != 0) {
		std::cout << shilling << "sh. ";
	}
	if (pence != 0) {
		std::cout << pence << "p. ";
	}
	if (pound == 0 && shilling == 0 && pence == 0) {
			std::cout << "0p.";
	}
}
Money Money::operator + (const Money& secondMoney) const {
	int addPound = pound, secPound = secondMoney.pound, addShilling = shilling, secShilling = secondMoney.shilling;
	double addPence = pence, secPence = secondMoney.pence;
	if (positive_amount == false) {
		addPound = -pound;
		addShilling = -shilling;
		addPence = -pence;
	}
	if (secondMoney.positive_amount == false) {
		secPound = -secondMoney.pound;
		secShilling = -secondMoney.shilling;
		secPence = -secondMoney.pence;
	}
	Money additionMoney(addPound + secPound, addShilling + secShilling, addPence + secPence, true);
	additionMoney.transform();
	return additionMoney;
}
Money Money::operator - (const Money& secondMoney) const {
	int diffPound = pound, secPound = secondMoney.pound, diffShilling = shilling, secShilling = secondMoney.shilling;
	double diffPence = pence, secPence = secondMoney.pence;
	if (positive_amount == false) {
		diffPound = -pound;
		diffShilling = -shilling;
		diffPence = -pence;
	}
	if (secondMoney.positive_amount == false) {
		secPound = -secondMoney.pound;
		secShilling = -secondMoney.shilling;
		secPence = -secondMoney.pence;
	}
	Money diffMoney(diffPound - secPound, diffShilling - secShilling, diffPence - secPence, true);
	diffMoney.transform();
	return diffMoney;
}
Money Money::operator += (const Money& secondMoney) {
	*this = *this + secondMoney;
	return *this;
}
Money Money::operator -= (const Money& secondMoney) {
	*this = *this - secondMoney;
	return *this;
}
Money Money::operator - () {
	return Money(pound, shilling, pence, !positive_amount);
}
bool Money::operator > (Money secondMoney) {
	return this->getPennies() > secondMoney.getPennies();
}
bool Money::operator < (Money secondMoney) {
	return this->getPennies() < secondMoney.getPennies();
}
bool Money::operator >= (Money secondMoney) {
	return this->getPennies() >= secondMoney.getPennies();
}
bool Money::operator <= (Money secondMoney) {
	return this->getPennies() <= secondMoney.getPennies();
}
bool Money::operator == (Money secondMoney) {
	return this->getPennies() == secondMoney.getPennies();
}
bool Money::operator != (Money secondMoney) {
	return this->getPennies() != secondMoney.getPennies();
}

