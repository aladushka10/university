#ifndef INC_11__1_PERFORMER_H
#define INC_11__1_PERFORMER_H
#include "MusicalComposition.h"

class Performer : public MusicComposition
{
private:
    static const int maxCnt;
    int realCnt;
    int* concerts;
public:
    Performer(string, MusicGenre, int, int, int*);
    Performer(const Performer&);

    ~Performer();

    Performer& operator=(const Performer&);
    friend ostream& operator<<(ostream&, const Performer&);
};


#endif //INC_11__1_PERFORMER_H
