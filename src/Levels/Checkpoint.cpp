#include "Checkpoint.h"

using namespace Levels;

Checkpoint::Checkpoint(const Vect pos, const Vect s) :
position(pos),
size(s)
{}

Checkpoint::~Checkpoint()
{}

Vect Checkpoint::getPosition() const { return position; }

void Checkpoint::setPosition(const Vect pos) { position = pos; }

Vect Checkpoint::getSize() const { return size; }

void Checkpoint::setSize(const Vect s) { size = s; }
