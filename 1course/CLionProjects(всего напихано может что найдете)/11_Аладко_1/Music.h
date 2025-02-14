#ifndef INC_11__1_MUSIC_H
#define INC_11__1_MUSIC_H
#include <iostream>
class Music{
protected:
    const int ID;
public:
    Music();
    virtual ~Music();

    virtual void printID(std::ostream&) const = 0;
    int static NextID;
};

#endif //INC_11__1_MUSIC_H
