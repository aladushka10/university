#include <iostream>
#include "Person.h"

int main()
{
    Person Adam("Adam", Gender::male);
    Person Eva("Eva", Gender::female);
    Person Arina = *Eva.GiveBirth("Arina", Gender::female, &Adam);
    Person Stepan = *Arina.GiveBirth("Stepan", Gender::male, &Adam);
    Person Genya = *Eva.GiveBirth("Genya", Gender::female, &Stepan);
    Person Jora = *Genya.GiveBirth("Jora", Gender::male);
    Stepan.Print();

    return 0;
}