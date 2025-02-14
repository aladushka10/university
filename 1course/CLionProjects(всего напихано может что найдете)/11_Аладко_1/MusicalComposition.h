#ifndef INC_11__1_MUSICALCOMPOSITION_H
#define INC_11__1_MUSICALCOMPOSITION_H
#include "Music.h"
#include <iostream>
#include <string>
using namespace std;

enum MusicGenre{song = 1, opera, simphony, jazz};

inline ostream& operator <<(ostream&, const MusicGenre&);

class MusicComposition: public Music{
protected:
    string titleComposition;
    const MusicGenre genre;
    int yearCreation;
public:
    void printID(std::ostream&) const override;

    MusicComposition(string, MusicGenre, int);
    MusicComposition(const MusicComposition&);

    ~MusicComposition();

    string get_title() const;
    MusicGenre get_genre() const;
    int get_year() const;

    void set_title(string);
    void set_year(int);

    MusicComposition& operator = (const MusicComposition&);
    bool operator ==(const MusicComposition&) const;
    friend ostream& operator << (ostream&, const MusicComposition&);
};
#endif //INC_11__1_MUSICALCOMPOSITION_H
