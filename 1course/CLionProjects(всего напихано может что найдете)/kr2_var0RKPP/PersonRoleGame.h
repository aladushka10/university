#ifndef KR2_VAR0RKPP_PERSONROLEGAME_H
#define KR2_VAR0RKPP_PERSONROLEGAME_H
#include <iostream>
#include <string>
enum PersonCondition{normal = 1, paralyzed, dead};
enum PersonRace{human = 1, dwarf, elf};
using namespace std;
class PersonRoleGame{
protected:
    const int ID;
    string name;
    PersonCondition condition;
    const PersonRace race;
    bool abilityToMove;
public:
    static int NextID;

    PersonRoleGame();
    PersonRoleGame(string, PersonCondition, PersonRace);
    PersonRoleGame(const PersonRoleGame&);
    virtual ~PersonRoleGame(){};

    string get_name() const;
    PersonCondition get_condition() const;
    PersonRace get_race() const;
    bool get_abilityToMove() const;

    void set_name(const string&);
    void set_condition(const PersonCondition&);

    PersonRoleGame& operator = (const PersonRoleGame&);
    bool operator ==(const PersonRoleGame&) const;
    friend ostream& operator << (ostream&, const PersonRoleGame&);
};
#endif //KR2_VAR0RKPP_PERSONROLEGAME_H
