#pragma once

namespace Math {
    class Vect {
    private:
        float x, y;

    public:
        Vect();
        Vect(const float _x, const float _y);
        ~Vect();

        const float getX() const;
        void setX(const float _x);

        const float getY() const;
        void setY(const float _y);

        float getMagnitude() const;
        Vect normalize() const;

        Vect operator-(const Vect v);
        Vect operator+(Vect v);
        void operator+=(Vect v);
        void operator*=(const float a);
        void operator/=(const float a);
    };

    const Vect operator*(const Vect v, const float a);
}
