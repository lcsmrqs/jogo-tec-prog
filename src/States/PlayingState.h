#pragma once

#include "State.h"

namespace Levels {
    class Level;
}

using Levels::Level;

namespace States {
    class PlayingState : public State
    {
    private:
        Level *level;

    public:
        PlayingState(Level *pl = NULL, StateStack *c = NULL);
        ~PlayingState();

        void setLevel(Level *l);

        void run(float dt);
        void draw();
        void reset();

        virtual void onKeyPressed(Managers::Key k);

        virtual void onKeyReleased(Managers::Key k);
    };
}
