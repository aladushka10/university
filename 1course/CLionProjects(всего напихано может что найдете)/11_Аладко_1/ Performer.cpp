#include "Performer.h"


Performer::Performer(string name, MusicGenre genre, int yearCreation, int realCnt, int * concerts) : MusicComposition(name, genre, yearCreation),
    realCnt(realCnt)
{
    this->concerts = new int[realCnt];
    for (int i = 0; i < realCnt; i++)
        this->concerts[i] = concerts[i];
}

Performer::Performer(const Performer & init) : MusicComposition(init.get_title(), init.get_genre(), init.get_year()), realCnt(init.realCnt)
{
    this->concerts = new int[realCnt];
    for (int i = 0; i < realCnt; i++)
        this->concerts[i] = init.concerts[i];
}

Performer::~Performer()
{
    if (realCnt == 1)
        delete concerts;
    if (realCnt > 1)
        delete[] concerts;
}