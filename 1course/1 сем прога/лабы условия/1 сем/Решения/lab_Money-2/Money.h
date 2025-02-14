#pragma once
class Money
{
private:
	int pound;
	int shilling;
	double pence;
	bool positive_amount;
	void transform();
	Money(int, int, double, bool);
public:
	Money();
	Money(int, int, double);

	void setPound(int);
	void setShilling(int);
	void setPence(double);

	int getPound();
	int getShilling();
	double getPence();
	double getPennies();

	void print();

	Money operator + (const Money&) const;
	Money operator - (const Money&) const;
	Money operator += (const Money&);
	Money operator -= (const Money&);
	Money operator - ();

	bool operator > (Money);
	bool operator < (Money);
	bool operator >= (Money);
	bool operator <= (Money);
	bool operator == (Money);
	bool operator != (Money);

};

