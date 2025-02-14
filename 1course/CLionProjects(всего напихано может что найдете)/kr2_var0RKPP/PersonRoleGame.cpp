#include "PersonRoleGame.h"

PersonRoleGame::PersonRoleGame(): ID(NextID++), race(human) {
    name = "Harry Potter", condition = normal, abilityToMove = true;
}

PersonRoleGame::PersonRoleGame(string name, PersonCondition state, PersonRace race): ID(NextID++), race(race){
    this->name = name;
    if(state == normal)
        this->abilityToMove = true;
    else
        abilityToMove = false;
}

PersonRoleGame::PersonRoleGame(const PersonRoleGame &p): ID(NextID++), name(p.name),
condition(p.condition), race(p.race), abilityToMove(p.abilityToMove){} //??

string PersonRoleGame::get_name() const {
    return name;
}

PersonCondition PersonRoleGame::get_condition() const {
    return condition;
}

PersonRace PersonRoleGame::get_race() const {
    return race;
}

bool PersonRoleGame::get_abilityToMove() const {
    return abilityToMove;
}

void PersonRoleGame::set_name(const string & name) {
    this->name = name;
}

void PersonRoleGame::set_condition(const PersonCondition & condition) {
    this->condition = condition;
    if (condition == normal)
        abilityToMove = true;
    else
        abilityToMove = false;
}

PersonRoleGame &PersonRoleGame::operator=(const PersonRoleGame &right) {
    if(this == &right)
        return *this;
    name = right.name;
    condition = right.condition;
    //race = right.race;
    abilityToMove = right.abilityToMove;
    return *this;
}

bool PersonRoleGame::operator==(const PersonRoleGame &p) const {
    return (name == p.name && condition == p.condition && race == p.race);
}


ostream &operator<<(ostream &out, const PersonRoleGame &p) {
    out << "Имя: " << p.name << endl;
    out << "Состояние" << p.condition << endl;
    out << "Раса" << p.race << endl;
    out << "Возможность двигаться" << p.abilityToMove << endl;
}









