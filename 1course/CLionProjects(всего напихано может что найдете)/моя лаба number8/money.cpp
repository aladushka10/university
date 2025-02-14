#include "money.h"

Money::Money() {
    halfPences = 0;
}

Money::Money(int pnd, int sh, double pen)
{
    if (pnd < 0 || sh < 0 || pen < 0 || sh >= 20 || pen >= 12 || pnd >= 1000000000 || int(pen * 2) != pen * 2)
        throw 2;
    halfPences = pnd;
    halfPences *= 480;
    halfPences += sh * 24;
    halfPences += int(2 * pen);
}

Money::Money(long long halfPen)
{
    halfPences = halfPen;
}

long long Money::getHalfPences()
{
    return halfPences;
}

void Money::setHalfPences(long long halfPen)
{
    halfPences = halfPen;
}

void Money::out() {
    long long halfPen = halfPences;
    if (halfPen < 0)
    {
        cout << "-";
        halfPen *= -1;
    }
    if (halfPen == 0)
    {
        cout << "0p.";
    }
    else
    {
        if (halfPen >= 480)
        {
            cout << halfPen / 480 << "pd. ";
            halfPen %= 480;
        }
        if (halfPen >= 24)
        {
            cout << halfPen / 24 << "sh. ";
            halfPen %= 24;
        }
        if (halfPen % 2)
        {
            cout << halfPen / 2 << ",5 p.";
        }
        else
        {
            cout << halfPen / 2 << "p.";
        }
    }
}
Money Money::operator + (Money& money){
    Money answer;
    answer.setHalfPences(halfPences + money.getHalfPences());
    return answer;
}

Money Money::operator - () {
    return Money(-halfPences);
}
Money Money::operator - (Money &money)
{
    Money x = -money;
    return *this + x;
}

Money Money::operator += ( Money& money2) {
    *this = *this + money2;
    return *this;
}
Money Money::operator -= (Money& money2) {
    *this = *this - money2;
    return *this;
}

bool Money::operator != (Money& money)
{
    return (halfPences != money.getHalfPences());
}

bool Money::operator == (Money &money)
{
    return !(*this != money);
}

bool Money::operator > (Money &money)
{
    long long halfPen = halfPences - money.getHalfPences();
    return (halfPen > 0);
}

bool Money::operator >= (Money &money)
{
    return (*this > money || *this == money);
}

bool Money::operator < (Money &money)
{
    return !(*this >= money);
}

bool Money::operator <= (Money &money)
{
    return !(*this > money);
}
