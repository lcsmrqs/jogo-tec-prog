#include "Vect.h"
#include <iostream>
#include <cmath>

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

float Vect::getMagnitude() {
    return sqrt(powf(x, 2) + powf(y, 2));
}

Vect Vect::normalize() {
    Vect normalized(x, y);
    float magnitude = getMagnitude();

    if(magnitude > 0.0f)
        normalized /= magnitude;

    return normalized;
}

Vect Vect::operator-(const Vect v) {
    return Vect(x - v.getX(), y - v.getY());
}

Vect Vect::operator*(const float a) {
    return Vect(x * a, y * a);
}

void Vect::operator+=(Vect v) {
    x += v.x;
    y += v.y;
}

void Vect::operator*=(const float a) {
    x *= a;
    y *= a;
}

void Vect::operator/=(const float a) {
    x /= a;
    y /= a;
}

Vect Vect::operator+(Vect v) {
    return Vect(x + v.getX(), y + v.getY());
}
