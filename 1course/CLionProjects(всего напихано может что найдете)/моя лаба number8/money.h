#ifndef __NUMBER8_MONEY_H
#define __NUMBER8_MONEY_H
#endif //__NUMBER8_MONEY_H
#include <iostream>
using namespace std;
class Money
{
private:
    long long halfPences;
public:
    Money();
    Money(int, int, double);
    Money(long long);
    long long getHalfPences();
    void setHalfPences(long long);
    void out();
    Money operator + (Money&);
    Money operator - (Money&);
    Money operator - ();
    Money operator += (Money&);
    Money operator -= (Money&);
    bool operator > (Money&);
    bool operator >= (Money&);
    bool operator < (Money&);
    bool operator <= (Money&);
    bool operator == (Money&);
    bool operator != (Money&);
};
