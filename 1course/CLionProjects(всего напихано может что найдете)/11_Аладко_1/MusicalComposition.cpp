#include "MusicalComposition.h"

MusicComposition::~MusicComposition() {}

void MusicComposition::printID(ostream & out) const {
    out << "Музыкальная композиция " << ID << endl;
}

inline ostream& operator<<(ostream& out, const MusicGenre& genre)
{
    switch (genre)
    {
        case song:
            out << "песня";
            break;
        case opera:
            out << "опера";
            break;
        case simphony:
            out << "симфония";
            break;
        case jazz:
            out << "джаз";
            break;
        default:
            break;
    }
    return out;
}


MusicComposition::MusicComposition(string title, MusicGenre genre, int year): titleComposition(title), genre(genre),
yearCreation(year){}

MusicComposition::MusicComposition(const MusicComposition &m): titleComposition(m.titleComposition),
genre(m.genre), yearCreation(m.yearCreation){}

string MusicComposition::get_title() const {
    return titleComposition;
}

MusicGenre MusicComposition::get_genre() const {
    return  genre;
}

int MusicComposition::get_year() const {
    return yearCreation;
}

void MusicComposition::set_title(string titleComposition) {
    this->titleComposition = titleComposition;
}

void MusicComposition::set_year(int yearCreation) {
    this->yearCreation = yearCreation;
}

MusicComposition &MusicComposition::operator=(const MusicComposition &right) {
    if(this == &right)
        return *this;
    titleComposition = right.titleComposition;
    yearCreation = right.yearCreation;
    return *this;
}

bool MusicComposition::operator==(const MusicComposition &m) const {
    return (titleComposition == m.titleComposition && genre == m.genre && yearCreation == m.yearCreation);
}

ostream &operator<<(ostream & out, const MusicComposition & mus) {
    mus.printID(out);
    out << "Название музыкальной композиции: " << mus.titleComposition << endl;
    out << "Жанр: " << mus.genre << endl;
    out << "Год издания: " << mus.yearCreation << endl;
    return out;
}







