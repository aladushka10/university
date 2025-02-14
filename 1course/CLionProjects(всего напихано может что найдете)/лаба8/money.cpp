#include "money.h"

Money::Money(int pd, int sh, int p, bool hf)
{
    if (pd < 0 || pd >= 1000000000)
        throw 2;
    if (sh < 0 || sh >= 20)
        throw 2;
    if (penny < 0 || penny >= 12 || penny * 2 != int(2 * penny))
        throw 2;
    pounds = pd;
    shillings = sh;
    penny = p;
    half = hf;
}

int Money::getPounds()
{
    return pounds;
}

int Money::getShillings()
{
    return shillings;
}

int Money::getPenny()
{
    return penny;
}

int Money::getSign()
{
    return sign;
}

long long Money::getPenny2()
{
    long long answer = 0;
    answer = pounds;
    answer *= 480;
    answer += shillings * 24;
    answer += penny * 2;
    if (half)
        answer++;
    answer *= sign;
    return answer;
}

bool Money::getHalf()
{
    return half;
}

void Money::setPounds(int pd)
{
    pounds = pd;
}

void Money::setShillings(int sh)
{
    if (sh >= 20)
        throw 4;
    shillings = sh;
}

void Money::setPenny(int p)
{
    if (p >= 12)
        throw 4;
    penny = p;
}

void Money::setSign(int s)
{
    sign = s;
}

void Money::setHalf(bool hf)
{
    half = hf;
}

ostream & operator << (ostream &out, Money &m)
{
    if (m.getSign() == -1)
        out << "-";
    bool zero = true;
    if (m.getPounds() != 0)
    {
        out << m.getPounds() << "pd.";
        zero = false;
    }
    if (m.getShillings() != 0)
    {
        out << m.getShillings() << "sh.";
        zero = false;
    }
    if (m.getPenny() != 0)
    {
        out << m.getPenny();
        if (m.getHalf())
            out << ",5p.";
        else
            out << "p.";
    }
    else
    {
        if (zero)
        {
            out << m.getPenny();
            if (m.getHalf())
                out << ",5p.";
            else
                out << "p.";
        }
        else
        {
            if (m.getHalf())
                out << m.getPenny() << ",5p.";
        }
    }
    out << endl;
    return out;
}

Money Money::operator + (Money& m)
{
    long long Pen1 = getPenny2();
    long long Pen2 = m.getPenny2();
    long long int sum = Pen1 + Pen2;
    Money answer;
    if (sum < 0)
    {
        answer.setSign(-1);
        sum *= -1;
    }
    if (sum % 2)
        answer.setHalf(true);
    sum /= 2;
    answer.setPounds(sum / 240);
    sum %= 240;
    answer.setShillings(sum / 12);
    sum %= 12;
    answer.setPenny(sum);
    if (answer.getPounds() >= 1000000000)
        throw 3;
    return answer;
}

Money Money::operator - (Money &m)
{
    Money temp = m;
    temp.setSign(-m.getSign());
    Money ans = *this + temp;
    return ans;
}

Money Money::operator += (Money &m)
{
    Money temp = *this + m;
    pounds = temp.getPounds();
    shillings = temp.getShillings();
    penny = temp.getPenny();
    sign = temp.getSign();
    half = temp.getHalf();
    return temp;
}

Money Money::operator -= (Money &m)
{
    Money temp = m;
    temp.setSign(-temp.getSign());
    Money ans = *this + temp;
    pounds = ans.getPounds();
    shillings = ans.getShillings();
    penny = ans.getPenny();
    sign = ans.getSign();
    half = ans.getHalf();
    return ans;
}

Money Money::operator - ()
{
    Money temp = *this;
    temp.setSign(-temp.getSign());
    return temp;
}

bool Money::operator != (Money &m)
{
    long long pen1 = getPenny2();
    long long pen2 = m.getPenny2();
    if (pen1 != pen2)
        return true;
    else
        return false;
}

bool Money::operator == (Money &m)
{
    if (*this != m)
        return false;
    else
        return true;
}

bool Money::operator > (Money &m)
{
    Money temp = *this - m;
    long long pen = temp.getPenny2();
    if (pen > 0)
        return true;
    else
        return false;
}

bool Money::operator >= (Money &m)
{
    return (*this > m || *this == m);
}

bool Money::operator < (Money &m)
{
    return !(*this >= m);
}

bool Money::operator <= (Money &m)
{
    return !(*this > m);
}

