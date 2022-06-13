#include "Floor.h"

using namespace Entities;

Floor::Floor(const Vect pos, const Vect size, const int l) :
Entity(pos)
{
    setSize(size);

    if(l == 1)
        setTexture("floor-grass", true);
    else if(l == 2)
        setTexture("floor-mud", true);
}

Floor::~Floor() {}

void Floor::run(float dt) {}
