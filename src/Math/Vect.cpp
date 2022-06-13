#include "Vect.h"
#include <cmath>

namespace Math {

    Vect::Vect() : x(0.0f), y(0.0f) {}

    Vect::Vect(const float _x, const float _y) : x(_x), y(_y) {}

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

    float Vect::getMagnitude() const {
        return sqrtf(powf(x, 2.0f) + powf(y, 2.0f));
    }

    Vect Vect::normalize() const {
        Vect normalized(x, y);
        float magnitude = getMagnitude();

        if (magnitude > 0.0f)
            normalized /= magnitude;

        return normalized;
    }

    Vect Vect::operator-(const Vect v) {
        return Vect(x - v.getX(), y - v.getY());
    }

/*Vect Vect::operator*(const float a) {
    return Vect(x * a, y * a);
}*/

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

    const Vect operator*(const Vect v, const float a) {
        return Vect(v.getX() * a, v.getY() * a);
    }
}