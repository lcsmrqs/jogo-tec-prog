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

        void operator*=(float a);
        Vect operator*(float a);

        void operator+=(Vect v);
    };
}
