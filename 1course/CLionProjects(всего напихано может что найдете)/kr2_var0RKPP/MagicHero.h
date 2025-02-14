#ifndef KR2_VAR0RKPP_MAGICHERO_H
#define KR2_VAR0RKPP_MAGICHERO_H
#include "PersonRoleGame.h"
#include <iostream>
class MagicHero : public PersonRoleGame{
private:
    unsigned int max_mana;
    unsigned int current_mana;
    int* array;
    int cnt_month;
    void checkLimits();
    void deleteArr();
public:
    MagicHero();
    MagicHero(string, PersonCondition, PersonRace, unsigned int, unsigned int, int*, int);
    MagicHero(const MagicHero&);

    ~MagicHero();

    unsigned int get_max_mana() const;
    unsigned int get_current_nama() const;
    int* get_array() const;
    int get_cnt_month() const;

    void set_max_mana(const unsigned int&);
    void set_current_mana(const unsigned int&);
    void set_array(const int* &);
    void set_cnt_month(const int&);

    MagicHero& operator = (const MagicHero&);
    friend std::ostream& operator << (std::ostream&, const MagicHero&);
};

#endif //KR2_VAR0RKPP_MAGICHERO_H
