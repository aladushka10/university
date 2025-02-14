#include "Music.h"

int Music::NextID = 1;

void Music::printID(std::ostream & out) const{
    out << "ID: " <<ID;
}

Music::Music() : ID(NextID++) {}

Music::~Music() {}
