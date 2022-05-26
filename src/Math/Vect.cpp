#include "Vect.h"

using namespace Math;

Vect::Vect(): x(0), y(0) {}

Vect::Vect(const float _x, const float _y): x(_x), y(_y) {}

Vect::~Vect() {}

const float Vect::getX() const {
    return x;
}

void Vect::setX(const float _x) {
    x = _x;
}

const float Vect::getY() const {
    return y;
}

void Vect::setY(const float _y) {
    y = _y;
}

void Vect::operator*=(float a) {
    x *= a;
    y *= a;
}

Vect Vect::operator*(float a) {
    return Vect(x * a, y * a);
}

void Vect::operator+=(Vect v) {
    x += v.x;
    y += v.y;
}
