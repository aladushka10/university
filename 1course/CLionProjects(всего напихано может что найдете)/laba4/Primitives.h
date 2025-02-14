#ifndef LABA3RKPP_PRIMITIVES_H
#define LABA3RKPP_PRIMITIVES_H
#include "Component.h"
class Tipper: public Component {
public:
    virtual int getStrength() { return 3; } };
class TrailerTruck: public Component{
public:
    virtual int getStrength() { return 2; } };
class Van: public Component {
public:
    virtual int getStrength() { return 1; } };

#endif //LABA3RKPP_PRIMITIVES_H
