/*
 * Baseado em:
 *  - playlist do Burda(https://www.youtube.com/channel/UCrNDrGwDXmBErjp0BGqqOUw),
 *  - livro Design Patterns
 *  - https://refactoring.guru/
 */

#pragma once

#include <cstdlib>
#include "../Ent.h"
#include "../Managers/EventListener.h"

using Managers::EventListener;

namespace States {
	class StateStack;

    class State : public Ent, public EventListener
    {
    protected:
        StateStack *context;

    public:
        State(StateStack *c = NULL);
        virtual ~State();

        virtual void run(float dt) = 0;
        virtual void draw() = 0;
        virtual void reset() = 0;

        virtual void onKeyPressed(Managers::Key k) = 0;
        virtual void onKeyReleased(Managers::Key k) = 0;

        void requestStackPush(State *s);
		void requestStackPop();
        void requestResetTop();

        StateStack* getContext();
        void setContext(StateStack *c);

        const bool isOnTop() const;
    };
}
