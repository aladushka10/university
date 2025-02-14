#include "MagicHero.h"
#include "assert.h"

void MagicHero::checkLimits() {
    if()
}

void MagicHero::deleteArr() {

}

MagicHero::MagicHero(): PersonRoleGame() {
    max_mana = 35, current_mana = 24, cnt_month = 0;
}

MagicHero::MagicHero(string name, PersonCondition state, PersonRace race, unsigned int max_mana,
                     unsigned int current_mana, int * array, int cnt_month): max_mana(max_mana),
                     array(array), cnt_month(cnt_month){
    this->array = new int[this->cnt_month];
    for(int i = 0; i < cnt_month; i++)
       this->array[i] = array[i];
    if(current_mana <= max_mana)
        this->current_mana = current_mana;
    else assert(false);
}

MagicHero::MagicHero(const MagicHero & m): max_mana(m.max_mana), current_mana(m.current_mana),
array(m.array), cnt_month(m.cnt_month){}

MagicHero::~MagicHero() {
if(cnt_month == 1)
    delete array;
if(cnt_month > 1)
    delete[] array;
}

unsigned int MagicHero::get_max_mana() const {
    return max_mana;
}

unsigned int MagicHero::get_current_nama() const {
    return current_mana;
}

int* MagicHero::get_array() const {
    //return nullptr;
}

int MagicHero::get_cnt_month() const {
    return cnt_month;
}

void MagicHero::set_max_mana(const unsigned int &m) {

}


