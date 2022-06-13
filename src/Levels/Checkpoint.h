#pragma once

#include "../Math/Vect.h"

using Math::Vect;

namespace Levels {
    class Checkpoint
    {
    private:
        Vect position, size;

    public:
        Checkpoint(const Vect pos = Vect(), const Vect s = Vect());
        ~Checkpoint();

        Vect getPosition() const;
        void setPosition(const Vect pos);

        Vect getSize() const;
        void setSize(const Vect s);
    };
}