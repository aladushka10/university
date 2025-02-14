#ifndef INC_8_MONEY_H
#define INC_8_MONEY_H
#include <iostream>

using namespace std;

class Money
{
public:
    Money() {}
    Money(int pd, int sh, int p, bool hf);
    int getPounds();
    int getShillings();
    int getSign();
    int getPenny();
    long long getPenny2();
    bool getHalf();
    void setPounds(int);
    void setShillings(int);
    void setPenny(int);
    void setSign(int);
    void setHalf(bool);
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
private:
    int pounds = 0;
    int shillings = 0;
    int penny = 0;
    int sign = 1;
    bool half = false;
};

ostream & operator <<(ostream &out, Money&);


#endif //INC_8_MONEY_H
