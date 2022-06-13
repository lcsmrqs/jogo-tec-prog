#pragma once

#include "Level.h"

namespace Levels {
    class Forest : public Level
    {
    public:
        Forest(const int players = 1, const float w = 3500.0);
        ~Forest();

        void init();
        void generateLevel();
        void reset();
        void finish();

        virtual void onKeyPressed(Managers::Key k);
    };
}
